#include "../include/cub3d.h"

void			my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char *dst;

	dst = (char *)all->global.addr +
	(y * all->global.line_length + x * (all->global.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void init_data(t_all *all)
{
	all->pos.pos_x = 12;
	all->pos.pos_y = 5;
  	all->pos.dir_y = 0;
	all->pos.dir_x = -1;
	all->pos.plane_x = 0;
	all->pos.plane_y = 0.66;
	all->pos.move_speed = 0.05;
	all->pos.rot_speed = 0.05;
}

void verLine(t_all *all, int color, int x)
{
	int	y;
	y = all->pos.draw_start;
	while (y <= all->pos.draw_end)
	{
		my_mlx_pixel_put(all, x, y, color);
		y++;
	}
}
void get_next_step(t_all *all)
{
    if (all->pos.ray_x < 0)
	{
		all->pos.step_x = -1;
		all->pos.side_dist_x = (all->pos.pos_x - all->pos.map_x) * all->pos.delta_dist_x;
	}
	else
	{
		all->pos.step_x = 1;
		all->pos.side_dist_x = (all->pos.map_x + 1.0 - all->pos.pos_x) * all->pos.delta_dist_x;
	}
	if (all->pos.ray_y < 0)
	{
		all->pos.step_y = -1;
		all->pos.side_dist_y = (all->pos.pos_y - all->pos.map_y) * all->pos.delta_dist_y;
	}
	else
	{
		all->pos.step_y = 1;
		all->pos.side_dist_y = (all->pos.map_y + 1.0 - all->pos.pos_y) * all->pos.delta_dist_y;
	}
}

void init_ray(t_all *all, int x)
{
    all->pos.camera_x = 2 * x / (double)WIDTH - 1;
	all->pos.ray_x = all->pos.dir_x + all->pos.plane_x * all->pos.camera_x;
	all->pos.ray_y = all->pos.dir_y + all->pos.plane_y * all->pos.camera_x;
	all->pos.map_x = (int)all->pos.pos_x;
	all->pos.map_y = (int)all->pos.pos_y;
	all->pos.hit = 0;
	all->pos.delta_dist_x = fabs(1 / all->pos.ray_x);
	all->pos.delta_dist_y = fabs(1 / all->pos.ray_y);
    get_next_step(all);
}

char elem_at(int x, int y, t_all *all)
{
    return(all->global.nums[x][y]);
}
void dda(t_all *all)
{ 
    while (all->pos.hit == 0)
    {
        if (all->pos.side_dist_x < all->pos.side_dist_y)
			{
				all->pos.side_dist_x += all->pos.delta_dist_x;
				all->pos.map_x += all->pos.step_x;
				all->pos.side = 0;
			}
			else
			{
				all->pos.side_dist_y += all->pos.delta_dist_y;
				all->pos.map_y += all->pos.step_y;
				all->pos.side = 1;
			}
			
			if (all->global.nums[all->pos.map_x][all->pos.map_y] > '0')
				all->pos.hit = 1;
    }
}

void get_dist(t_all *all)
{
    if (all->pos.side == 0)
		all->pos.perp_wall_dist = (all->pos.map_x - all->pos.pos_x + (1 - all->pos.step_x) / 2)
			/ all->pos.ray_x;
	else
		all->pos.perp_wall_dist = (all->pos.map_y - all->pos.pos_y + (1 - all->pos.step_y) / 2)
			/ all->pos.ray_y;
	all->pos.line_h = (int)(HEIGHT / all->pos.perp_wall_dist);
}

void draw(t_all *all)
{
    all->pos.draw_start = -all->pos.line_h / 2 + HEIGHT / 2;
    if (all->pos.draw_start < 0)
        all->pos.draw_start = 0;
    all->pos.draw_end = all->pos.line_h / 2 + HEIGHT / 2;
    if (all->pos.draw_end >= HEIGHT)
        all->pos.draw_end = HEIGHT - 1;
	all->pos.tex_num = (int)all->global.nums[all->pos.map_x][all->pos.map_y];
}

void color(t_all *all)
{
    int color;
    if (all->global.nums[all->pos.map_x][all->pos.map_y] == '1')
        color = 0xFF0000;
    else if (all->global.nums[all->pos.map_x][all->pos.map_y] == '0')
        color = 0x00FF00;
	else if (all->global.nums[all->pos.map_x][all->pos.map_y] == '3')
		color = 0x0000FF;
	else if (all->global.nums[all->pos.map_x][all->pos.map_y] == '4')
		color = 0xFFFFFF;
	else
		color = 0xFFFF00;
    if (all->pos.side == 1)
        color = color / 2;
    //verLine(all, color, x);
}

void floror(t_all *all, int x)
{
	int y = 0;
	y = all->pos.draw_end;
	y--;
	while (y < HEIGHT)
	{
		my_mlx_pixel_put(all, x, y, all->global.rgbF);
		y++;
	}
}

void texturing(t_all *all)
{
	if (all->pos.side == 0)
	{
		all->pos.wall_x = all->pos.pos_y + all->pos.perp_wall_dist * all->pos.ray_y;
	}
	else
		all->pos.wall_x = all->pos.pos_x + all->pos.perp_wall_dist * all->pos.ray_x;
	all->pos.wall_x -= floor((all->pos.wall_x));
	all->pos.tex_x = (int)(all->pos.wall_x * (double)all->pos.tex_width);
	if (all->pos.side == 0 && all->pos.ray_x > 0)
		all->pos.tex_x = all->pos.tex_width - all->pos.tex_x -1;
	if (all->pos.side == 1 && all->pos.ray_y < 0)
		all->pos.tex_x = all->pos.tex_width - all->pos.tex_x -1;
	all->pos.step = 1.0 * all->pos.tex_height / all->pos.line_h;
	all->pos.tex_pos = (all->pos.draw_start - HEIGHT / 2 + all->pos.line_h / 2) * all->pos.step;
}

void printing(t_all *all, int x, int y)
{
	y = all->pos.draw_start;
	ft_get_textures(all);
	while(y < all->pos.draw_end)
	{
		all->pos.tex_y = (int)all->pos.tex_pos;
		all->pos.tex_pos += all->pos.step;
		all->global.color = all->pos.buffer[all->pos.tex_width * all->pos.tex_y + all->pos.tex_x];
		my_mlx_pixel_put(all, x, y, all->global.color);
		y++;
	}
}

void ceiling(t_all *all, int x)
{
	int y = 0;
	while (y < all->pos.draw_start)
	{
		my_mlx_pixel_put(all, x, y, all->global.rgbC);
		y++;
	}
}

void put_pistolon(t_all *all)
{
	all->image.image = mlx_new_image(all->global.mlx, all->image.x, all->image.y);
	all->image.pointer = mlx_xpm_file_to_image(all->image.image, "assets/sprites/pistol.xpm", &all->image.x, &all->image.y);
	all->image.pixels  = mlx_get_data_addr(all->image.image, &all->image.bits_per_pixel, &all->image.line_size, &all->image.endian);
	mlx_put_image_to_window(all->global.mlx, all->global.win, all->image.pointer, 825, 870);

	// all->image.image = mlx_new_image(all->global.mlx, all->image.x, all->image.y);
	// all->image.pointer = mlx_xpm_file_to_image(all->image.image, "assets/sprites/crosshair.xpm", &all->image.x, &all->image.y);
	// all->image.pixels  = mlx_get_data_addr(all->image.image, &all->image.bits_per_pixel, &all->image.line_size, &all->image.endian);
	// //mlx_put_image_to_window(all->global.mlx, all->global.win, all->image.pointer, 930, 513);
}

void	calc(t_all *all)
{
    int x;
	int y;

    x = 0;
	y = 0;
	while (x < WIDTH)
	{
        init_ray(all, x);
		dda(all);
        get_dist(all);
        draw(all);
		texturing(all);
        color(all);
		printing(all, x, y);
		ceiling(all, x);
		floror(all, x);
		x++;
	}
	
	mlx_put_image_to_window(all->global.mlx, all->global.win,
	all->global.img, 0, 0);
	//put_pistolon(all);
	// mlx_put_image_to_window(all->global.mlx, all->global.win,
	// all->image.image, 0, 0);
	key_move(all);
	
}

int	main_loop(t_all *all)
{
	calc(all);
	return (0);
}
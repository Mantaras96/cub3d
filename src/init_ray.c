#include "../include/cub3d.h"


void init_data(t_all *all)
{
	all->pos.pos_x = 12;
	all->pos.pos_y = 5;
  	all->pos.dir_y = 0;
	all->pos.dir_x = -1;
	all->pos.plane_x = 0;
	all->pos.plane_y = 0.66;
}

void verLine(t_all *all, int color, int x)
{
	int	y;

	y = all->pos.draw_start;
	while (y <= all->pos.draw_end)
	{
		mlx_pixel_put(all->global.mlx, all->global.win, x, y, color);
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
}

void color(t_all *all, int x)
{
    int color;
    if (all->global.nums[all->pos.map_y][all->pos.map_x] == '1')
        color = 0xFF0000;
    else if (all->global.nums[all->pos.map_y][all->pos.map_x] == '0')
        color = 0x00FF00;
    if (all->pos.side == 1)
        color = color / 2;
    verLine(all, color, x);
}


void	calc(t_all *all)
{
    int x;

    x = 0;
	while (x < WIDTH)
	{
        init_ray(all, x);
		dda(all);
        get_dist(all);
        draw(all);
        color(all, x);
		x++;
	}
}

int	main_loop(t_all *all)
{
	calc(all);
	return (0);
}
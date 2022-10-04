#include "../include/cub3d.h"


void init_data(t_all *all)
{
  	all->pos.dir_y = 0;
	all->pos.dir_x = 0;
	all->pos.plane_y = 0;
	all->pos.dir_y = -1;
	all->pos.plane_x = 0.66;
}

void verLine(t_all *all, int color, int x)
{
	int	y;

	y = all->ray->draw_start;
	while (y <= all->ray->draw_end)
	{
		mlx_pixel_put(all->global->mlx, all->global->win, x, y, color);
		y++;
	}
}
void get_next_step(t_ray *ray, t_pos pos)
{
    if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (pos.pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - pos.pos_x) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (pos.pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - pos.pos_y) * ray->delta_dist_y;
	}
}

void init_ray(t_ray *ray, t_pos pos, int x)
{
    ray->camera_x = 2 * x / (double)WIDTH - 1;
	ray->dir_x = pos.dir_x + pos.plane_x * ray->camera_x;
	ray->dir_y = pos.dir_y + pos.plane_y * ray->camera_x;
	ray->map_x = (int)pos.pos_x;
	ray->map_y = (int)pos.pos_y;
	ray->hit = 0;
    if (ray->dir_y == 0)
		ray->delta_dist_x = 0;
	else if (ray->dir_x == 0)
		ray->delta_dist_x = 1;
	else
		ray->delta_dist_x = fabs(1 / ray->dir_x);
	if (ray->dir_x == 0)
		ray->delta_dist_y = 0;
	else if (ray->dir_y == 0)
		ray->delta_dist_y = 1;
	else
		ray->delta_dist_y = fabs(1 / ray->dir_y);
    get_next_step(ray, pos);
}

char elem_at(int x, int y, t_global *global)
{
    return(global->nums[x][y]);
}
void dda(t_ray *ray, t_global *global)
{
    printf("%d\n", ray->map_y);
    global =NULL;
    while (ray->hit == 0)
    {
        if (ray->side_dist_x < ray->side_dist_y)
			{
				ray->side_dist_x += ray->delta_dist_x;
				ray->map_x += ray->step_x;
				ray->side = 0;
			}
			else
			{
				ray->side_dist_y += ray->delta_dist_y;
				ray->map_y += ray->step_y;
				ray->side = 1;
			}
			// if (elem_at(ray->map_x, ray->map_y, global) == '1')
			//     ray->hit = 1;
    }
}

void get_dist(t_ray *ray, t_pos pos)
{
    if (ray->side == 0 || ray->side == 1)
		ray->perp_wall_dist = (ray->map_x - pos.pos_x + (1 - ray->step_x) / 2)
			/ ray->dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - pos.pos_y + (1 - ray->step_y) / 2)
			/ ray->dir_y;
	ray->line_h = (int)HEIGHT / ray->perp_wall_dist;
}

void draw(t_ray *ray)
{
    ray->draw_start = -ray->line_h / 2 + HEIGHT / 2;
    if (ray->draw_start)
        ray->draw_start = 0;
    ray->draw_end = ray->line_h / 2 + HEIGHT / 2;
    if (ray->draw_end >= HEIGHT)
        ray->draw_end = 1;
}

void color(t_all *all, int x)
{
    int color;
    if (all->global->nums[all->ray->map_y][all->ray->map_x] == '0')
        color = 0xFF0000;
    else if (all->global->nums[all->ray->map_y][all->ray->map_x] == '1')
        color = 0x00FF00;
    if (all->ray->side == 1)
        color = color / 2;
    verLine(all, color, x);
}


void	calc(t_all *all)
{
    int x;

    x = -1;
	while (++x < WIDTH)
	{
        init_ray(all->ray, all->pos, x);
		dda(all->ray, all->global);
        get_dist(all->ray, all->pos);
        draw(all->ray);
        color(all, x);
	}
}

int	main_loop(t_all *all)
{
	calc(all);
	return (0);
}
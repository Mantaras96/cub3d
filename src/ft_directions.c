#include "../include/cub3d.h"


void ft_directions(t_all *all)
{
    all->corde.direction = 'E';
    all->corde.x = 12;
    all->corde.y = 5;

    if (all->corde.direction == 'N')
    {
        all->pos.pos_x = all->corde.x;
	    all->pos.pos_y = all->corde.y;
  	    all->pos.dir_y = 0;
	    all->pos.dir_x = 1;
	    all->pos.plane_x = 0;
	    all->pos.plane_y = -0.66;
    }
    if (all->corde.direction == 'S')
    {
        all->pos.pos_x = all->corde.x;
	    all->pos.pos_y = all->corde.y;
  	    all->pos.dir_y = 0;
	    all->pos.dir_x = -1;
	    all->pos.plane_x = 0;
	    all->pos.plane_y = 0.66;
    }
    if (all->corde.direction == 'W')
    {
        all->pos.pos_x = all->corde.x;
	    all->pos.pos_y = all->corde.y;
  	    all->pos.dir_y = 1;
	    all->pos.dir_x = 0;
	    all->pos.plane_x = 0.66;
	    all->pos.plane_y = 0;
    }
    if (all->corde.direction == 'E')
    {
        all->pos.pos_x = all->corde.x;
	    all->pos.pos_y = all->corde.y;
  	    all->pos.dir_y = -1;
	    all->pos.dir_x = 0;
	    all->pos.plane_x = -0.66;
	    all->pos.plane_y = 0;
    }
}
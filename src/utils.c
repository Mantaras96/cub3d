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
	// all->pos.pos_x = 12;
	// all->pos.pos_y = 5;
  	// all->pos.dir_y = 0;
	// all->pos.dir_x = -1;
	// all->pos.plane_x = 0;
	// all->pos.plane_y = 0.66;
	all->pos.move_speed = 0.04;
	all->pos.rot_speed = 0.04;
	all->pos.buffer = NULL;
	all->pos.tex_num = 0;
	all->pos.tex_x = 0;
	all->pos.step_x = 0;
	all->pos.step_y = 0;
	all->pos.tex_y = 0;
	all->pos.tex_width = 0;
	all->pos.tex_height = 0;
	all->corde.a = 0;
	all->corde.left = 0;
	all->corde.right = 0;
}

int	close_event(void)
{
	exit (0);
	return (0);
}

int	ft_matrix_len(char **matrix)
{
	int	i;

	i = 0;
	while (matrix && matrix[i])
		i++;
	return (i);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	if (!str1)
		return (1);
	while (*str1)
	{
		if (*str1 != *str2)
			break ;
		str1++;
		str2++;
	}
	return (*(const unsigned char *) str1 - *(const unsigned char *) str2);
}
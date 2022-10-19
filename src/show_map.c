/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 22:34:14 by albertmanta       #+#    #+#             */
/*   Updated: 2022/10/19 19:32:09 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	*transform_img(void *mlx, char *image)
{
	void	*img;
	int		img_size;

	img = mlx_xpm_file_to_image(mlx, image,
			&img_size, &img_size);
	return (img);
}

void	*get_sprite_char(t_global *global)
{
	if (global->character.direction == 'W')
		return (transform_img(global->mlx, "./assets/sprites/char_u.xpm"));
	else if (global->character.direction == 'S')
		return (transform_img(global->mlx, "./assets/sprites/char_d.xpm"));
	else if (global->character.direction == 'A')
		return (transform_img(global->mlx, "./assets/sprites/char_l.xpm"));
	else if (global->character.direction == 'D')
		return (transform_img(global->mlx, "./assets/sprites/char_r.xpm"));
	return (NULL);
}

void	*complete_map_img(t_global *global, int i, int j)
{
	if (global->map[i][j] == '1')
		return (transform_img(global->mlx, "./assets/sprites/wall.xpm"));
	else if (global->map[i][j] == '0')
		return (transform_img(global->mlx, "./assets/sprites/water.xpm"));
	else if (global->map[i][j] == 'E')
		return (transform_img(global->mlx, "./assets/sprites/escape.xpm"));
	else if (global->map[i][j] == 'P')
	{
		global->character.x = j;
		global->character.y = i;
		return (get_sprite_char(global));
	}
	return (NULL);
}

void	show_map(t_global *global)
{
	int		count;
	t_corde	c;
	t_corde	coord;

	c.x = 0;
	count = 0;
	coord.y = 0;
	while (global->map[c.x])
	{
		c.y = 0;
		coord.x = 0;
		while (global->map[c.x][c.y] != '\n' && global->map[c.x][c.y])
		{
			global->img[count] = complete_map_img(global, c.x, c.y);
			if (global->img[count] == NULL)
				exit (0);
			mlx_put_image_to_window(global->mlx, global->win,
				global->img[count++], coord.x, coord.y);
			coord.x += SIZE_TEXTURE;
			c.y++;
		}
		coord.y += SIZE_TEXTURE;
		c.x++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:20:39 by amantara          #+#    #+#             */
/*   Updated: 2022/10/19 19:20:49 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_texture(t_all *all)
{
	all->text_norte.tex_norte = mlx_xpm_file_to_image(all->global.mlx,
			all->global.path_textures[0], &all->text_norte.tex_width,
			&all->text_norte.tex_height);
	all->text_sud.tex_sud = mlx_xpm_file_to_image(all->global.mlx,
			all->global.path_textures[1], &all->text_sud.tex_width,
			&all->text_sud.tex_height);
	all->text_oeste.tex_oeste = mlx_xpm_file_to_image(all->global.mlx,
			all->global.path_textures[2], &all->text_oeste.tex_width,
			&all->text_oeste.tex_height);
	all->text_este.tex_este = mlx_xpm_file_to_image(all->global.mlx,
			all->global.path_textures[3], &all->text_este.tex_width,
			&all->text_este.tex_height);
}

void	ft_get_text2(t_all *all)
{
	if (all->pos.side == 1 && all->pos.step_y == 1)
	{
		all->pos.tex_width = all->text_este.tex_width;
		all->pos.tex_height = all->text_este.tex_height;
		all->pos.textura = all->text_este.tex_este;
		all->pos.buffer = (unsigned int *)mlx_get_data_addr(all->pos.textura,
				&all->text_este.bits_per_pixel, &all->text_este.line_lenght,
				&all->text_este.endian);
	}
	if (all->pos.side == 1 && all->pos.step_y == -1)
	{
		all->pos.tex_width = all->text_oeste.tex_width;
		all->pos.tex_height = all->text_oeste.tex_height;
		all->pos.textura = all->text_oeste.tex_oeste;
		all->pos.buffer = (unsigned int *)mlx_get_data_addr(all->pos.textura,
				&all->text_oeste.bits_per_pixel,
				&all->text_oeste.line_lenght,
				&all->text_oeste.endian);
	}
}

void	ft_get_textures(t_all *all)
{
	if (all->pos.side == 0 && all->pos.step_x == -1)
	{
		all->pos.tex_width = all->text_norte.tex_width;
		all->pos.tex_height = all->text_norte.tex_height;
		all->pos.textura = all->text_norte.tex_norte;
		all->pos.buffer = (unsigned int *)mlx_get_data_addr(all->pos.textura,
				&all->text_norte.bits_per_pixel, &all->text_norte.line_lenght,
				&all->text_norte.endian);
	}
	if (all->pos.side == 0 && all->pos.step_x == 1)
	{
		all->pos.tex_width = all->text_sud.tex_width;
		all->pos.tex_height = all->text_sud.tex_height;
		all->pos.textura = all->text_sud.tex_sud;
		all->pos.buffer = (unsigned int *)mlx_get_data_addr(all->pos.textura,
				&all->text_sud.bits_per_pixel, &all->text_sud.line_lenght,
				&all->text_sud.endian);
	}
	ft_get_text2(all);
}

int	access_textures(char *filename, t_global *global, int i)
{
	int		fd;
	char	**arr;

	arr = ft_split(filename, '\n');
	fd = open(arr[0], R_OK);
	if (fd == -1)
	{
		return (1);
		close(fd);
		free_matrix(&arr);
	}
	while (i < global->lines_textures)
	{
		global->path_textures[i] = ft_strdup(arr[0]);
		i++;
	}
	close(fd);
	free_matrix(&arr);
	return (0);
}

int	validate_textures(t_global *global, int i, char **arr)
{
	while (global->textures[i])
	{
		arr = ft_split(global->textures[i], ' ');
		if (!ft_strcmp(arr[0], "NO") || !ft_strcmp(arr[0], "SO")
			|| !ft_strcmp(arr[0], "WE") || !ft_strcmp(arr[0], "EA"))
		{
			if (access_textures(arr[1], global, i))
			{
				free_matrix(&arr);
				show_error_msg(1, "Error ruta de las texturas\n");
				break ;
			}
			free_matrix(&arr);
		}
		else
		{
			free_matrix(&arr);
			show_error_msg(1, "Identificador de las texturas erroneo.\n");
			break ;
		}
		free_matrix(&arr);
		i++;
	}
	return (0);
}

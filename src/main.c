/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 23:22:17 by albertmanta       #+#    #+#             */
/*   Updated: 2022/09/30 16:49:39 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	close_event(void)
{
	exit (0);
	return (0);
}

void	set_mlx_windows_and_pistolon(t_all *all)
{
	
	all->global.mlx = mlx_init();
	all->global.win = mlx_new_window(all->global.mlx,
			WIDTH, HEIGHT, "cub3d");
			

	// all->image.image = mlx_new_image(all->global.mlx, all->image.x, all->image.y);
	// all->image.pointer = mlx_xpm_file_to_image(all->image.image, "assets/sprites/pistol.xpm", &all->image.x, &all->image.y);
	// all->image.pixels  = mlx_get_data_addr(all->image.image, &all->image.bits_per_pixel, &all->image.line_size, &all->image.endian);
	// mlx_put_image_to_window(all->global.mlx, all->global.win, all->image.pointer, 825, 870);

	// all->image.image = mlx_new_image(all->global.mlx, all->image.x, all->image.y);
	// all->image.pointer = mlx_xpm_file_to_image(all->image.image, "assets/sprites/crosshair.xpm", &all->image.x, &all->image.y);
	// all->image.pixels  = mlx_get_data_addr(all->image.image, &all->image.bits_per_pixel, &all->image.line_size, &all->image.endian);
	// mlx_put_image_to_window(all->global.mlx, all->global.win, all->image.pointer, 930, 513);
}
int count_file_lines(t_global *global, int i)
{
	while(global->map[i])
	{
		if(global->map[i][0] == '\n')
		{
			break ;
		}
		i++;
	}
	return(i);
}

int count_empty_lines(t_global *global, int i, int count)
{
	if (global->map[i][0] == '\n'){
		while(global->map[i])
		{
			if(global->map[i][0] == '\n')
			{
				i++;
				count++;
			}
			else 
				break ;
		}
	}
	return (count);
}

int count_lines(t_global *global)
{
	int i;
	i = 0;
	global->lines_textures = count_file_lines(global, i);
	global->empty_line = count_empty_lines(global, global->lines_textures, 0);
	i = count_file_lines(global, global->empty_line + global->lines_textures);
	global->lines_colors = i - global->empty_line - global->lines_textures;
	global->empty_line_2 = count_empty_lines(global, i, 0);
	i = count_file_lines(global, global->empty_line_2 + i);
	global->lines_maps = i - (global->lines_textures + global->lines_colors + global->empty_line + global->empty_line_2);
	if (global->lines_textures < 4 || global->lines_textures > 4)
		return (0);
	if (global->lines_colors < 2 || global->lines_colors > 2)
		return (0);
	 return(1);
}

int	main(int argc, char **argv)
{
	t_all all;

	if (argc == 2)
	{
		validate_and_read_map(argv[1], &all);
		if(!count_lines(&all.global))
			show_error_msg(1, "Error numero de texturas\n");
		if(!split_map(&all.global))
			return (0);
		validate_textures(&all.global);
		validate_colors(&all.global); //falta guardar los colores correctamente
		
		init_data(&all);
		//validate_map(&global);

		//set_mlx_windows_and_pistolon(&all);
		all.global.mlx = mlx_init();
		all.global.win = mlx_new_window(all.global.mlx,
			WIDTH, HEIGHT, "cub3d");


		all.global.img = mlx_new_image(all.global.mlx, WIDTH,
		HEIGHT);
		all.global.addr = mlx_get_data_addr(all.global.img,
		&all.global.bits_per_pixel, &all.global.line_length, &all.global.endian);
		ft_texture(&all);
		all.corde.a = 0;
		all.corde.left = 0;
		all.corde.right = 0;
		mlx_hook(all.global.win, 02, (0L << 0), mover, &all);
		mlx_hook(all.global.win, 03, (0L << 0), release, &all);
		mlx_hook(all.global.win, 17, 0, close_event, &all);
		mlx_loop_hook(all.global.mlx, main_loop, &all);
		mlx_loop(all.global.mlx);
	}
	else
	{
		show_error_msg(1, "Error numero de parametro incorrecto");
		return (0);
	}
	return (0);
}



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 23:22:17 by albertmanta       #+#    #+#             */
/*   Updated: 2022/09/23 20:35:52 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	close_event(void)
{
	exit (0);
	return (0);
}

void	*select_img(t_global *vars, char *image)
{
	void	*img;
	int		img_size;

	img = mlx_xpm_file_to_image(vars->mlx, image,
			&img_size, &img_size);
	return (img);
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

void count_lines(t_global *global)
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
}

int	main(int argc, char **argv)
{
	t_global	global;

	if (argc == 2)
	{
<<<<<<< HEAD
		//Teo: printar error y salir cuando hayan mas de las lineas que toca. :)
		global.map = validate_and_read_map(argv[1]);
		count_lines(&global);
		split_map(&global);
		validate_textures(&global);
=======
		validate_and_read_map(argv[1], &global);
		// count_lines(&global);
		// // Read map mock 
		validate_map(&global);
		// //split_map(&global);
		// valid_textures(&global);
>>>>>>> 740a64bdda67c7788998955fd2b8c5e8d6a99bb5
		// validate_letters_map(&global);
		// // global.img = ft_calloc(sizeof(void *),
		// // 		((global.width - 1) * (global.height)) + 1);
		// if (global.img == NULL)
		// 	return (0);
		// set_mlx_and_window(&global);
		// mlx_hook(global.win, 2, 0, mover, &global);
		// mlx_hook(global.win, 17, 0, close_event, &global);
		// mlx_loop(global.mlx);
	}
	else
	{
		show_error_msg("Error numero de parametro incorrecto");
		return (0);
	}
	return (0);
}

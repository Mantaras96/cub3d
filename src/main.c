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

void	set_mlx_and_window(t_global *global)
{
	global->mlx = mlx_init();
	global->win = mlx_new_window(global->mlx,
			1920, 1080, "cub3d");
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
	t_global	global;

	if (argc == 2)
	{
		validate_and_read_map(argv[1], &global);
		if(!count_lines(&global))
			show_error_msg("Error numero de texturas\n");
		if(!split_map(&global))
			return (0);
		validate_textures(&global);
		validate_colors(&global);
		set_mlx_and_window(&global);
		mlx_hook(global.win, 2, 0, mover, &global);
		mlx_hook(global.win, 17, 0, close_event, &global);
		mlx_loop(global.mlx);
	}
	else
	{
		show_error_msg("Error numero de parametro incorrecto");
		return (0);
	}
	return (0);
}

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

void count_lines(t_global *global)
{
	int i;
	int j; 
	i = 0;
	j= 0;
	int count;
	count = 0;
	while(global->map[i])
	{
		if(global->map[i][0] == '\n')
		{
			break ;
		}
		i++;
	}
	global->lines_textures = i;
	j = i;
	if (global->map[j][0] == '\n'){
		while(global->map[j])
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
	
	printf("%d\n", count);
	printf("%d\n", global->lines_textures);
}

void valid_textures(t_global *global)
{
	int i;
	i = 0;
	global->textures = malloc(sizeof(char *) * (5));
	global->textures[4] = NULL;
	while (global->map[i])
	{
		
		if(global->map[i][0] == '\n')
			break ;

		global->textures[i] = ft_strdup(global->map[i]);
		i++;
	}

	i = 0;
	while(global->textures[i])
	{
		printf("%s", global->textures[i]);
		i++;
	}
}


int	main(int argc, char **argv)
{
	t_global	global;

	if (argc == 2)
	{
		validate_and_read_map(argv[1], &global);
		// count_lines(&global);
		// // Read map mock 
		validate_map(&global);
		// //split_map(&global);
		// valid_textures(&global);
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

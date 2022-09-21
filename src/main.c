/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 23:22:17 by albertmanta       #+#    #+#             */
/*   Updated: 2022/09/21 19:43:29 by amantara         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_global	global;

	if (argc == 2)
	{
		global.map = validate_and_read_map(argv[1]);
		split_map(&global);
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

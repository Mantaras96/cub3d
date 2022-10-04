/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mover.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:17:11 by amantara          #+#    #+#             */
/*   Updated: 2022/09/21 19:45:59 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	get_direction(int keycode)
{
	if (keycode == 13)
		return ('W');
	else if (keycode == 0)
		return ('A');
	else if (keycode == 1)
		return ('S');
	else if (keycode == 2)
		return ('D');
	return ('0');
}

int	can_move(t_global *global)
{
	char	object;

	object = ' ';
	if (global->character.direction == 'W')
		object = global->map[global->character.y - 1][global->character.x];
	else if (global->character.direction == 'A')
		object = global->map[global->character.y][global->character.x - 1];
	else if (global->character.direction == 'S')
		object = global->map[global->character.y + 1][global->character.x];
	else if (global->character.direction == 'D')
		object = global->map[global->character.y][global->character.x + 1];
	if (object == '1')
		return (0);
	else if (object == 'E')
		return (2);
	return (1);
}

void	move_main_char(t_global *global)
{
	ft_putstr_fd("Movimientos: ", 1);
	//ft_putnbr_fd(++global->movements, 1);
	ft_putchar_fd('\n', 1);
	global->map[global->character.y][global->character.x] = '0';
	if (global->character.direction == 'W')
		global->character.y--;
	else if (global->character.direction == 'A')
		global->character.x--;
	else if (global->character.direction == 'S')
		global->character.y++;
	else if (global->character.direction == 'D')
		global->character.x++;
	global->map[global->character.y][global->character.x] = 'P';
}

void	free_matrix(char ***matrix)
{
	int	i;

	i = 0;
	while (matrix && matrix[0] && matrix[0][i])
	{
		free (matrix[0][i]);
		i++;
	}
	if (matrix)
	{
		free (matrix[0]);
		*matrix = NULL;
	}
}

void free_all(t_global *global)
{
	free_matrix(&global->textures);
	free_matrix(&global->colors);
	//free_matrix(&global->nums);
	free_matrix(&global->map);
	free(global);
}

int	mover(int keycode, t_global *global)
{	
	if (keycode == 53)
	{
		mlx_destroy_window(global->mlx, global->win);
		exit(0);
	}
	return (0);
}

void	clean_img(t_global *global)
{
	int	i;

	i = 0;
	while (global->img[i])
	{
		mlx_destroy_image(global->mlx, global->img[i]);
		i++;
	}
}

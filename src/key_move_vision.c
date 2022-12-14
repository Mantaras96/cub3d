/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move_vision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:57:57 by amantara          #+#    #+#             */
/*   Updated: 2022/10/19 19:57:59 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	move_right_vision(t_all *all)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = all->pos.dir_x;
	all->pos.dir_x = all->pos.dir_x * cos(-all->pos.rot_speed)
		- all->pos.dir_y * sin(-all->pos.rot_speed);
	all->pos.dir_y = old_dir_x * sin(-all->pos.rot_speed)
		+ all->pos.dir_y * cos(-all->pos.rot_speed);
	old_plane_x = all->pos.plane_x;
	all->pos.plane_x = all->pos.plane_x * cos(-all->pos.rot_speed)
		- all->pos.plane_y * sin(-all->pos.rot_speed);
	all->pos.plane_y = old_plane_x * sin(-all->pos.rot_speed)
		+ all->pos.plane_y * cos(-all->pos.rot_speed);
}

void	move_left_vision(t_all *all)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = all->pos.dir_x;
	all->pos.dir_x = all->pos.dir_x * cos(all->pos.rot_speed)
		- all->pos.dir_y * sin(all->pos.rot_speed);
	all->pos.dir_y = old_dir_x * sin(all->pos.rot_speed)
		+ all->pos.dir_y * cos(all->pos.rot_speed);
	old_plane_x = all->pos.plane_x;
	all->pos.plane_x = all->pos.plane_x * cos(all->pos.rot_speed)
		- all->pos.plane_y * sin(all->pos.rot_speed);
	all->pos.plane_y = old_plane_x * sin(all->pos.rot_speed)
		+ all->pos.plane_y * cos(all->pos.rot_speed);
}

void	check_col(t_all *all, int i, int j)
{
	while (all->global.colors[i])
	{
		j = 0;
		while (all->global.colors[i][j])
		{
			if (all->global.colors[i][j] == 'C')
				all->global.count_c++;
			if (all->global.colors[i][j] == 'F')
				all->global.count_f++;
			j++;
		}
		i++;
	}
	if (all->global.count_f > 1 || all->global.count_c > 1)
		show_error_msg(3, "Err");
}

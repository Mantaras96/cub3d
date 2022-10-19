/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_directions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:08:35 by amantara          #+#    #+#             */
/*   Updated: 2022/10/19 20:13:28 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_directions_n(t_all *all)
{
	all->pos.pos_x = all->corde.x;
	all->pos.pos_y = all->corde.y;
	all->pos.dir_y = 0;
	all->pos.dir_x = 1;
	all->pos.plane_x = 0;
	all->pos.plane_y = -0.66;
}

void	ft_directions_s(t_all *all)
{
	all->pos.pos_x = all->corde.x;
	all->pos.pos_y = all->corde.y;
	all->pos.dir_y = 0;
	all->pos.dir_x = -1;
	all->pos.plane_x = 0;
	all->pos.plane_y = 0.66;
}

void	ft_directions_w(t_all *all)
{
	all->pos.pos_x = all->corde.x;
	all->pos.pos_y = all->corde.y;
	all->pos.dir_y = 1;
	all->pos.dir_x = 0;
	all->pos.plane_x = 0.66;
	all->pos.plane_y = 0;
}

void	ft_directions_e(t_all *all)
{
	all->pos.pos_x = all->corde.x;
	all->pos.pos_y = all->corde.y;
	all->pos.dir_y = -1;
	all->pos.dir_x = 0;
	all->pos.plane_x = -0.66;
	all->pos.plane_y = 0;
}

void	ft_directions(t_all *all)
{
	all->corde.direction = 'E';
	all->corde.x = 12;
	all->corde.y = 5;
	if (all->corde.direction == 'N')
		ft_directions_n(all);
	if (all->corde.direction == 'S')
		ft_directions_s(all);
	if (all->corde.direction == 'W')
		ft_directions_w(all);
	if (all->corde.direction == 'E')
		ft_directions_e(all);
}

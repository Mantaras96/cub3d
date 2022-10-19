/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:30:25 by amantara          #+#    #+#             */
/*   Updated: 2022/10/19 19:30:34 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	malloc_maps(t_global *global)
{
	global->textures = malloc(sizeof(char *) * (global->lines_textures + 1));
	global->textures[global->lines_textures] = NULL;
	global->colors = malloc(sizeof(char *) * (global->lines_colors + 1));
	global->colors[global->lines_colors] = NULL;
	global->nums = malloc(sizeof(char *) * (global->lines_maps + 1));
	global->nums[global->lines_maps] = NULL;
	global->path_textures
		= malloc(sizeof(char *) * (global->lines_textures + 1));
	global->path_textures[global->lines_textures] = NULL;
	if (!global->textures || !global->colors || !global->nums)
	{
		show_error_msg(1, "Malloc error");
		return (0);
	}
	return (1);
}

int	split_map(t_global *global)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (!malloc_maps(global))
		return (0);
	while (++i < global->lines_textures)
	{
		global->textures[i] = ft_strdup(global->map[i]);
	}
	i = global->empty_line + i;
	while (++j < global->lines_colors)
	{
		global->colors[j] = ft_strdup(global->map[i]);
		i++;
	}
	i = global->empty_line_2 + i;
	j = -1;
	while (++j < global->lines_maps)
	{
		global->nums[j] = ft_strdup(global->map[i]);
		i++;
	}
	return (1);
}

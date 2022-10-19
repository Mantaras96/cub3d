/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:24:41 by amantara          #+#    #+#             */
/*   Updated: 2022/10/19 20:24:17 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	rgb(int r, int g, int b)
{
	int	rgb;

	rgb = r;
	rgb = (rgb << 8) + g;
	rgb = (rgb << 8) + b;
	return (rgb);
}

int	save_num(t_global *global, char *nums, int i)
{
	char	**arr;

	arr = NULL;
	if (i == 0)
	{
		arr = ft_split(nums, ',');
		global->rgb_f = rgb(ft_atoi(arr[0]), ft_atoi(arr[1]), ft_atoi(arr[2]));
		free_matrix(&arr);
	}	
	if (i == 1)
	{
		arr = ft_split(nums, ',');
		global->rgb_c = rgb(ft_atoi(arr[0]), ft_atoi(arr[1]), ft_atoi(arr[2]));
		free_matrix(&arr);
	}
	free_matrix(&arr);
	return (0);
}

int	save_color(t_global *global)
{
	int		i;
	char	**arr;
	char	**arr2;

	i = 0;
	while (global->colors[i])
	{
		arr = ft_split(global->colors[i], ' ');
		arr2 = ft_split(arr[1], '\n');
		save_num(global, arr2[0], i);
		free_matrix(&arr);
		free_matrix(&arr2);
		i++;
	}
	free_matrix(&arr);
	free_matrix(&arr2);
	return (0);
}

int	check_nums(char *line_nums)
{
	int		i;
	char	**arr;

	i = 0;
	arr = ft_split(line_nums, ',');
	while (arr[i])
	{
		if (ft_isdigit(arr[i][0]))
		{
			if (ft_atoi(arr[i]) > 255 || ft_atoi(arr[i]) < 0)
			{
				free_matrix(&arr);
				return (1);
			}
		}
		else
		{
			free_matrix(&arr);
			return (1);
		}
		i++;
	}
	free_matrix(&arr);
	return (0);
}

int	validate_colors(t_global *global)
{
	int		i;
	char	**arr;

	i = 0;
	while (global->colors[i])
	{
		arr = ft_split(global->colors[i], ' ');
		if (!ft_strcmp(arr[0], "F") || !ft_strcmp(arr[0], "C"))
		{
			if (check_nums(arr[1]))
			{
				free_matrix(&arr);
				show_error_msg(1, "Error colores");
				break ;
			}
		}
		else
		{
			free_matrix(&arr);
			show_error_msg(2, "Error colores");
			break ;
		}
		free_matrix(&arr);
		i++;
	}
	save_color(global);
	return (0);
}

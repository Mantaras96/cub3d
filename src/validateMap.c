/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validateMap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:50:37 by amantara          #+#    #+#             */
/*   Updated: 2022/10/19 19:00:29 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	validate_one_player(t_global *global)
{
	int		i;
	int		j;
	t_corde	cordeplayer;

	i = 0;
	while (global->nums[i])
	{
		j = 0;
		while (global->nums[i][j])
		{
			if (global->nums[i][j] == 'N' || global->nums[i][j] == 'S'
				|| global->nums[i][j] == 'E' || global->nums[i][j] == 'W')
			{
				global->count_player++;
				cordeplayer.x = j;
				cordeplayer.y = i;
				cordeplayer.direction = global->nums[i][j];
			}
			if (global->max_lenght < j)
				global->max_lenght = j;
			j++;
		}
		global->character = cordeplayer;
		i++;
	}
	if (global->count_player > 1 || global->count_player == 0)
		printf("\nError mas de 1 o no encontrado player");
}

void	validate_rows(t_global *global)
{
	int	i;
	int	j;

	i = 1;
	while (global->nums[i])
	{
		j = 0;
		while (global->nums[i][j] == 32 && global->nums[i][j])
			j++;
		if (global->nums[i][j] != '1')
			printf("Error 1\n");
		if (i < (ft_matrix_len(global->nums) - 1)
			&& global->nums[i][ft_strlen(global->nums[i]) - 2] != '1')
			printf("Error 2\n");
		i++;
	}
}

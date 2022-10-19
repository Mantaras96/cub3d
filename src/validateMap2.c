/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validateMap2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:50:24 by amantara          #+#    #+#             */
/*   Updated: 2022/10/19 18:59:22 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    validate_first_last_row(t_global *global)
{
	int i;
	int j;

	j = 0;
	while(global->nums[0][j]){
		if (global->nums[0][j] != 32 && global->nums[0][j] != '1' && global->nums[0][j] != '\n' && global->nums[0][j] != '\t') // Se puede quitar el \n si se hace un split antes.
			printf("Error primera linea"); 
		j++;
	}

	j = 0;
	i = ft_matrix_len(global->nums) - 1;
	while(global->nums[i][j]){
		if (global->nums[i][j] != 32 && global->nums[i][j] != '1' && global->nums[i][j] != '\n' && global->nums[i][j] != '\t') // Se puede quitar el \n si se hace un split antes.
			printf("Error ultima linea");
		j++;
	}
}

int	is_space_tab(char c)
{
	if (c == 32 || c == '\t')
		return (1);
	return (0);
}

void check_directions(int i, int j, t_global *global){
	if (is_space_tab(global->nums[i - 1][j]) || is_space_tab(global->nums[i + 1][j]) || is_space_tab(global->nums[i][j - 1]) || is_space_tab(global->nums[i][j + 1])){
		printf("Error posicion[%d][%d]", i, j);
	} 
}

void	validate_all_different_wall(t_global *global)
{
	int	i;
	int	j;

	i = 1;
	while (global->nums[i]){
		j = 0;
		while (global->nums[i][j]){
			if (global->nums[i][j] == '0' || global->nums[i][j] == 'N' || global->nums[i][j] == 'S' || global->nums[i][j] == 'E'  || global->nums[i][j] == 'W')
				check_directions(i, j, global);
			j++;
		}
		i++;
	}
}

void	validate_map(t_global *global)
{
	int	i;

	i = 0;
	while (global->nums[i])
	{
		printf("MAPA: %s", global->nums[i]);
		i++;
	}
	global->count_player = 0;
	validate_one_player(global);
	validate_rows(global);
	validate_first_last_row(global);
	validate_all_different_wall(global);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validateMap2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:50:24 by amantara          #+#    #+#             */
/*   Updated: 2022/10/26 19:59:16 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// void	free_matrix(char ***matrix)
// {
// 	int	i;

// 	i = 0;
// 	while (matrix && matrix[0] && matrix[0][i])
// 	{
// 		free (matrix[0][i]);
// 		i++;
// 	}
// 	if (matrix)
// 	{
// 		free (matrix[0]);
// 		*matrix = NULL;
// 	}
// }

void	validate_first_last_row(t_global *global)
{
	int	i;
	int	j;

	j = 0;
	while (global->nums[0][j])
	{
		if (global->nums[0][j] != 32 && global->nums[0][j] != '1'
			&& global->nums[0][j] != '\n' && global->nums[0][j] != '\t')
			show_error_msg(6, "primera linea con error.");
		j++;
	}
	j = 0;
	i = ft_matrix_len(global->nums) - 1;
	while (global->nums[i][j])
	{
		if (global->nums[i][j] != 32 && global->nums[i][j] != '1'
			&& global->nums[i][j] != '\n' && global->nums[i][j] != '\t')
			show_error_msg(6, "ultima linea con error.");
		j++;
	}
}

int	is_space_tab(char c)
{
	printf("Valor %c",  c);
	if (c == 32 || c == '\t')
		return (1);
	return (0);
}

void	check_directions(int i, int j, t_global *global)
{
	if (is_space_tab(global->nums[i - 1][j])
		|| is_space_tab(global->nums[i + 1][j])
		|| is_space_tab(global->nums[i][j - 1])
		|| is_space_tab(global->nums[i][j + 1]))
		show_error_msg(6, "mapa no valido.");
}

void	validate_all_different_wall(t_global *global)
{
	int	i;
	int	j;

	i = 1;
	while (global->nums[i])
	{
		j = 0;
		while (global->nums[i][j])
		{
			if (global->nums[i][j] == '0' || global->nums[i][j] == 'N'
				|| global->nums[i][j] == 'S'
				|| global->nums[i][j] == 'E' || global->nums[i][j] == 'W')
				check_directions(i, j, global);
			j++;
		}
		i++;
	}
}

void parserMap(t_global *global){
	int i;
	int j;
	char **newMap;

	newMap = malloc((ft_matrix_len(global->nums) + 1) * sizeof(char *));
	i = 0;
	while (global->nums[i])
	{
		newMap[i] = malloc( sizeof(char) * (global->max_lenght + 1));
		j = 0;
		while (j < global->max_lenght){
			newMap[i][j] = ' ';
			j++;
		}
		newMap[i][j++] = '\n';
		newMap[i][j++] = '\0';
		i++;
	}
	newMap[i] = 0;
	i = 0;
	while (global->nums[i])
	{
		j = 0;
		while (global->nums[i][j] && global->nums[i][j] != '\n')
		{
			newMap[i][j] = global->nums[i][j];
			j++;
		}
		i++;
	}
	i = 0;
	free_matrix(&global->nums);
	global->nums = newMap;
}

void	validate_map(t_global *global)
{
	int	i;

	i = 0;
	global->count_player = 0;
	validate_one_player(global);
	parserMap(global);
	validate_first_last_row(global);
	//validate_rows(global);
	validate_all_different_wall(global);
}

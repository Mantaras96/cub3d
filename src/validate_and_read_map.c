/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_and_read_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 23:22:17 by albertmanta       #+#    #+#             */
/*   Updated: 2022/09/21 19:36:04 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	**validate_and_read_map(char *filename)
{
	ft_validate_name(filename);
	return (read_map(filename));
}

char	**read_map(char *filename)
{
	char	**map;
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		show_error_msg("Error\n La ruta del mapa no es correcta");
	map = ft_calloc(sizeof(char *), 1);
	if (map == NULL)
		show_error_msg("Error\n de memoria.\n");
	while (1)
	{
		line = get_next_line(fd);
		if (line != NULL)
			map = arr_push(map, line);
		else
			break ;
	}
	close(fd);
	return (map);
}

int	ft_validate_name(char *filename)
{
	if (!ft_strnstr(filename, ".cub", ft_strlen(filename)))
	{
		show_error_msg("Error\n El mapa no tiene la extension correcta");
		return (1);
	}
	return (0);
}

int	array_str_count(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

char	**arr_push(char **arr, char *str)
{
	int		i;
	int		n;
	char	**new;

	i = 0;
	n = array_str_count(arr);
	new = ft_calloc(sizeof(char *), n + 2);
	while (i < n)
	{
		new[i] = arr[i];
		i++;
	}
	new[i] = str;
	free(arr);
	return (new);
}

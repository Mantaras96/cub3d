/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 23:23:18 by albertmanta       #+#    #+#             */
/*   Updated: 2022/10/19 20:09:32 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	show_error_msg(int option, char *str)
{
	str = NULL;
	if (option == 1)
		printf("Error en las texturas");
	else if (option == 2)
		printf("Error en los coleres cielo y tierra");
	else if (option == 3)
		printf("Error en el mapa");
	else if (option == 4)
		printf("Error en abrir juego");
	exit(1);
}

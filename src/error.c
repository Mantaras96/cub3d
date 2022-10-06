/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 23:23:18 by albertmanta       #+#    #+#             */
/*   Updated: 2022/10/05 20:38:31 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	show_error_msg(int option, char *str)
{
	str = NULL;
	if (option == 1){
		printf("Error en las texturas");
	} else if (option == 2){
		printf("Error en los coleres cielo y tierra");
	} else if (option == 3){
		printf("Error en el mapa");
	} else if (option == 4){
		printf("Error en abrir juego");
	}
	exit(1);
}

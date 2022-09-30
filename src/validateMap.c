
#include "../include/cub3d.h"

void validate_one_player(t_global *global){
	int i; 
	int j;
	t_corde cordeplayer;

	i = 0;
	while (global->nums[i]){
		j = 0;
		while(global->nums[i][j]){
			if (global->nums[i][j] == 'N' || global->nums[i][j] == 'S'  || global->nums[i][j] == 'E'  || global->nums[i][j] == 'W'){
				global->count_player++;
				cordeplayer.x = j;
				cordeplayer.y = i;
			}
			if (global->max_lenght < j)
				global->max_lenght = j; // Con salto de linea hay que quitarlos. 
			j++;
		}
		global->character = cordeplayer;
		i++;
	}
	if (global->count_player > 1 || global->count_player < 1)
		printf("\nError mas de 1 o no encontrado player");
		// Funcion de error y free.
}

// Validated 1-true 0-false
void	validate_rows(t_global *global){
	int	i;
	int	j;
	
	i = 1;
	while (global->nums[i]){
		j = 0;
		while (global->nums[i][j] == 32 && global->nums[i][j])
			j++;
		if (global->nums[i][j] != '1')
			printf("Error 1\n");
		if (i < (ft_matrix_len(global->nums) - 1) && global->nums[i][ft_strlen(global->nums[i]) - 2] != '1')
			printf("Error 2\n");
		i++;
	}
}

void validate_first_last_row(t_global *global){
	int i;
	int j;

	j = 0;
	while(global->nums[0][j]){
		if (global->nums[0][j] != 32 && global->nums[0][j] != '1' && global->nums[0][j] != '\n' && global->nums[0][j] != '\t') // Se puede quitar el \n si se hace un split antes.
			printf("Error primera linea"); // Tirar error y que no siga. 
		j++;
	}

	j = 0;
	i = ft_matrix_len(global->nums) - 1;
	while(global->nums[i][j]){
		if (global->nums[i][j] != 32 && global->nums[i][j] != '1' && global->nums[i][j] != '\n' && global->nums[i][j] != '\t') // Se puede quitar el \n si se hace un split antes.
			printf("Error ultima linea"); // Tirar error y que no siga. 
		j++;
	}
}

int is_space_tab(char c){
	if (c == 32 || c == '\t'){
		return (1);
	}
	return (0);
}

void check_directions(int i, int j, t_global *global){
	//printf("Error posicion[%d][%d][%c][%d][%d][%d][%d]\n", i, j, global->nums[i][j], is_space_tab(global->nums[i][j + 1]), is_space_tab(global->nums[i][j  - 1]), is_space_tab(global->nums[i - 1][j]), is_space_tab(global->nums[i + 1][j]));
	if (is_space_tab(global->nums[i - 1][j]) || is_space_tab(global->nums[i + 1][j]) || is_space_tab(global->nums[i][j - 1]) || is_space_tab(global->nums[i][j + 1])){
		printf("Error posicion[%d][%d]", i, j);
	} 
}

void validate_all_different_wall(t_global *global){
	int i;
	int j;

	i = 1;
	while (global->nums[i]){
		j = 0;
		while (global->nums[i][j]){
			if (global->nums[i][j] == '0' || global->nums[i][j] == 'N' || global->nums[i][j] == 'S'  || global->nums[i][j] == 'E'  || global->nums[i][j] == 'W'){
				check_directions(i, j, global);
			}
			j++;
		} 
		i++;
	}
}

void validate_map(t_global *global){
	int i; 

	i = 0;
	while (global->nums[i]){
		printf("MAPA: %s", global->nums[i]);
		i++;
	}
	//Validaciones a realizar
	 // 1.- Primera linea y ultima solo se aceptan espacios y 1
	 // 2.- En la primera columna de cada fila y la ultima tiene que ser un espacio o 1
	 // 3.- Un espacio tiene que tener espacios a su alrededor o 1 si es 0 esta mal. 
	 // 4.- Tiene que existir N,S,E,W solo uno para identifica al jugador si hay mas de 1 esta mal.

	//4
	global->count_player = 0;
	validate_one_player(global);
	// //1 Validate first character and last
	//validate_rows(global);
	validate_first_last_row(global);
	validate_all_different_wall(global);
}
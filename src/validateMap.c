
#include "../include/cub3d.h"

void validate_one_player(t_global *global){
    int i; 
    int j;

    i = 0;
    j = 0;
    while (global->map[i]){
        while(global->map[i][j]){
            if (global->map[i][j] == 'N' || global->map[i][j] == 'S'  || global->map[i][j] == 'E'  || global->map[i][j] == 'W'){
                global->count_player++;
            }
            j++;
        }
        i++;
    }
}

void validate_map(t_global *global){
    int i; 

    i = 0;
    while (global->map[i]){
        printf("MAPA: %s", global->map[i]);
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

}
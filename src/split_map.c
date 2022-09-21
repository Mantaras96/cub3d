#include "../include/cub3d.h"

int	ft_matrix_len(char **matrix)
{
	int	i;

	i = 0;
	while (matrix && matrix[i])
		i++;
	return (i);
}

void split_map(t_global *global)
{
    int i;
    int j;
    char **aux;

    i = 0;
    global->textures = malloc(sizeof(char *) * (4));
    while(i < 4)
    {
        global->textures[i] = malloc(sizeof(char) * (ft_strlen(global->map[i])));
        global->textures[i] = global->map[i];
        printf("%s", global->textures[i]);
        i++;
    }
    global->colors = malloc(sizeof(char *) * (2));
    j = 0;
    while (++i < 7)
    {
        global->colors[j] = malloc(sizeof(char) * (ft_strlen(global->map[i])));
        global->colors[j] = global->map[i];
        j++;
    }
    printf("%s", global->colors[0]);
    printf("%s", global->colors[1]);

    aux = malloc(sizeof(char *) * (ft_matrix_len(global->map - 7)));
    j = 0;
    while (global->map[++i])
    {
        aux[j] = malloc(sizeof(char) * (ft_strlen(global->map[i])));
        aux[j] = global->map[i];
        printf("%s",aux[j]);
        j++;
    }
}
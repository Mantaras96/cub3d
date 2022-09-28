#include "../include/cub3d.h"

int check_nums(char *line_nums)
{
    int i;
    char **arr;
    i = 0;
    
    arr = ft_split(line_nums, ',');
    while(arr[i])
    {
        if (ft_isdigit(arr[i][0]))
        {
            if (ft_atoi(arr[i]) > 255 || ft_atoi(arr[i]) < 0)
            {
                free(arr);
                return (1);
            }
        }
        else
        {
            free(arr);
            return (1);
        }
        i++;
    }
    return (0);
}


int validate_colors(t_global *global)
{
    int i;
    char **arr;
    i = 0;

    while (global->colors[i])
    {
        arr = ft_split(global->colors[i], ' ');
        if (!ft_strcmp(arr[0], "F") || !ft_strcmp(arr[0], "C"))
        {
            if (check_nums(arr[1]))
            {
                show_error_msg("Colores erroneos");
                free(arr);
                break ;
            }
        }
        else{
            show_error_msg("Indicadores de colores erroneos\n");
            free(arr);
            break ;
        }
        free(arr);
        i++;
    }
    return (0);
}
#include "../include/cub3d.h"

// int rgb(int r, int g, int b)
// {
//     int rgb;
//     rgb = r;
// 	rgb = (rgb << 8) + g;
// 	rgb = (rgb << 8) + b;
// 	return (rgb);
// }

// int save_num(t_global *global, char *nums, int i)
// {
//     char **arr = NULL;
//     if (i == 0)
//     {
//         arr = ft_split(nums, ',');
//         global->rgb = rgb(ft_atoi(arr[0]), ft_atoi(arr[1]), ft_atoi(arr[2]));
//         printf("%d\n", global->rgb);
//     }
        
//     if (i == 1)
//     {
//         arr = ft_split(nums, ',');
//         global->rgb = rgb(ft_atoi(arr[0]), ft_atoi(arr[1]), ft_atoi(arr[2]));
//         printf("%d\n", global->rgb);
//     } 
//     return (0);
// }
// int save_color(t_global *global)
// {
//     int i;
//     i = 0;
//     char **arr;
//     char **arr2;

//     while (global->colors[i])
//     {
//         arr = ft_split(global->colors[i], ' ');
//         arr2 = ft_split(arr[1], '\n');
//         save_num(global, arr2[0], i);
//         i++;
//     }
//     return (0);
// }


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
                free_matrix(&arr);
                return (1);
            }
        }
        else
        {
            free_matrix(&arr);
            return (1);
        }
        i++;
    }
    free_matrix(&arr);
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
                free_matrix(&arr);
                break ;
            }
        }
        else{
            show_error_msg("Indicadores de colores erroneos\n");
            free_matrix(&arr);
            break ;
        }
        free_matrix(&arr);
        i++;
    }
    // global->rgb = save_color(global);
    return (0);
}
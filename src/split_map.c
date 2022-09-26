#include "../include/cub3d.h"

int	ft_matrix_len(char **matrix)
{
	int	i;

	i = 0;
	while (matrix && matrix[i])
		i++;
	return (i);
}

int malloc_maps(t_global *global)
{
    global->textures = malloc(sizeof(char *) * (global->lines_textures + 1));
    global->textures[global->lines_textures] = NULL;
    global->colors = malloc(sizeof(char *) * (global->lines_colors + 1));
    global->colors[global->lines_colors] = NULL;
    global->nums = malloc(sizeof(char *) * (global->lines_maps + 1));
    global->nums[global->lines_maps] = NULL;
    if(!global->textures || !global->colors || !global->nums)
    {
        show_error_msg("Malloc error");
        return (0);
    }
    return (1);
}

int split_map(t_global *global)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if(!malloc_maps(global))
        return (0);
    while(i < global->lines_textures)
    {
 		global->textures[i] = ft_strdup(global->map[i]);
		i++;
    }
    i = global->empty_line + i;
    while (j < global->lines_colors)
    {
 		global->colors[j] = ft_strdup(global->map[i]);
		i++;
        j++;
    }
    i = global->empty_line_2 + i;
    j = 0;
    while(j < global->lines_maps)
    {
 		global->nums[j] = ft_strdup(global->map[i]);
		i++;
        j++;
    }
    return (1);
// //     printf("TEXT%d\n", global->lines_textures );
// //     printf("colors%d\n", global->lines_colors );
// //     printf("maps%d\n", global->lines_maps );
// //     printf("empty1 %d\n", global->empty_line );
// //     printf("empty2 %d\n", global->empty_line_2 );
//     i = 0;
// 	while(global->textures[i])
// 	{
// 		printf("%s\n", global->textures[i]);
// 		i++;
// 	}
//     i = 0;
//    // printf("\n");
// 	while(global->colors[i])
// 	{
// 		printf("%s", global->colors[i]);
   
// 		i++;
// 	}
//     i = 0;
// 	while(global->nums[i])
// 	{
// 		printf("%s", global->nums[i]);
      
// 		i++;
// 	}
//     printf("\n");
//     printf("\n");
}
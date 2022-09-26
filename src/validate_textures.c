#include "../include/cub3d.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	if (!str1)
		return (1);
	while (*str1)
	{
		if (*str1 != *str2)
			break ;
		str1++;
		str2++;
	}
	return (*(const unsigned char *) str1 - *(const unsigned char *) str2);
}

int validate_textures(t_global *global)
{
    int i;
    char **arr;
    i = 0;
    //int fd;
    //MIRAR CON EL GNL Y SPLIT 
    // if (global->textures[0][0] != 'N' && global->textures[0][1] != 'O')
    //     printf("to1");
    // if (global->textures[1][0] != 'S' && global->textures[1][1] != 'O')
    //     printf("to2");
    // if (global->textures[2][0] != 'W' && global->textures[2][1] != 'E')
    //     printf("to3");
    // if (global->textures[3][0] != 'E' && global->textures[3][1] != 'A')
    //     printf("to4");
    return (0);
}
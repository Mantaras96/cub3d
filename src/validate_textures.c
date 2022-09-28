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

int access_textures(const char *filename)
{
    int fd;
    char **arr;
    arr = ft_split(filename, '\n');
    fd = open(arr[0], R_OK);
    if (fd == -1)
    {
        return (1);
        close(fd);
        free_matrix(&arr);
    }
    close(fd);
    free_matrix(&arr);
    return (0);
}

int validate_textures(t_global *global)
{
    int i;
    char **arr;
    i = 0;

    while (global->textures[i])
    {
        arr = ft_split(global->textures[i], ' ');
        if (!ft_strcmp(arr[0], "NO") || !ft_strcmp(arr[0], "SO") || !ft_strcmp(arr[0], "WE") || !ft_strcmp(arr[0], "EA"))
        {
            if (access_textures(arr[1]))
            {
                show_error_msg("Error en las rutas de las texturas\n");
                free_matrix(&arr);
                break ;
            }
        }
        else {
            show_error_msg("Identificador de las texturas erroneo.\n");
            free_matrix(&arr);
            break ;
        }
            free_matrix(&arr);
        i++;
    }
    return (0);
}
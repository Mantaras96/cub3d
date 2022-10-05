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

int access_textures(const char *filename, t_global *global, int i)
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
    while (i < global->lines_textures)
    {
        global->path_textures[i] = ft_strdup(arr[0]);
        i++;
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

    global->path_textures = malloc(sizeof(char *) * (global->lines_textures + 1));
    global->path_textures[global->lines_textures] = NULL;
    while (global->textures[i])
    {
        arr = ft_split(global->textures[i], ' ');
        if (!ft_strcmp(arr[0], "NO") || !ft_strcmp(arr[0], "SO") || !ft_strcmp(arr[0], "WE") || !ft_strcmp(arr[0], "EA"))
        {
            if (access_textures(arr[1], global, i))
            {
                free_matrix(&arr);
                show_error_msg(1, "Error ruta de las texturas\n");
                break ;
            }
        }
        else {
            free_matrix(&arr);
            show_error_msg(1, "Identificador de las texturas erroneo.\n");
            break ;
        }
            free_matrix(&arr);
        i++;
    }
    return (0);
}
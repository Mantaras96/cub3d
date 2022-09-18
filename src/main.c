#include "../cub3d.h"

int print_error(int type)
{
    if (type == 1)
        printf("No .cub file specified.\n");
    if (type == 2)
        printf("Too Many arguments.\n");
    if (type == 3)
        printf("Wrong .cub extension\n");
    return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}


int read_file(int argc, char *file)
{
    char **split;

    split = ft_split(file, '.');
    if (!split[1] || (split[1] && ft_strcmp(split[1], "cub")))
    {
        print_error(3);
        return (0);
    }
    return (1);
}

int check_args(int argc)
{
    if (argc < 2)
    {
        print_error(1);
        return(0);
    }
    else if (argc > 2)
    {
        print_error(2);
        return(0);
    }
    return (1);
}

int main(int argc, char **argv)
{
    //t_info *info;
    char *file;

    file = argv[1];
    if (!check_args(argc))
        return (0);
    if (!read_file(argc, file))
        return(0);
    //if (!check_map(file)) TODO: Albert implementar
	//return (0)
}

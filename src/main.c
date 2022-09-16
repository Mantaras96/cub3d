#include "../cub3d.h"

int print_error(int type)
{
    if (type == 1)
        printf("No .cub file specified.\n");
    if (type == 2)
        printf("Too Many arguments.\n");
    return (0);
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
    (void)argv;
    if (!check_args(argc))
        return (0);
}
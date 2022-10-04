SRC	=	src/main.c \
		src/validate_and_read_map.c \
		src/validate_letters_map.c \
		src/show_map.c \
		src/error.c \
		src/mover.c \
		gnl/get_next_line_utils.c \
		gnl/get_next_line.c \
		src/split_map.c \
		src/validateMap.c \
		src/validate_textures.c \
		src/validate_colors.c \
		src/init_ray.c

NAME 	= 	cub3d

CC 		= 	gcc
CFLAGS 	= 	-Wall -Wextra -Werror

OBJ		= 	$(SRC:.c=.o)

LIBFT 	= libft/libft.a

MLXLINK = -L mlx
MINILIBX = -I mlx
OPENGL = -lmlx -framework OpenGL -framework AppKit


all: $(NAME)

$(NAME): $(OBJ)
		make -C mlx
		make -C libft
		$(CC) $(MLXLINK) $(MINILIBX) $(LIBFT) $(OPENGL) $^ -o $(NAME)

clean:
		make clean -C mlx
		make clean -C libft
		/bin/rm -rf src/*.o

fclean: clean 
		make fclean -C libft
		/bin/rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re


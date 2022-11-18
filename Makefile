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
		src/validateMap2.c \
		src/validateMap3.c \
		src/validate_textures.c \
		src/validate_colors.c \
		src/raycasting.c\
		src/raycasting2.c\
		src/key_move.c\
		src/utils.c\
		src/key_move_vision.c\
		src/ft_directions.c\
		src/split_space.c \

NAME 	= 	cub3d

CC 		= 	gcc
CFLAGS 	= 	-Wall -Wextra -Werror

OBJ		= 	$(SRC:.c=.o)

LIBFT 	= libft/libft.a

MLXLINK = -L mlx
MINILIBX = -I mlx
OPENGL = -lmlx -framework OpenGL -framework AppKit


all: $(NAME)

compile_libft :
	@if [ ! -d "libft" ]; then \
		git clone https://github.com/Mantaras96/libft.git; \
	fi
	@make -C libft

$(NAME): compile_libft $(OBJ)
		make -C mlx
		$(CC) $(LIBFT) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)
		rm -rf ./libft

clean:
		make clean -C mlx
		/bin/rm -rf src/*.o

fclean: clean 
		/bin/rm -f $(NAME)

re: fclean all
.PHONY: all re compile_libft clean fclean 


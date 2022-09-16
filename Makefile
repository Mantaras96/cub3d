SRCS =	src/main.c \
			libft/ft_isalpha.c \
			libft/ft_isdigit.c \
			libft/ft_isalnum.c \
			libft/ft_isascii.c \
			libft/ft_isprint.c \
			libft/ft_strlen.c\
			libft/ft_memset.c\
			libft/ft_strlcat.c \
			libft/ft_toupper.c \
			libft/ft_tolower.c \
			libft/ft_strchr.c \
			libft/ft_strrchr.c \
			libft/ft_strncmp.c\
			libft/ft_bzero.c\
			libft/ft_atoi.c\
			libft/ft_memcmp.c\
			libft/ft_memcpy.c\
			libft/ft_strlcpy.c\
			libft/ft_memmove.c\
			libft/ft_memchr.c\
			libft/ft_putchar_fd.c\
			libft/ft_putstr_fd.c\
			libft/ft_putendl_fd.c\
			libft/ft_putnbr_fd.c\
			libft/ft_calloc.c\
			libft/ft_strdup.c\
			libft/ft_striteri.c\
			libft/ft_substr.c\
			libft/ft_strjoin.c\
			libft/ft_strmapi.c\
			libft/ft_strnstr.c\
			libft/ft_itoa.c\
			libft/ft_strtrim.c\
			libft/ft_split.c

OBJS = ${SRCS:.c=.o}
NAME = cub3d

HEADER = cub3d.h
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} $ -I ${HEADER} -c $< -o ${<:.c=.o}
	
${NAME}:	${OBJS} ${HEADER}
			${CC}  ${OBJS} -o ${NAME}
all:		${NAME}

test:		${OBJS} ${HEADER}
			${CC}  ${CFLAGS} ${OBJS} -o ${NAME}	&& ./cub3d
clean: 		
			${RM} ${OBJS}
fclean: 	clean
			${RM} ${NAME}
			${RM} bonus
re:			fclean all
.PHONY: all clean fclean re
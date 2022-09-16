SRCS =	src/main.c 

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
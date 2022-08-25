NAME	=	bsq

C_FILES	=	main.c \
			tools/ft_split.c \
			tools/ft_string.c \
			tools/ft_itoa.c \
			solve_square/ft_solve_square.c \
			parsing/ft_check_header.c \
			parsing/ft_check_map.c \
			parsing/ft_file.c \
			parsing/ft_free.c \
			parsing/ft_parsing.c \
			parsing/ft_get_stdin.c


OBJS	=	${C_FILES:.c=.o}

HEADERS	= 	headers/

FLAGS	=	-Wall -Wextra -Werror -O3

RM 		=	rm -f

.PHONY:		all clean fclean

all:		${NAME}

.c.o:
			gcc ${FLAGS} -c $< -o ${<:.c=.o} -I ${HEADERS}

$(NAME):	${OBJS}
			gcc ${FLAGS} -g ${OBJS} -I ${HEADERS} -o ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

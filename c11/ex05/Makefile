SRCS		= ft_atoi.c ft_op.c ft_putnbr.c main.c

OBJS		= ${SRCS:.c=.o}

NAME		= do-op

GCC			= gcc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

.c.o:
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@${GCC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:		
			@${RM} ${OBJS}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re

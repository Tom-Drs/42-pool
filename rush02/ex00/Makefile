SRCS		= srcs/main.c srcs/ft_check_1.c srcs/ft_check_2.c srcs/ft_check_3.c srcs/ft_file.c srcs/ft_parsing.c srcs/ft_print_argument.c srcs/ft_search_print.c srcs/ft_split.c srcs/ft_str.c srcs/ft_check_line.c srcs/ft_manage_dict.c

OBJS		= ${SRCS:.c=.o}

HEADERS 	= includes/

NAME		= rush-02

DEBUG	= rush-02.dSYM

GCC			= gcc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

RMFOLDER	= rm -Rf

LLDB		= lldb

FSANITIZE	= -fsanitize=address
.c.o:
			@${CC} ${CFLAGS} -I ${HEADERS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@${GCC} -o ${NAME} ${OBJS}

all:		${NAME}

debug:		${OBJS}
			@${GCC} -g3 -o ${NAME} ${OBJS}
			${LLDB} ./${NAME}

fsanitize:	${OBJS}
			@${GCC} ${FSANITIZE} -o ${NAME} ${OBJS}

clean:		
			@${RM} ${OBJS}

debug_clean:clean
			@${RMFOLDER} ${DEBUG}

fclean:		debug_clean
			@${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re

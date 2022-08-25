CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRCS= ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
TARGET_LIB=libft.a
HEADER=includes
OBJS=$(SRCS:.c=.o)

all : $(TARGET_LIB)

$(TARGET_LIB): $(SRCS)
	cd srcs && ar -rc ../libft.a $(OBJS)

$(SRCS):
	cd srcs && $(CC) $(CFLAGS) -I ../$(HEADER) -c $@ 

clean:
	cd srcs && rm -rf $(OBJS)

fclean: clean
	rm -rf $(TARGET_LIB)

re: fclean all

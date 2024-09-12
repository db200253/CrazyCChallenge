CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRCS= ./SRCS/ft_malloc.c \
		./SRCS/ft_calloc.c \
		./SRCS/ft_realloc.c \
		./SRCS/ft_free.c \
		./SRCS/ft_malloc_display.c \
		./SRCS/utils.c \
		./SRCS/main.c
HEADER= ./Includes/ft_malloc.h
OBJS=$(SRCS:.c=.o)
NAME=ft_malloc

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re : fclean
	all

.PHONY: all clean fclean re
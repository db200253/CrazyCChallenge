CC=gcc
CFLAGS=-Wall -Wextra -Werror

SRCS_DIR=./SRCS
TEST_DIR=./Test
INCLUDE_DIR=./Includes

SRCS=$(wildcard $(SRCS_DIR)/*.c)
TEST=$(TEST_DIR)/test.c \
		$(SRCS_DIR)/utils.c
HEADER=$(INCLUDE_DIR)/ft_malloc.h

OBJS=$(SRCS:.c=.o)
OBJ_TEST=$(TEST:.c=.o)

NAME=ft_malloc
NAME_TEST=unit_tests

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS) $(OBJ_TEST)

fclean: clean
	rm -f $(NAME) $(NAME_TEST)

re: fclean all

test: $(OBJ_TEST) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ_TEST) -I $(INCLUDE_DIR) -o $(NAME_TEST)

$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

$(TEST_DIR)/%.o: $(TEST_DIR)/%.c $(HEADER)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

.PHONY: all clean fclean re test

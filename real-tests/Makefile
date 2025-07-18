include Include.mk

CC=cc
LIBFT_DIR=./libft
SRCS_DIR=./srcs
OBJS_DIR=./objs
CFLAGS=-Wall -Wextra -Werror -g -I$(LIBFT_DIR)/includes
SRCS=$(wildcard $(SRCS_DIR)/*.c) main.c
OBJS = $(SRCS:.c=.o)
NAME=nothing-tester

all: libft $(NAME)

libft:
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(OBJS_DIR)/%.o: %.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all libft clean fclean re $(NAME)
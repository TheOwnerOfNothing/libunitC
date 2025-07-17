include Include.mk

CC=cc
LIBFT_DIR=./libft
OBJS_DIR=./objs
CFLAGS=-Wall -Wextra -Werror -g -I$(LIBFT_DIR)/includes
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

.PHONY: all libft $(NAME)
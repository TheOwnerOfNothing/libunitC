CC=cc
LIBFT_DIR = ./libft
UNITLIBS_DIR = ./unit_libs
OBJS_DIR = ./objs
SRCS_DIR = ./srcs
CFLAGS = -Wall -Wextra -Werror -g -I$(LIBFT_DIR)/includes -I./includes
SRCS = $(addprefix $(SRCS_DIR)/, launch_tests.c load_test.c main.c)
OBJS = $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS))
NAME = nothing-tester

all: libft $(NAME)

libft:
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(UNITLIBS_DIR) -lgnlunit -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all libft
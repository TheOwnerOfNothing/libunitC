CC=cc
LIBFT_DIR = ./libft
OBJS_DIR = ./objs
SRCS_DIR = ./srcs
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)/includes -I./includes
LIBUNIT_CORE_SRCS = launch_tests.c load_test.c
LIBUNIT_CORE_OBJS := $(LIBUNIT_CORE_SRCS:.c=.o)
LIBUNIT_CORE_OBJS := $(addprefix objs/, $(LIBUNIT_CORE_OBJS))
LIBUNIT_OBJS = ft_strlen_00_launcher.o ft_strlen_01_basic_test.o ft_strlen_02_empty_test.o
LIBUNIT_OBJS := $(addprefix objs/, $(LIBUNIT_OBJS))
LIBUNIT_OBJS += $(LIBUNIT_CORE_OBJS)
LIBUNIT = libunit.a
LIBUNIT_FINGERPRINT = .libunit_fingerprint
TESTER = tester
LIBFT = ./libft/libft.a

all: $(LIBFT)
	$(MAKE) -C ./tests/ft_strlen
	$(MAKE) $(LIBUNIT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBUNIT): $(LIBUNIT_FINGERPRINT) $(LIBUNIT_CORE_OBJS)
	ar rcs $@ $(LIBUNIT_OBJS)

test:
	$(MAKE) -C ./tests/ft_strlen
	$(MAKE) $(TESTER)

$(TESTER): $(LIBFT) $(LIBUNIT)
	$(CC) $(CFLAGS) srcs/main.c -L. -L$(LIBFT_DIR) -lunit -lft -o $@
	@./tester

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all test
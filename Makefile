CC=cc
LIBFT_DIR = ./libft
OBJS_DIR = ./objs
SRCS_DIR = ./srcs
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)/includes -I./includes
LIBUNIT_CORE_SRCS = launch_tests.c load_test.c
LIBUNIT_CORE_OBJS := $(LIBUNIT_CORE_SRCS:.c=.o)
LIBUNIT_CORE_OBJS := $(addprefix objs/, $(LIBUNIT_CORE_OBJS))
LIBUNIT_OBJS = gnl_00_launcher.o gnl_01_basic_test.o gnl_02_empty_test.o
LIBUNIT_OBJS := $(addprefix objs/, $(LIBUNIT_OBJS))
LIBUNIT_OBJS += $(LIBUNIT_CORE_OBJS)
LIBUNIT = libunit.a
LIBUNIT_FINGERPRINT = .libunit_fingerprint
TESTER = tester
LIBFT = ./libft/libft.a

all: $(LIBFT)
	$(MAKE) -C ./tests/get_next_line
	$(MAKE) $(LIBUNIT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBUNIT): $(LIBUNIT_FINGERPRINT) $(LIBUNIT_CORE_OBJS)
	ar rcs $@ $(LIBUNIT_OBJS)

$(TESTER): $(LIBFT) $(LIBUNIT)
	$(CC) $(CFLAGS) srcs/main.c -L. -lunit -L$(LIBFT_DIR) -lft -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all
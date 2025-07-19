CC=cc
LIBFT_DIR = ../../libft
OBJS_DIR = ../../objs
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)/includes -I../../framework/includes
SRCS = 00_launcher.c \
	01_basic_test.c \
	02_zero_test.c \
	03_negative_test.c \
	04_max_int_test.c \
	05_min_int_test.c \
	06_negative_zero_test.c
FRAMEWORK_SRCS = launch_tests.c load_test.c
FRAMEWORK_SRCS_DIR = ../../framework/srcs
OBJS = $(SRCS:.c=.o)
FRAMEWORK_OBJS := $(FRAMEWORK_SRCS:.c=.o)
OBJS := $(addprefix ../../objs/ft_atoi_,$(OBJS))
FRAMEWORK_OBJS := $(addprefix ../../objs/,$(FRAMEWORK_OBJS))
OBJS += $(FRAMEWORK_OBJS)
FINGERPRINT = ../../.libunit_fingerprint
LIBUNIT = libunit.a

all: $(LIBUNIT)

$(LIBUNIT): $(OBJS)
	ar rcs $@ $(OBJS)
	touch $(FINGERPRINT)

$(OBJS_DIR)/ft_atoi_%.o: %.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR)/%.o: $(FRAMEWORK_SRCS_DIR)/%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

test:
	$(MAKE) -C ../../ test ARG=ft_split

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIBUNIT)

re: fclean all

.PHONY: all clean fclean test re
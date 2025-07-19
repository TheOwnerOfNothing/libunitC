CC=cc
LIBFT_DIR = ../../libft
OBJS_DIR = ../../objs
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)/includes -I../../framework/includes
SRCS := 00_launcher.c \
	01_basic_test.c \
	02_empty_test.c \
	03_delimiters_test.c \
	04_delimiters_space_test.c
FRAMEWORK_SRCS := launch_tests.c load_test.c
FRAMEWORK_SRCS_BONUS := launch_tests_bonus.c load_test.c
FRAMEWORK_SRCS_DIR = ../../framework/srcs
OBJS := $(SRCS:.c=.o)
FRAMEWORK_OBJS := $(FRAMEWORK_SRCS:.c=.o)
FRAMEWORK_OBJS_BONUS := $(FRAMEWORK_SRCS_BONUS:.c=.o)
OBJS := $(addprefix ../../objs/ft_split_,$(OBJS))
FRAMEWORK_OBJS := $(addprefix ../../objs/,$(FRAMEWORK_OBJS))
FRAMEWORK_OBJS_BONUS := $(addprefix ../../objs/,$(FRAMEWORK_OBJS_BONUS))
OBJS += $(FRAMEWORK_OBJS)
FINGERPRINT = ../../.libunit_fingerprint
LIBUNIT = libunit.a

all: $(LIBUNIT)

$(LIBUNIT): $(OBJS)
	ar rcs $@ $(OBJS)
	touch $(FINGERPRINT)

$(OBJS_DIR)/ft_split_%.o: %.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR)/%.o: $(FRAMEWORK_SRCS_DIR)/%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

test:
	$(MAKE) -C ../../ test ARG=real-tests

test-bonus:
	$(MAKE) -C ../../ test-bonus ARG=real-tests

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean: clean
	rm -f $(LIBUNIT)
	rm -f $(LIBUNIT_BONUS)

re: fclean all

.PHONY: all clean fclean test re test-bonus
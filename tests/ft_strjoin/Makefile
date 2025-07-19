CC=cc
LIBFT_DIR = ../../libft
OBJS_DIR = ../../objs
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)/includes -I../../framework/includes
SRCS = 00_launcher.c \
	01_basic_test.c \
	02_one_empty_test.c \
	03_empty_test.c
FRAMEWORK_SRCS = launch_tests.c load_test.c
FRAMEWORK_SRCS_DIR = ../../framework/srcs
OBJS = $(SRCS:.c=.o)
FRAMEWORK_OBJS := $(FRAMEWORK_SRCS:.c=.o)
OBJS := $(addprefix ../../objs/ft_strjoin_,$(OBJS))
FRAMEWORK_OBJS := $(addprefix ../../objs/,$(FRAMEWORK_OBJS))
OBJS += $(FRAMEWORK_OBJS)
FINGERPRINT = ../../.libunit_fingerprint
LIBUNIT = libunit.a

all: $(LIBUNIT)

$(LIBUNIT): $(OBJS)
	ar rcs $@ $(OBJS)
	touch $(FINGERPRINT)

$(OBJS_DIR)/ft_strjoin_%.o: %.c
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
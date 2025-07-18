CC=cc
LIBFT_DIR = ../../libft
OBJS_DIR = ../../objs
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)/includes -I../../includes
SRCS = 00_launcher.c 01_basic_test.c 02_empty_test.c
OBJS = $(SRCS:.c=.o)
OBJS := $(addprefix ../../objs/gnl_,$(OBJS))
FINGERPRINT = ../../.libunit_fingerprint

all: $(FINGERPRINT)

$(FINGERPRINT): $(OBJS)
	touch $(FINGERPRINT)

$(OBJS_DIR)/gnl_%.o: %.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all $(NAME)
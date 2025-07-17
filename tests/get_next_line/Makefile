CC=cc
LIBFT_DIR = ../../libft
OBJS_DIR = ./objs
CFLAGS = -Wall -Wextra -Werror -g -I$(LIBFT_DIR)/includes -I../../includes
SRCS = 00_launcher.c 01_basic_test.c 02_ko_test.c
OBJS = $(SRCS:.c=.o)
OBJS := $(addprefix objs/,$(OBJS))
NAME = libgnlunit
OUT_DIR = ../../unit_libs
TARGET = $(OUT_DIR)/$(NAME).a

all: $(TARGET)

$(NAME): $(TARGET)

$(TARGET): $(OBJS)
	mkdir -p $(OUT_DIR)
	ar rcs $(OUT_DIR)/$@ $(OBJS)

$(OBJS_DIR)/%.o: %.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all $(NAME)
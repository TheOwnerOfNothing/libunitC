ifndef ARG
	ARG=all
endif

CC=cc
LIBFT_DIR = ./libft
OBJS_DIR = ./objs
SRCS_DIR = ./framework/srcs
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)/includes -I./framework/includes
LIBUNIT_CORE_OBJS = launch_tests.o load_test.o
LIBUNIT_MAIN_OBJ = main.o
LIBUNIT_CORE_OBJS := $(addprefix objs/, $(LIBUNIT_CORE_OBJS))
LIBUNIT_MAIN_OBJ := $(addprefix objs/, $(LIBUNIT_MAIN_OBJ))
LIBUNIT_OBJS = ft_strlen_00_launcher.o \
	ft_strlen_01_basic_test.o \
	ft_strlen_02_empty_test.o \
	real_tests_00_launcher.o \
	real_tests_01_ok_test.o \
	real_tests_02_ko_test.o \
	real_tests_03_sigsegv_test.o \
	real_tests_04_sigbus_test.o \
	real_tests_05_sigfpe_test.o \
	real_tests_06_sigill_test.o \
	real_tests_07_sigabrt_test.o \
	real_tests_08_sigpipe_test.o \
	ft_split_00_launcher.o \
	ft_split_01_basic_test.o \
	ft_split_02_empty_test.o \
	ft_split_03_delimiters_test.o \
	ft_split_04_delimiters_space_test.o
LIBUNIT_OBJS := $(addprefix objs/, $(LIBUNIT_OBJS))
LIBUNIT_OBJS += $(LIBUNIT_CORE_OBJS)
LIBUNIT = libunit.a
LIBUNIT_FINGERPRINT = .libunit_fingerprint
TESTER = tester
LIBFT = ./libft/libft.a

all: $(LIBFT)
	$(MAKE) -C ./tests/ft_strlen
	$(MAKE) -C ./tests/ft_split
	$(MAKE) -C ./tests/real-tests
	$(MAKE) $(LIBUNIT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBUNIT): $(LIBUNIT_FINGERPRINT) $(LIBUNIT_CORE_OBJS)
	ar rcs $@ $(LIBUNIT_OBJS)

test:
	$(MAKE) -C ./tests/ft_strlen
	$(MAKE) -C ./tests/ft_split
	$(MAKE) -C ./tests/real-tests
	$(MAKE) $(LIBUNIT)
	$(MAKE) $(TESTER)
	./tester $(ARG)

$(TESTER): $(LIBFT) $(LIBUNIT) $(LIBUNIT_MAIN_OBJ)
	$(CC) $(CFLAGS) $(LIBUNIT_MAIN_OBJ) -L. -L$(LIBFT_DIR) -lunit -lft -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(LIBUNIT_OBJS) $(LIBUNIT_MAIN_OBJ)
	rm -rf objs

fclean: clean
	rm -f $(LIBUNIT)
	rm -f $(TESTER)

re: fclean all

.PHONY: all test clean fclean re
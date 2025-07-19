ifndef ARG
	ARG=all
endif

CC=cc
LIBFT_DIR = ./libft
OBJS_DIR = ./objs
SRCS_DIR = ./framework/srcs
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)/includes -I./framework/includes
HEADERS = ./framework/includes/libunit.h
LIBUNIT_CORE_OBJS = launch_tests.o load_test.o
LIBUNIT_CORE_OBJS_BONUS = launch_tests_bonus.o load_test.o
LIBUNIT_MAIN_OBJ = main.o
LIBUNIT_CORE_OBJS := $(addprefix objs/, $(LIBUNIT_CORE_OBJS))
LIBUNIT_CORE_OBJS_BONUS := $(addprefix objs/, $(LIBUNIT_CORE_OBJS_BONUS))
LIBUNIT_MAIN_OBJ := $(addprefix objs/, $(LIBUNIT_MAIN_OBJ))
LIBUNIT_OBJS := ft_strlen_00_launcher.o \
	ft_strlen_01_basic_test.o \
	ft_strlen_02_empty_test.o \
	real_tests_00_launcher.o \
	real_tests_01_ok_test.o \
	real_tests_02_ko_test.o \
	real_tests_03_sigsegv_test.o \
	real_tests_04_sigbus_test.o \
	ft_split_00_launcher.o \
	ft_split_01_basic_test.o \
	ft_split_02_empty_test.o \
	ft_split_03_delimiters_test.o \
	ft_split_04_delimiters_space_test.o \
	ft_strjoin_00_launcher.o \
	ft_strjoin_01_basic_test.o \
	ft_strjoin_02_one_empty_test.o \
	ft_strjoin_03_empty_test.o \
	ft_atoi_00_launcher.o \
	ft_atoi_01_basic_test.o \
	ft_atoi_02_zero_test.o \
	ft_atoi_03_negative_test.o \
	ft_atoi_04_max_int_test.o \
	ft_atoi_05_min_int_test.o \
	ft_atoi_06_negative_zero_test.o
LIBUNIT_OBJS_BONUS := real_tests_05_sigfpe_test.o \
	real_tests_06_sigill_test.o \
	real_tests_07_sigabrt_test.o \
	real_tests_08_sigpipe_test.o \
	$(LIBUNIT_OBJS)
LIBUNIT_OBJS := $(addprefix objs/, $(LIBUNIT_OBJS))
LIBUNIT_OBJS += $(LIBUNIT_CORE_OBJS)
LIBUNIT_OBJS_BONUS := $(addprefix objs/, $(LIBUNIT_OBJS_BONUS))
LIBUNIT_OBJS_BONUS += $(LIBUNIT_CORE_OBJS)
LIBUNIT = libunit.a
LIBUNIT_BONUS = libunit_bonus.a
LIBUNIT_FINGERPRINT = .libunit_fingerprint
TESTER = tester
TESTER_BONUS = tester_bonus
LIBFT = ./libft/libft.a

all:
	$(MAKE) -C ./tests/ft_strlen
	$(MAKE) -C ./tests/ft_split
	$(MAKE) -C ./tests/ft_strjoin
	$(MAKE) -C ./tests/ft_atoi
	$(MAKE) -C ./tests/real-tests
	$(MAKE) $(LIBUNIT)

bonus:
	$(MAKE) -C ./tests/ft_strlen
	$(MAKE) -C ./tests/ft_split
	$(MAKE) -C ./tests/ft_strjoin
	$(MAKE) -C ./tests/ft_atoi
	$(MAKE) -C ./tests/real-tests bonus
	$(MAKE) $(LIBUNIT_BONUS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBUNIT): $(LIBUNIT_FINGERPRINT) $(LIBUNIT_CORE_OBJS)
	ar rcs $@ $(LIBUNIT_OBJS)

$(LIBUNIT_BONUS): $(LIBUNIT_FINGERPRINT) $(LIBUNIT_CORE_OBJS_BONUS)
	ar rcs $@ $(LIBUNIT_OBJS_BONUS)

test:
	$(MAKE) -C ./tests/ft_strlen
	$(MAKE) -C ./tests/ft_split
	$(MAKE) -C ./tests/ft_strjoin
	$(MAKE) -C ./tests/ft_atoi
	$(MAKE) -C ./tests/real-tests
	$(MAKE) $(LIBUNIT)
	$(MAKE) $(TESTER)
	./tester $(ARG)

test-bonus:
	$(MAKE) -C ./tests/ft_strlen
	$(MAKE) -C ./tests/ft_split
	$(MAKE) -C ./tests/ft_strjoin
	$(MAKE) -C ./tests/ft_atoi
	$(MAKE) -C ./tests/real-tests bonus
	$(MAKE) $(LIBUNIT_BONUS)
	$(MAKE) $(TESTER_BONUS)
	./tester_bonus $(ARG)

$(TESTER): $(LIBFT) $(LIBUNIT) $(LIBUNIT_MAIN_OBJ)
	$(CC) $(CFLAGS) $(LIBUNIT_MAIN_OBJ) -L. -L$(LIBFT_DIR) -lunit -lft -o $@

$(TESTER_BONUS): $(LIBFT) $(LIBUNIT_BONUS) $(LIBUNIT_MAIN_OBJ)
	$(CC) $(CFLAGS) $(LIBUNIT_MAIN_OBJ) -L. -L$(LIBFT_DIR) -lunit_bonus -lft -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS)
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(LIBUNIT_OBJS) $(LIBUNIT_MAIN_OBJ)
	rm -rf objs
	rm -f .libunit_fingerprint

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f ./tests/ft_strlen/libunit.a \
		./tests/ft_strjoin/libunit.a \
		./tests/ft_split/libunit.a \
		./tests/ft_atoi/libunit.a \
		./tests/real-tests/libunit_bonus.a \
		$(LIBUNIT) \
		$(LIBUNIT_BONUS) \
		$(TESTER) \
		$(TESTER_BONUS)

re: fclean all

.PHONY: all test clean fclean re test-bonus bonus
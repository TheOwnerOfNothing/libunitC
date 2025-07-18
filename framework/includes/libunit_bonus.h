/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:57:28 by amsaleh           #+#    #+#             */
/*   Updated: 2025/07/19 20:21:18 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_BONUS_H
# define LIBUNIT_BONUS_H

# define TIMEOUT 5

# include <sys/wait.h>
# include <libft.h>
# include <signal.h>

typedef struct s_test_data
{
	char	*test_name;
	int		(*test_func)(void);
	int		verbose;
}	t_test_data;

int	load_test(t_list **lst,
		char *test_name, int (*test_func)(void), int verbose);
int	launch_tests(char *func_name, t_list *test_lst);
int	ft_strlen_basic_test(void);
int	ft_strlen_empty_test(void);
int	ft_strlen_launcher(void);
int	real_tests_launcher(void);
int	real_tests_ok_test(void);
int	real_tests_ko_test(void);
int	real_tests_sigsegv_test(void);
int	real_tests_sigbus_test(void);
int	real_tests_sigfpe_test(void);
int	real_tests_sigill_test(void);
int	real_tests_sigabrt_test(void);
int	real_tests_sigpipe_test(void);
int	ft_split_launcher(void);
int	ft_split_basic_test(void);
int	ft_split_empty_test(void);
int	ft_split_delimiters_test(void);
int	ft_split_delimiters_space_test(void);
int	ft_strjoin_basic_test(void);
int	ft_strjoin_one_empty_test(void);
int	ft_strjoin_empty_test(void);
int	ft_strjoin_launcher(void);
int	ft_atoi_basic_test(void);
int	ft_atoi_zero_test(void);
int	ft_atoi_negative_test(void);
int	ft_atoi_max_int_test(void);
int	ft_atoi_min_int_test(void);
int	ft_atoi_launcher(void);
int	ft_atoi_negative_zero_test(void);

#endif
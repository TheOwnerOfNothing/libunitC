/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:57:28 by amsaleh           #+#    #+#             */
/*   Updated: 2025/07/19 03:09:01 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <libft.h>
# include <signal.h>

typedef struct s_test_data
{
	char	*test_name;
	int		(*test_func)(void);
}	t_test_data;

enum	e_tests
{
	ALL_TESTS,
	FT_STRLEN_TESTS,
	REAL_TESTS
};

int	load_test(t_list **lst, char *test_name, int (*test_func)(void));
int	launch_tests(char *func_name, t_list *test_lst);
int	ft_strlen_basic_test(void);
int	ft_strlen_empty_test(void);
int	ft_strlen_launcher(void);
int	real_tests_launcher(void);
int	real_tests_ok_test(void);
int	real_tests_ko_test(void);
int	real_tests_segsegv_test(void);

#endif
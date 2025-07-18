/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:57:28 by amsaleh           #+#    #+#             */
/*   Updated: 2025/07/17 20:40:07 by amsaleh          ###   ########.fr       */
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

enum e_child_status
{
    CHILD_SUCCESS,
    CHILD_KO,
    CHILD_SEGFAULT,
    CHILD_SIGBUS,
    CHILD_UNKNOWN
};

int load_test(t_list **lst, char *test_name, int (* test_func)(void));
int	launch_tests(char *func_name, t_list *test_lst);
int ft_strlen_basic_test(void);
int ft_strlen_empty_test(void);
int ft_strlen_launcher(void);

#endif
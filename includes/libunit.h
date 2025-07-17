/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <mhasoneh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:57:28 by amsaleh           #+#    #+#             */
/*   Updated: 2025/07/17 20:24:07 by mhasoneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "../libft/includes/libft.h"

typedef struct s_test_data
{
	char	*test_name;
	int		(*test_func)(void);
}	t_test_data;

int	launch_tests(t_list *test_lst);
int	load_test(t_list **lst, char *test_name, int (*test_func)(void));
int	execute_test(t_list **lst, char *test_name, int (*test_func)(void));
int	strlen_basic_test(void);
int	strlen_null_test(void);

#endif

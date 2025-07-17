/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <mhasoneh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:18:28 by amsaleh           #+#    #+#             */
/*   Updated: 2025/07/17 20:24:47 by mhasoneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libunit.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>

int	launch_tests(t_list *test_lst)
{
	pid_t	p;

	while (test_lst)
	{
		p = fork();
		if (p < 0)
		{
			write(1, "fork fail", 10);
			exit(1);
		}
		else if (p == 0)
		{
			execute_test(
				(t_test_data *)test_lst->content,
				((t_test_data *)test_lst->content)->test_name,
				((t_test_data *)test_lst->content)->test_func
				);
			exit(0);
		}
		ft_printf("%s\n", ((t_test_data *)test_lst->content)->test_name);
		test_lst = test_lst->next;
	}
	while (wait(NULL) > 0)
		;
	return (0);
}

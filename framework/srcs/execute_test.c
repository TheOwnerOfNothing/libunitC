/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <mhasoneh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:45:57 by amsaleh           #+#    #+#             */
/*   Updated: 2025/07/17 20:23:48 by mhasoneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libunit.h>
#include <libft.h>

int	execute_test(t_list **lst, char *test_name, int (*test_func)(void))
{
	int	result;

	result = test_func();
	if (result == 0)
		ft_printf("[✔] %s passed\n", test_name);
	else
	{
		ft_printf("[✘] %s failed with code %d\n", test_name, result);
		exit(result);
	}
}

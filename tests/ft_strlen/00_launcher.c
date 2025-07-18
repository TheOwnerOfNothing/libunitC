/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:44:27 by amsaleh           #+#    #+#             */
/*   Updated: 2025/07/19 17:53:39 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libunit.h>

int	ft_strlen_launcher(void)
{
	t_list	*tests_lst;
	int		res;

	tests_lst = 0;
	load_test(&tests_lst, "basic string test", &ft_strlen_basic_test, 1);
	load_test(&tests_lst, "empty string test", &ft_strlen_empty_test, 1);
	res = launch_tests("ft_strlen", tests_lst);
	return (res);
}

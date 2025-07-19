/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:44:27 by amsaleh           #+#    #+#             */
/*   Updated: 2025/07/19 18:30:10 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libunit.h>

int	ft_atoi_launcher(void)
{
	t_list	*tests_lst;
	int		res;

	tests_lst = 0;
	load_test(&tests_lst, "basic test", &ft_atoi_basic_test, 1);
	load_test(&tests_lst, "zero test", &ft_atoi_zero_test, 1);
	load_test(&tests_lst, "negative test", &ft_atoi_negative_test, 1);
	load_test(&tests_lst, "max int test", &ft_atoi_max_int_test, 1);
	load_test(&tests_lst, "min int test", &ft_atoi_max_int_test, 1);
	load_test(&tests_lst, "min int test", &ft_atoi_negative_zero_test, 1);
	res = launch_tests("ft_atoi", tests_lst);
	return (res);
}

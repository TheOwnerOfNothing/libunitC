/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:44:27 by amsaleh           #+#    #+#             */
/*   Updated: 2025/07/19 17:53:28 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libunit.h>

int	ft_split_launcher(void)
{
	t_list	*tests_lst;
	int		res;

	tests_lst = 0;
	load_test(&tests_lst, "basic split test", &ft_split_basic_test, 1);
	load_test(&tests_lst, "empty split test", &ft_split_empty_test, 1);
	load_test(&tests_lst, "delimiters split test", &ft_split_delimiters_test, 1);
	load_test(&tests_lst, "delimiters with space split test",
		&ft_split_delimiters_space_test, 1);
	res = launch_tests("ft_split", tests_lst);
	return (res);
}

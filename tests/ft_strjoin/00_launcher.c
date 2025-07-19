/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:44:27 by amsaleh           #+#    #+#             */
/*   Updated: 2025/07/19 18:08:05 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libunit.h>

int	ft_strjoin_launcher(void)
{
	t_list	*tests_lst;
	int		res;

	tests_lst = 0;
	load_test(&tests_lst, "basic join test", &ft_strjoin_basic_test, 1);
	load_test(&tests_lst, "one empty join test", &ft_strjoin_one_empty_test, 1);
	load_test(&tests_lst, "empty join test", &ft_strjoin_empty_test, 1);
	res = launch_tests("ft_strjoin", tests_lst);
	return (res);
}

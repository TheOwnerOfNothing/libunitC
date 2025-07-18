/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <mhasoneh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:44:27 by amsaleh           #+#    #+#             */
/*   Updated: 2025/07/17 19:51:03 by mhasoneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libunit.h>

int	ft_strlen_launcher(void)
{
	t_list	*tests_lst;
	int		res;

    tests_lst = 0;
    load_test(&tests_lst, "ft_strlen basic string test", &ft_strlen_basic_test);
    load_test(&tests_lst, "ft_strlen empty string test", &ft_strlen_empty_test);
    res = launch_tests("ft_strlen", tests_lst);
    return (res);
}

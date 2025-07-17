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

#include "../libft/includes/libft.h"
#include "../includes/libunit.h"

int	gnl_launcher(void)
{
	t_list	*tests_lst;
	int		res;

	tests_lst = 0;
	load_test(&tests_lst, "Basic test", &strlen_basic_test);
	load_test(&tests_lst, "KO test", &strlen_null_test);
	res = launch_tests(tests_lst);
	return (res);
}

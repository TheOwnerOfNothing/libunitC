/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 02:18:58 by amsaleh           #+#    #+#             */
/*   Updated: 2025/07/19 19:25:09 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libunit.h>

int	real_tests_launcher(void)
{
	t_list	*tests_lst;
	int		res;

	tests_lst = 0;
	load_test(&tests_lst, "OK test", &real_tests_ok_test, 1);
	load_test(&tests_lst, "KO test", &real_tests_ko_test, 1);
	load_test(&tests_lst, "SIGSEGV test", &real_tests_sigsegv_test, 1);
	load_test(&tests_lst, "SIGBUS test", &real_tests_sigbus_test, 1);
	// load_test(&tests_lst, "SIGFPE test", &real_tests_sigfpe_test, 1);
	// load_test(&tests_lst, "SIGILL test", &real_tests_sigill_test, 1);
	// load_test(&tests_lst, "SIGABRT test", &real_tests_sigabrt_test, 1);
	// load_test(&tests_lst, "SIGPIPE test", &real_tests_sigpipe_test, 1);
	res = launch_tests("real-tests", tests_lst);
	return (res);
}

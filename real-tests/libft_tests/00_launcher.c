/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <mhasoneh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:28:00 by mhasoneh          #+#    #+#             */
/*   Updated: 2025/07/18 18:41:00 by mhasoneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	basic_tests_launcher(void)
{
	t_list	*testlist;

	testlist = NULL;
	load_test(&testlist, "BASIC_TESTS", "Success test", &success_test);
	load_test(&testlist, "BASIC_TESTS", "Failure test", &failure_test);
	load_test(&testlist, "BASIC_TESTS", "Segfault test", &segfault_test);
	return (launch_tests(testlist));
}

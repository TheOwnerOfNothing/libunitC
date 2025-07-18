/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <mhasoneh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:06:44 by mhasoneh          #+#    #+#             */
/*   Updated: 2025/07/17 20:22:53 by mhasoneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "/includes/libunit.h"

int	test_one(void)
{
	return (0);
}

int	test_two(void)
{
	return (1);
}

int	main(void)
{
	t_list	*tests;

	tests = NULL;
	load_test(&tests, "Test One", test_one);
	load_test(&tests, "Test Two", test_two);
	launch_tests(tests);
	return (0);
}

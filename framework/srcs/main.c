/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 23:19:02 by amsaleh           #+#    #+#             */
/*   Updated: 2025/07/19 03:12:28 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libunit.h>

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	if (ac != 2)
	{
		ft_dprintf(STDERR_FILENO, "USAGE: ./tester <ARG>\n");
		return (0);
	}
	if (!ft_strcmp(av[1], "all"))
	{
		ft_strlen_launcher();
		real_tests_launcher();
	}
	else if (!ft_strcmp(av[1], "ft_strlen"))
		ft_strlen_launcher();
	else if (!ft_strcmp(av[1], "real-tests"))
		real_tests_launcher();
	return (0);
}

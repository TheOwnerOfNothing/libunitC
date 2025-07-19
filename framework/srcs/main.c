/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 23:19:02 by amsaleh           #+#    #+#             */
/*   Updated: 2025/07/19 19:25:00 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libunit.h>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_dprintf(STDERR_FILENO, "USAGE: ./tester <TEST>\n");
		return (0);
	}
	if (!ft_strcmp(av[1], "all"))
	{
		ft_strlen_launcher();
		ft_split_launcher();
		ft_strjoin_launcher();
		ft_atoi_launcher();
		real_tests_launcher();
	}
	else if (!ft_strcmp(av[1], "ft_strlen"))
		ft_strlen_launcher();
	else if (!ft_strcmp(av[1], "ft_split"))
		ft_split_launcher();
	else if (!ft_strcmp(av[1], "ft_strjoin"))
		ft_strjoin_launcher();
	else if (!ft_strcmp(av[1], "ft_atoi"))
		ft_atoi_launcher();
	else if (!ft_strcmp(av[1], "real-tests"))
		real_tests_launcher();
	return (0);
}

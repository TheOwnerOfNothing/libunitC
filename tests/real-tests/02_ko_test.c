/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_ko_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 02:56:53 by amsaleh           #+#    #+#             */
/*   Updated: 2025/07/19 16:56:40 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libunit.h>

int	real_tests_ko_test(void)
{
	if (ft_strlen("1234") == 5)
		return (0);
	else
		return (-1);
}

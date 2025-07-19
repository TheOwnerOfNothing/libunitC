/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:40:23 by amsaleh           #+#    #+#             */
/*   Updated: 2025/07/19 16:53:06 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libunit.h>

int	ft_split_basic_test(void)
{
	char	**res;

	res = ft_split("HABDA 123", ' ');
	if (!res)
		return (-1);
	if (ft_arrlen((void *)res) == 2 && !ft_strcmp("HABDA", res[0])
		&& !ft_strcmp("123", res[1]))
		return (0);
	return (-1);
}

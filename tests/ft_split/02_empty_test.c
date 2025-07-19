/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_empty_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:40:23 by amsaleh           #+#    #+#             */
/*   Updated: 2025/07/19 17:09:21 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libunit.h>

int	ft_split_empty_test(void)
{
	char	**res;

	res = ft_split("", ' ');
	if (!res)
		return (-1);
	if (ft_arrlen((void *)res) == 0)
		return (0);
	return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_delimiters_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:13:50 by amsaleh           #+#    #+#             */
/*   Updated: 2025/07/19 18:01:57 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libunit.h>

int	ft_split_delimiters_test(void)
{
	char	**res;

	res = ft_split("            ", ' ');
	if (!res)
		return (-1);
	if (ft_arrlen((void *)res) == 0)
	{
		free_array((void **)res);
		return (0);
	}
	else
	{
		free_array((void **)res);
		return (-1);
	}
}

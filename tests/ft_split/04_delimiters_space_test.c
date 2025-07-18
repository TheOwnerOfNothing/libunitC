/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_delimiters_space_test.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:15:44 by amsaleh           #+#    #+#             */
/*   Updated: 2025/07/19 18:02:16 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libunit.h>

int	ft_split_delimiters_space_test(void)
{
	char	**res;

	res = ft_split("\n\n\n \n\n\n\n", '\n');
	if (!res)
		return (-1);
	if (ft_arrlen((void *)res) == 1 && !ft_strcmp(res[0], " "))
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

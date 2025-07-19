/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_one_empty_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:00:08 by amsaleh           #+#    #+#             */
/*   Updated: 2025/07/19 18:32:54 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libunit.h>

int	ft_strjoin_one_empty_test(void)
{
	char	*str;

	str = ft_strjoin("123", "");
	if (!str)
		return (-1);
	if (!ft_strcmp(str, "123"))
	{
		free(str);
		return (0);
	}
	else
	{
		free(str);
		return (-1);
	}
}

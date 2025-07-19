/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:58:56 by amsaleh           #+#    #+#             */
/*   Updated: 2025/07/19 18:32:51 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libunit.h>

int	ft_strjoin_basic_test(void)
{
	char	*str;

	str = ft_strjoin("123", "123");
	if (!str)
		return (-1);
	if (!ft_strcmp(str, "123123"))
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

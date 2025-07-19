/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_empty_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:03:32 by amsaleh           #+#    #+#             */
/*   Updated: 2025/07/19 18:32:56 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libunit.h>

int	ft_strjoin_empty_test(void)
{
	char	*str;

	str = ft_strjoin("", "");
	if (!str)
		return (-1);
	if (!ft_strcmp(str, ""))
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

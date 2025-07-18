/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:13:09 by amsaleh           #+#    #+#             */
/*   Updated: 2025/03/04 02:15:49 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	size_t	len;

	if (!s1 || !s2)
		return (-1);
	if (ft_strlen(s1) > ft_strlen(s2))
		len = ft_strlen(s1);
	else
		len = ft_strlen(s2);
	i = 0;
	while (i < len)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:45:57 by amsaleh           #+#    #+#             */
/*   Updated: 2025/07/18 23:27:02 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libunit.h>

int	load_test(t_list **lst, char *test_name, int (*test_func)(void))
{
	t_test_data	*test_data;
	t_list		*node;

	test_data = malloc(sizeof(t_test_data));
	if (!test_data)
		return (0);
	test_data->test_name = test_name;
	test_data->test_func = test_func;
	node = ft_lstnew(test_data);
	if (!node)
	{
		free(test_data);
		return (0);
	}
	ft_lstadd_back(lst, node);
	return (1);
}

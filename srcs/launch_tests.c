/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:18:28 by amsaleh           #+#    #+#             */
/*   Updated: 2025/07/17 19:20:17 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libunit.h>
#include <libft.h>

int    launch_tests(t_list *test_lst)
{
    while (test_lst)
    {
        ft_printf("%s\n", ((t_test_data *)test_lst->content)->test_name);
        test_lst = test_lst->next;
    }
    return (0);
}
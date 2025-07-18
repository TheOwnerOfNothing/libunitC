/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <mhasoneh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:18:28 by amsaleh           #+#    #+#             */
/*   Updated: 2025/07/18 18:42:52 by mhasoneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libunit.h>
#include <libft.h>

// int	launch_tests(t_list *test_lst)
// {
// 	pid_t	p;
// 	int		status;
// 	int		total_tests;
// 	int		passed_tests;
// 	int		result;
// 	int		exit_code;
// 	int		signal;

// 	total_tests = 0;
// 	passed_tests = 0;
// 	while (test_lst)
// 	{
// 		total_tests++;
// 		p = fork();
// 		if (p < 0)
// 		{
// 			write(1, "fork fail", 10);
// 			exit(1);
// 		}
// 		else if (p == 0)
// 		{
// 			result = ((t_test_data *)test_lst->content)->test_func();
// 			exit(result);
// 		}
// 		else
// 		{
// 			wait(&status);
// 			if (WIFEXITED(status))
// 			{
// 				exit_code = WEXITSTATUS(status);
// 				if (exit_code == 0)
// 				{
// 					ft_printf("[%s]:[%s]:[OK]\n",
// 						"FUNCTION_NAME",
// 						((t_test_data *)test_lst->content)->test_name);
// 					passed_tests++;
// 				}
// 				else
// 				{
// 					ft_printf("[%s]:[%s]:[KO]\n", "FUNCTION_NAME",
// 						((t_test_data *)test_lst->content)->test_name);
// 				}
// 			}
// 			else if (WIFSIGNALED(status))
// 			{
// 				signal = WTERMSIG(status);
// 				if (signal == SIGSEGV)
// 				{
// 					ft_printf("[%s]:[%s]:[SIGSEGV]\n", "FUNCTION_NAME",
// 						((t_test_data *)test_lst->content)->test_name);
// 				}
// 				else if (signal == SIGBUS)
// 				{
// 					ft_printf("[%s]:[%s]:[SIGBUS]\n", "FUNCTION_NAME",
// 						((t_test_data *)test_lst->content)->test_name);
// 				}
// 			}
// 		}
// 		test_lst = test_lst->next;
// 	}
// 	ft_printf("%d/%d tests checked\n", passed_tests, total_tests);
// 	if (passed_tests == total_tests)
// 		return (0);
// 	else
// 		return (1);
// }

int	launch_tests(t_list *test_lst)
{
    while (test_lst)
    {
        ft_printf(((t_test_data *)test_lst->content)->test_name);
        test_lst = test_lst->next;
    }
    return (0);
}
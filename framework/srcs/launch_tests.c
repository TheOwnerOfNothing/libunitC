/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:18:28 by amsaleh           #+#    #+#             */
/*   Updated: 2025/07/19 02:11:43 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libunit.h>

void	child_func(t_list *test_lst)
{
	t_list	*node_prev;
	int		status;

	status = ((t_test_data *)test_lst->content)->test_func();
	while (test_lst)
	{
		node_prev = test_lst;
		test_lst = test_lst->next;
		ft_lstdelone(node_prev, free);
	}
	exit(status);
}

int	start_test(t_list *test_lst)
{
	pid_t	pid;
	int		wstatus;

	pid = fork();
	if (pid == -1)
	{
		ft_dprintf(STDERR_FILENO, "fork() failed!");
		return (-1);
	}
	if (!pid)
		child_func(test_lst);
	wait(&wstatus);
	if (WIFSIGNALED(wstatus))
		return (WTERMSIG(wstatus));
	return (WEXITSTATUS(wstatus));
}

void	print_test_result(char *func_name,
	int child_ret, t_test_data *test_data)
{
	char	*msg;

	if (!child_ret)
		msg = "OK";
	else if (child_ret == 255)
		msg = "KO";
	else if (child_ret == SIGSEGV)
		msg = "SIGSEGV";
	else if (child_ret == SIGBUS)
		msg = "SIGBUS";
	else
		msg = "UNKNOWN ERROR";
	ft_printf("%s:%s:%s\n", func_name, test_data->test_name, msg);
}

int	launch_tests(char *func_name, t_list *test_lst)
{
	t_test_data	*test_data;
	t_list		*node_prev;
	size_t		tests_count;
	size_t		success_tests;
	int			child_ret;

	tests_count = 0;
	success_tests = 0;
	while (test_lst)
	{
		test_data = test_lst->content;
		child_ret = start_test(test_lst);
		print_test_result(func_name, child_ret, test_data);
		if (!child_ret)
			success_tests++;
		node_prev = test_lst;
		test_lst = test_lst->next;
		ft_lstdelone(node_prev, free);
		tests_count++;
	}
	ft_printf("Tests Passed: %lu/%lu\n", tests_count, success_tests);
	if (success_tests != tests_count)
		return (-1);
	return (0);
}

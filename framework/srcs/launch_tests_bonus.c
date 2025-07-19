/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:18:28 by amsaleh           #+#    #+#             */
/*   Updated: 2025/07/19 19:27:45 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libunit_bonus.h>

void	child_func(t_list *test_lst)
{
	t_list	*node_prev;
	int		status;

	alarm(TIMEOUT);
	status = ((t_test_data *)test_lst->content)->test_func();
	alarm(0);
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

	if (!test_data->verbose)
		return ;
	if (!child_ret)
		msg = "\e[32mOK\e[00m";
	else if (child_ret == 255)
		msg = "\e[31mKO\e[00m";
	else if (child_ret == SIGSEGV)
		msg = "\e[33mSIGSEGV\e[00m";
	else if (child_ret == SIGBUS)
		msg = "\e[33mSIGBUS\e[00m";
	else if (child_ret == SIGFPE)
		msg = "\e[33mSIGFPE\e[00m";
	else if (child_ret == SIGILL)
		msg = "\e[33mSIGILL\e[00m";
	else if (child_ret == SIGABRT)
		msg = "\e[33mSIGABRT\e[00m";
	else if (child_ret == SIGPIPE)
		msg = "\e[33mSIGPIPE\e[00m";
	else if (child_ret == SIGALRM)
		msg = "\e[31mTIMEOUT\e[00m";
	else
		msg = "\e[31mUNKNOWN ERROR\e[00m";
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
	ft_printf("Tests Passed: %lu/%lu\n", success_tests, tests_count);
	if (success_tests != tests_count)
		return (-1);
	return (0);
}

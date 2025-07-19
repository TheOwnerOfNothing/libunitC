/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_sigbus_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 03:15:26 by amsaleh           #+#    #+#             */
/*   Updated: 2025/07/19 04:28:05 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libunit.h>
#include <sys/mman.h>
#include <fcntl.h>

int	real_tests_sigbus_test(void)
{
	char	*addr;
	char	*new_addr;
	int		*tmp;
	int		val;

	__asm__("pushf\norl $0x40000,(%rsp)\npopf");
	addr = malloc(sizeof(int));
	new_addr = addr + 1;
	tmp = (int *)new_addr;
	*tmp = 42;
	val = *tmp;
	free(addr);
	if (val == 42)
		return (0);
	return (-1);
}
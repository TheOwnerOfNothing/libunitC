/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_sigfpe_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:21:41 by amsaleh           #+#    #+#             */
/*   Updated: 2025/07/19 16:56:28 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	real_tests_sigfpe_test(void)
{
	__asm__ volatile (
		"movq $42, %%rax\n"
		"movq $0, %%rdi\n"
		"movq $0, %%rdx\n"
		"divq %%rdi"
		:
		:
		: "rax", "rdi", "rdx"
	);
	if (1)
		return (0);
	else
		return (-1);
}

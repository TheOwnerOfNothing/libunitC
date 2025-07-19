/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_sigpipe_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:35:43 by amsaleh           #+#    #+#             */
/*   Updated: 2025/07/19 14:40:28 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libunit.h>

int	real_tests_sigpipe_test(void)
{
    int pipefds[2];
    
    if (pipe(pipefds) == -1)
        return (-1);
    close(pipefds[0]);
    write(pipefds[1], "42", 2);
    close(pipefds[1]);
	if (1)
		return (0);
	return (-1);
}

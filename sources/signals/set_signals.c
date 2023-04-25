/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 12:36:43 by lucocozz          #+#    #+#             */
/*   Updated: 2023/04/23 23:25:32 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

static void	sigint_handler(int signum)
{
	(void)signum;
	g_running = 0;
}

void	set_signals(void)
{
	struct sigaction	action = {0};

	action.sa_handler = &sigint_handler;
	action.sa_flags = SA_ONSTACK;
	// action.sa_flags = SA_RESTART;
	if (sigaction(SIGINT, &action, NULL) == -1) {
		dprintf(STDERR_FILENO, "sigaction(): error\n");
		exit(EXIT_FAILURE);
	}
}


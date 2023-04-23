/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 12:36:43 by lucocozz          #+#    #+#             */
/*   Updated: 2023/04/23 17:44:40 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

static void	__handle_sigint(int signum)
{
	(void)signum;
	g_running = false;
}

void	set_signals(void)
{
	signal(SIGINT, __handle_sigint);
}

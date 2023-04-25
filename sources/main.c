/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:43:13 by lucocozz          #+#    #+#             */
/*   Updated: 2023/04/23 19:45:40 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

volatile sig_atomic_t g_running = 1;

int	main(int argc, char **argv)
{
	int		sock;
	int		status;
	t_cli	cli = get_cli(argc, argv);

	set_signals();
	sock = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ARP));
	if (sock == -1) {
		dprintf(STDERR_FILENO, "socket(): %s\n", strerror(errno));
		return (EXIT_ERROR);
	}
	status = arp_poisoning(sock, cli);
	close(sock);
	return (status);
}

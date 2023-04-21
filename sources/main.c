/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:43:13 by lucocozz          #+#    #+#             */
/*   Updated: 2023/04/21 16:14:24 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

void	set_header(struct ether_arp *packet)
{
	mac_str_to_binary(BROADCAST_MAC_ADDR, packet->ether.dhost);
	mac_str_to_binary("08:00:27:d2:f5:f6", packet->ether.shost);
	packet->ether.type = htons(ETHERTYPE_ARP);

	packet->arp.hardware_type = htons(ARPHRD_ETHER);
	packet->arp.protocol_type = htons(ETHERTYPE_IP);
	packet->arp.hardware_len = MAC_ADDR_LEN;
	packet->arp.protocol_len = IP_ADDR_LEN;
	packet->arp.opcode = htons(ARPOP_REQUEST);
	mac_str_to_binary("08:00:27:d2:f5:f6", packet->arp.sender_hardware);
	inet_pton(AF_INET, "10.0.2.15", packet->arp.sender_ip);
	mac_str_to_binary(NULL_MAC_ADDR, packet->arp.target_hardware);
	inet_pton(AF_INET, "10.0.2.4", packet->arp.target_ip);
}

int	main(int argc, char **argv)
{
	(void)argv;
	(void)argc;
	// if (argc != 5) {
		// dprintf(STDERR_FILENO, ERR_USAGE);
		// return (EXIT_FAILURE);
	// }
	int					sock;
	struct ether_arp	packet = {0};
	struct sockaddr_ll	device = {0};

	set_header(&packet);
	print_ether_arp(packet);

	sock = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ARP));
	if (sock == -1) {
		dprintf(STDERR_FILENO, "socket(): %s\n", strerror(errno));
		return (1);
	}

	device.sll_ifindex = if_nametoindex("enp0s3");
	if (sendto(sock, &packet, sizeof(struct ether_arp), 0, (struct sockaddr*)&device, sizeof(device)) == -1)
		dprintf(STDERR_FILENO, "sendto(): %s\n", strerror(errno));
	close(sock);
	return (EXIT_SUCCESS);
}

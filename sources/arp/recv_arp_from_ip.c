/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recv_arp_from_ip.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:09:21 by lucocozz          #+#    #+#             */
/*   Updated: 2023/04/23 17:46:15 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

int	recv_arp_from_ip(int sock, struct ether_arp *packet, const char *from_ip)
{
	u_char				ip[IP_ADDR_LEN] = {0};

	inet_pton(AF_INET, from_ip, ip);
	do {
		if (recvfrom(sock, (void*)packet, sizeof(*packet), 0, NULL, NULL) < 0)
			return (-1);
	} while (ft_memcmp(packet->arp.sender_ip, ip, IP_ADDR_LEN) != 0 && g_running == true);

	printf("\nReceiving Packet:\n");
	print_ether_arp(*packet);

	return (0);
}

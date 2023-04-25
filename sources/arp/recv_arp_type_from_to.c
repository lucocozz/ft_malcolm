/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recv_arp_type_from_to.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:09:21 by lucocozz          #+#    #+#             */
/*   Updated: 2023/04/25 13:32:59 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

int	recv_arp_type_from_to(int sock, struct ether_arp *packet, int type, const char *from, const char *to)
{
	u_char	ip_to[IP_ADDR_LEN] = {0};
	u_char	ip_from[IP_ADDR_LEN] = {0};

	inet_pton(AF_INET, from, ip_from);
	inet_pton(AF_INET, to, ip_to);
	while (true)
	{
		if (recvfrom(sock, (void*)packet, sizeof(*packet), 0, NULL, NULL) < 0) {
			if (errno == EINTR)
				return (0);
			dprintf(STDERR_FILENO, "recvfrom(): %s\n", strerror(errno));
			return (-1);
		}
		if (htons(packet->arp.opcode) == type
			&& ft_memcmp(packet->arp.sender_ip, ip_from, IP_ADDR_LEN) == 0
			&& ft_memcmp(packet->arp.target_ip, ip_to, IP_ADDR_LEN) == 0) {
			break;
		}
	} 

	printf("Receiving: "); print_arp(*packet);
	// print_ether_arp(*packet);

	return (0);
}

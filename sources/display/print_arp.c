/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:02:58 by lucocozz          #+#    #+#             */
/*   Updated: 2023/04/24 16:10:45 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

void	print_arp(struct ether_arp packet)
{
	if (ntohs(packet.arp.opcode) == ARPOP_REQUEST) {
		printf("Who has ");
		print_ip_address(packet.arp.target_ip);
		printf("? Tell ");
		print_ip_address(packet.arp.sender_ip); printf("\n");
	}
	else if (ntohs(packet.arp.opcode) == ARPOP_REPLY) {
		print_ip_address(packet.arp.sender_ip);
		printf(" is at ");
		print_mac_address(packet.arp.sender_hardware); printf("\n");
	}
}

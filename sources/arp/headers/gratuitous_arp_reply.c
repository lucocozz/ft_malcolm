/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gratuitous_arp_reply.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:38:27 by lucocozz          #+#    #+#             */
/*   Updated: 2023/04/25 15:44:14 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

void	gratuitous_arp_reply(struct ether_arp *packet, t_cli cli)
{
	mac_str_to_binary(BROADCAST_MAC_ADDR, packet->ether.dhost);
	mac_str_to_binary(cli.sender_hardware, packet->ether.shost);
	packet->ether.type = htons(ETHERTYPE_ARP);

	packet->arp.hardware_type = htons(ARPHRD_ETHER);
	packet->arp.protocol_type = htons(ETHERTYPE_IP);
	packet->arp.hardware_len = MAC_ADDR_LEN;
	packet->arp.protocol_len = IP_ADDR_LEN;
	packet->arp.opcode = htons(ARPOP_REPLY);
	mac_str_to_binary(cli.sender_hardware, packet->arp.sender_hardware);
	inet_pton(AF_INET, cli.sender_ip, packet->arp.sender_ip);
	mac_str_to_binary(BROADCAST_MAC_ADDR, packet->arp.target_hardware);
	inet_pton(AF_INET, cli.sender_ip, packet->arp.target_ip);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ether_arp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:59:52 by lucocozz          #+#    #+#             */
/*   Updated: 2023/04/21 13:38:57 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

static const char	*__get_opcode(__be16 opcode)
{
	switch (opcode)
	{
	case ARPOP_REPLY:
		return ("reply");
	case ARPOP_REQUEST:
		return ("request");
	default:
		return ("unknown");
	}
}

static const char	*__get_hardware_type(__be16 type)
{
	switch (type)
	{
	case ARPHRD_ETHER:
		return ("Ethernet");
	default:
		return ("unknown");
	}
}

static const char	*__get_protocol_type(__be16 type)
{
	switch (type)
	{
	case ETH_P_IP:
		return ("IPv4 (0x0800)");
	case ETH_P_IPV6:
		return ("IPv6 (0x86dd)");
	default:
		return ("unknown");
	}
}

static void	__print_ethernet_header(struct ether_hdr header)
{
	printf("Ethernet II\n");
	printf("  Destination: "); print_mac_address(header.dhost); printf("\n");
	printf("  Source: "); print_mac_address(header.shost); printf("\n");
	printf("  Type: 0x%04x\n", ntohs(header.type));
}

static void	__print_arp_header(struct arp_hdr header)
{
	printf("Address Resolution Protocol (%s)\n", __get_opcode(ntohs(header.opcode)));
	printf("  Hardware type: %s\n", __get_hardware_type(ntohs(header.hardware_type)));
	printf("  Protocol type: %s\n", __get_protocol_type(ntohs(header.protocol_type)));
	printf("  Hardware size: %d\n", header.hardware_len);
	printf("  Protocol size: %d\n", header.protocol_len);
	printf("  Opcode: %s (%d)\n", __get_opcode(ntohs(header.opcode)), ntohs(header.opcode));
	printf("  Sender MAC address: "); print_mac_address(header.sender_hardware); printf("\n");
	printf("  Sender IP address: "); print_ip_address(header.sender_ip); printf("\n");
	printf("  Target MAC address: "); print_mac_address(header.target_hardware); printf("\n");
	printf("  Target IP address: "); print_ip_address(header.target_ip); printf("\n");
}

void	print_ether_arp(struct ether_arp packet)
{
	__print_ethernet_header(packet.ether);
	__print_arp_header(packet.arp);
}

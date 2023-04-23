/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_arp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:57:48 by lucocozz          #+#    #+#             */
/*   Updated: 2023/04/23 17:33:30 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

int	send_arp(int sock, t_cli cli, void (*fill_header)(struct ether_arp*, t_cli))
{
	struct ether_arp	packet;
	struct sockaddr_ll	device = {0};

	fill_header(&packet, cli);
	device.sll_ifindex = if_nametoindex("enp0s3");
	if (sendto(sock, &packet, sizeof(struct ether_arp), 0, (struct sockaddr*)&device, sizeof(device)) < 0) {
		dprintf(STDERR_FILENO, "sendto(): %s\n", strerror(errno));
		return (-1);
	}
	printf("\nSending Packet:\n");
	print_ether_arp(packet);
	
	return (0);
}

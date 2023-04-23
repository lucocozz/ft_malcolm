/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cli.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:44:11 by lucocozz          #+#    #+#             */
/*   Updated: 2023/04/21 19:06:07 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

t_cli	get_cli(int argc, char **argv)
{
	t_cli	cli = {0};

	if (argc != 5) {
		dprintf(STDERR_FILENO, ERR_USAGE);
		exit(EXIT_ERROR);
	}

	if (is_ip_address(argv[1]) == false) {
		dprintf(STDERR_FILENO, "Source IP: %s is not a valid IP address\n", argv[1]);
		exit(EXIT_ERROR);
	}
	cli.sender_ip = argv[1];
	
	if (is_mac_address(argv[2]) == false) {
		dprintf(STDERR_FILENO, "Source MAC: %s is not a valid MAC address\n", argv[2]);
		exit(EXIT_ERROR);
	}
	cli.sender_hardware = argv[2];
	
	if (is_ip_address(argv[3]) == false) {
		dprintf(STDERR_FILENO, "Target IP: %s is not a valid IP address\n", argv[3]);
		exit(EXIT_ERROR);
	}
	cli.target_ip = argv[3];
	
	if (is_mac_address(argv[4]) == false) {
		dprintf(STDERR_FILENO, "Target MAC: %s is not a valid MAC address\n", argv[4]);
		exit(EXIT_ERROR);
	}
	cli.target_hardware = argv[4];

	return (cli);
}

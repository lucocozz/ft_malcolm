/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malcolm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:42:30 by lucocozz          #+#    #+#             */
/*   Updated: 2023/04/25 13:00:47 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALCOLM_H
# define FT_MALCOLM_H

# define _GNU_SOURCE

# include <sys/types.h>
# include <sys/socket.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <arpa/inet.h>
# include <netinet/in.h>
# include <net/if_arp.h>
# include <net/if.h>
# include <linux/if_packet.h>
# include <net/ethernet.h>
# include <netdb.h>
# include <ifaddrs.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>

# include "libft.h"

# define PACKET_SIZE sizeof(struct arphdr) + sizeof(struct ether_header)
# define ETH_ALEN 6
# define MAC_ADDR_LEN 6
# define IP_ADDR_LEN 4
# define BROADCAST_MAC_ADDR "ff:ff:ff:ff:ff:ff"
# define NULL_MAC_ADDR "00:00:00:00:00:00"

# define EXIT_ERROR 2

# define ERR_USAGE "Usage: ./ft_malcolm <source ip> <source mac address> <target ip> <target mac address>\n"

struct ether_hdr {
	u_int8_t	dhost[ETH_ALEN];
	u_int8_t	shost[ETH_ALEN];
	u_int16_t	type;
} __attribute__ ((__packed__));

struct arp_hdr {
	__be16	hardware_type;
	__be16	protocol_type;
	u_char	hardware_len;
	u_char	protocol_len;
	__be16	opcode;
	u_char	sender_hardware[ETH_ALEN];
	u_char	sender_ip[4];
	u_char	target_hardware[ETH_ALEN];
	u_char	target_ip[4];
} __attribute__ ((__packed__));

struct ether_arp {
	struct ether_hdr	ether;
	struct arp_hdr		arp;
} __attribute__ ((__packed__));

typedef struct s_cli {
	char	*sender_hardware;
	char	*sender_ip;
	char	*target_hardware;
	char	*target_ip;
}	t_cli;

extern volatile sig_atomic_t g_running;

/*  ARP  */
int		arp_poisoning(int sock, t_cli cli);
int		send_arp(int sock, t_cli cli, void (*fill_header)(struct ether_arp*, t_cli));
int		recv_arp_type_from_to(int sock, struct ether_arp *packet, int type, const char *from, const char *to);
void	arp_request(struct ether_arp *packet, t_cli cli);
void	arp_reply(struct ether_arp *packet, t_cli cli);
void	poisoned_arp_request(struct ether_arp *packet, t_cli cli);


/*  Cli  */
t_cli	get_cli(int argc, char **argv);


/*  Display  */
void	print_ether_arp(struct ether_arp packet);
void	print_mac_address(u_int8_t* mac_address);
void	print_ip_address(u_int8_t* ip_address);
void	print_arp(struct ether_arp packet);


/*  Network  */
int		mac_str_to_binary(const char *str, unsigned char *binary);
bool	is_mac_address(const char *str);
bool	is_ip_address(const char *str);


/*  Signals  */
void	set_signals(void);

#endif

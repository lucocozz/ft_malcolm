/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malcolm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:42:30 by lucocozz          #+#    #+#             */
/*   Updated: 2023/04/10 18:50:50 by lucocozz         ###   ########.fr       */
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
# include <netdb.h>
# include <ifaddrs.h>
# include <string.h>
# include <stdio.h>

# define ERR_USAGE "Usage: ./ft_malcolm <source ip> <source mac address> <target ip> <target mac address>\n"

#endif

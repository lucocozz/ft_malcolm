/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ip_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:54:32 by lucocozz          #+#    #+#             */
/*   Updated: 2023/04/21 11:57:32 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

void	print_ip_address(u_int8_t* ip_address)
{
	printf("%d.%d.%d.%d",
		ip_address[0], ip_address[1],
		ip_address[2], ip_address[3]);
}

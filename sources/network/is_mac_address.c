/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_mac_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:55:24 by lucocozz          #+#    #+#             */
/*   Updated: 2023/04/21 17:03:26 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

bool	is_mac_address(const char *mac_str)
{
	int	count = 0;
	int	value = 0;
	
	while (*mac_str)
	{
		if (ft_isxdigit(*mac_str)) {
			value = (value << 4) | (ft_isdigit(*mac_str) ? *mac_str - '0' : ft_tolower(*mac_str) - 'a' + 10);
		}
		else if (*mac_str == ':')
		{
			count++;
			if (count == 6)
				return (false);
		    value = 0;
		}
		else
			return (false);
		mac_str++;
	}
	return (count == 5);
}


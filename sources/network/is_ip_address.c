/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ip_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:36:48 by lucocozz          #+#    #+#             */
/*   Updated: 2023/04/23 16:03:56 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

bool	is_ip_address(const char *str)
{
	int	num = 0; 
	int	dots = 0;

	for (int i = 0; str[i]; i++)
	{
		if (ft_isdigit(str[i]))
		{
			num = num * 10 + (str[i] - '0');
			if (num > 255)
				return (false);
		}
		else if (str[i] == '.')
		{
			dots++;
			if (dots > 3)
				return (false);
			num = 0;
		}
		else
			return (false);
	}
	return (dots == 3);
}

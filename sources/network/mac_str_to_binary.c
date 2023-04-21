/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mac_str_to_binary.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:25:40 by lucocozz          #+#    #+#             */
/*   Updated: 2023/04/21 15:33:40 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

static int	__hex_char_to_int(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	else
		return (-1);
}

static int	__parse_hex_byte(const char *str)
{
	int tens = __hex_char_to_int(str[0]);
	int ones = __hex_char_to_int(str[1]);

	if (tens < 0 || ones < 0)
		return (-1);
	return ((tens << 4) | ones);
}

int	mac_str_to_binary(const char *str, unsigned char *binary)
{
	const char *ptr = str;

	for (int i = 0; i < 6; i++)
	{
		int byte = __parse_hex_byte(ptr);
		if (byte < 0)
			return (-1);
		binary[i] = byte;
		ptr += 3;
	}
	return (0);
}

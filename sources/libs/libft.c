/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:58:25 by user42            #+#    #+#             */
/*   Updated: 2023/04/21 13:57:51 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	uint i = 0;

	while ((s1[i] != '\0' && s2[i] != '\0') && s1[i] == s2[i])
		++i;
	return ((u_char)s1[i] - (u_char)s2[i]);
}

uint	ft_strlen(const char *str)
{
	uint	i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

bool	ft_start_with(const char *start_with, const char *str)
{
	uint	i = 0;

	while (start_with[i] != '\0' && str[i] != '\0') {
		if (start_with[i] != str[i])
			return (false);
		++i;
	}
	return (start_with[i] == '\0' ? true : false);
}

static bool	ft_isspace(int c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (true);
	return (false);
}

int	ft_atoi(const char *str)
{
	int		i = 0;
	int		value = 0;
	short	sign = 1;

	while (ft_isspace(str[i]) == true)
		i++;
	if (str[i] == '-' || str[i] == '+') {
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	for (; str[i] >= '0' && str[i] <= '9'; ++i)
		value = value * 10 + (str[i] - '0');
	return (sign * value);
}

long	ft_atol(const char *str)
{
	int		i = 0;
	int		value = 0;
	short	sign = 1;

	while (ft_isspace(str[i]) == true)
		i++;
	if (str[i] == '-' || str[i] == '+') {
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	for (; str[i] >= '0' && str[i] <= '9'; ++i)
		value = value * 10 + (str[i] - '0');
	return (sign * value);
}

float	ft_atof(const char *str)
{
	int		i = 0;
	short	sign = 1;
	int		divisor = 1;
	double	integer = 0;
	double	fraction = 0;
	bool	in_fraction = false;

	while (ft_isspace(str[i]) == true)
		i++;
	if (str[i] == '-' || str[i] == '+') {
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	for (; str[i] != '\0'; ++i)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (in_fraction == true) {
				fraction = fraction * 10 + (str[i] - '0');
				divisor *= 10;
			}
			else
				integer = integer * 10 + (str[i] - '0');
		}
		else if (str[i] == '.')
		{
			if (in_fraction == true)
				return (sign * (integer + fraction / divisor));
			else
				in_fraction = true;
		}
		else
			return (sign * (integer + fraction / divisor));
	}
	return (sign * (integer + fraction / divisor));
}

bool	ft_is_integer(const char *str)
{
	for (uint i = 0; str[i] != '\0'; ++i)
		if (str[i] != '-' && !(str[i] >= '0' && str[i] <= '9'))
			return (false);
	return (true);
}

bool	ft_is_float(const char *str)
{
	for (uint i = 0; str[i] != '\0'; ++i)
		if (str[i] != '-' && !(str[i] >= '0' && str[i] <= '9') && str[i] != '.')
			return (false);
	return (true);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr = s;

	for (uint i = 0; i < n; ++i)
		ptr[i] = 0;
}

double ft_sqrt(double n)
{
	double x = n;
	double y = 1;
	double e = 0.000001;

	while (x - y > e) {
		x = (x + y) / 2;
		y = n / x;
	}
	return (x);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	*ft_memcpy(void *dest, void const *src, size_t n)
{
	char		*d = dest;
	const char	*s = src;

	while (n--)
		*d++ = *s++;
	return (dest);
}

void	ft_memset(void *mem, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)mem;
	for (i = 0; i < n; ++i)
		ptr[i] = c;
}


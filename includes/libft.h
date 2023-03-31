/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:59:06 by user42            #+#    #+#             */
/*   Updated: 2023/03/14 15:58:14 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <sys/types.h>
# include <stdint.h>
# include <stdbool.h>

typedef unsigned char	u_char;
typedef unsigned int	uint;

int		ft_strcmp(const char *s1, const char *s2);
bool	ft_start_with(const char *start_with, const char *str);
uint	ft_strlen(const char *str);
int		ft_atoi(const char *str);
long	ft_atol(const char *str);
float	ft_atof(const char *str);
bool	ft_is_integer(const char *str);
bool	ft_is_float(const char *str);
void	ft_bzero(void *s, size_t n);
double	ft_sqrt(double n);
char	*ft_strcpy(char *dest, char *src);
void	*ft_memcpy(void *dest, void const *src, size_t n);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:43:13 by lucocozz          #+#    #+#             */
/*   Updated: 2023/03/31 21:22:08 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 5) {
		dprintf(STDERR_FILENO, ERR_USAGE);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

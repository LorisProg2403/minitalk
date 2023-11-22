/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:24:18 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/22 15:49:56 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	main(int ac, char **av)
{
	int		n_bits;
	char	c;

	if (ac != 3 || !ft_atoi(av[1]))
		handle_errors("Incorrect arguments");
	while (*av[2])
	{
		c = *av[2];
		n_bits = 8;
		while (n_bits--)
		{
			if (c & 0b10000000)
				kill(ft_atoi(av[1]), SIGUSR1);
			else
				kill(ft_atoi(av[1]), SIGUSR2);
			usleep(10);
			c <<= 1;
		}
		av[2]++;
	}
	return (0);
}

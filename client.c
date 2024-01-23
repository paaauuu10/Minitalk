/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:42:28 by pbotargu          #+#    #+#             */
/*   Updated: 2024/01/23 12:31:16 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "./libft/libft.h"

void	ft_error(void)
{
	printf("Error sending the bit to the server\n"); /*fakeone*/
	exit(EXIT_FAILURE);
}

void	ft_send_signal(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error();
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_error();
		}
		bit--;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			ft_send_signal(pid, argv[2][i]);
			i++;
		}
		ft_send_signal(pid, '\n');
	}
	else
	{
		printf("Wrong format");/*fakeone*/
		printf("Correct format: ./client <PID> <MESSAGE>");/*fakeone*/
	}
	return (0);
}

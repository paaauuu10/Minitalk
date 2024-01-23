/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:50:52 by pbotargu          #+#    #+#             */
/*   Updated: 2024/01/23 12:25:33 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int	g_bit[8];

void	ft_print_byte(void)
{
	int	res;
	int	j;
	int	k;

	res = 0;
	j = 0;
	k = 128;
	while (j < 8)
	{
		res += g_bit[j] * k;
		k = k / 2;
		j++;
	}
	printf("%c", res);/*fakeone*/
	fflush(stdout);/*delete*/
}

void	ft_receive(int signal)
{
	static int	i = 0;

	if (signal == SIGUSR1)
	{
		g_bit[i] = 1;
		i++;
	}
	else if (signal == SIGUSR2)
	{
		g_bit[i] = 0;
		i++;
	}
	if (i == 8)
	{
		ft_print_byte();
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	argv = 0;
	if (argc != 1)
	{
		printf("Wrong format\n");/*fakeone*/
		printf("Correct one: ./server\n");/*fakeone*/
		return (0);
	}
	printf("Initated server\n"); /*pasar a funcio propia printf*/
	printf("PID's server is: %d\n", getpid()); /*pasar a funcio propia printf*/
	printf("Waiting signal...\n");/*fakeone*/
	while (argc == 1)
	{
		signal(SIGUSR1, ft_receive);
		signal(SIGUSR2, ft_receive);
		pause();
	}
	return (0);
}

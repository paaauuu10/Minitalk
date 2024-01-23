/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:50:52 by pbotargu          #+#    #+#             */
/*   Updated: 2024/01/23 16:42:48 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int	g_bit[8];

void	ft_putchar(char z)
{
	write(1, &z, 1);
}

void	ft_putnbr(int number)
{
	if (number > 9)
	{
		ft_putnbr(number / 10);
		number = number % 10;
	}
	if (number <= 9)
		ft_putchar('0' + number);
}

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
	ft_putchar(res);
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
		write(1, "Wrong format\n", 13);
		write(1, "Correct one: ./server\n", 22);
		return (0);
	}
	write(1, "Initiated server\n", 17);
	write(1, "PID's server is: ", 18);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	write(1, "Waiting signal...\n", 18);
	while (argc == 1)
	{
		signal(SIGUSR1, ft_receive);
		signal(SIGUSR2, ft_receive);
		pause();
	}
	return (0);
}

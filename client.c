/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:42:28 by pbotargu          #+#    #+#             */
/*   Updated: 2024/01/23 16:36:50 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	ft_error(void)
{
	write(1, "Error sending the bit to the server\n", 36);
	exit(EXIT_FAILURE);
}

int	ft_atoi(const char *str)
{
	int				i;
	long long int	result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
		if (result > 2147483647)
			return (-1);
	}
	return (result);
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
		write(1, "Wrong format!\n", 14);
		write(1, "Correct format: ./client <PID> <MESSAGE>\n", 41);
	}
	return (0);
}

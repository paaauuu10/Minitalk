/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:50:52 by pbotargu          #+#    #+#             */
/*   Updated: 2024/01/22 17:11:25 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int bit[8];

/*void	ft_print_byte(void)
{
    int	res;
    int j;
    int k;

    res = 0;
    j = 0;
    k = 128;

    while(j < 8)
    {
        res += bit[j] * k;
        k = k / 2;
        j++;
    }
    printf("%d\n", res); 
    printf("%c", res);
}*/ 

void ft_print_byte(void)
{
    int res;

    res = bit[0] * 128 + bit[1] * 64 + bit[2] * 32
        + bit[3] * 16 + bit[4] * 8 + bit[5] * 4 + bit[6] * 2 + bit[7];
    printf("%d\n", res);
    printf("%c\n", res);
}


void ft_receive(int signal)
{
    static int i = 0; 
    
    
    if (signal == SIGUSR1)
    {
        bit[i] = 0;
        i++;
    }
    if (signal == SIGUSR2)
    {
        bit[i] = 1;
        i++;
    }
    if (i == 8)
    {
        ft_print_byte();
        i = 0;
    }
}

int main(int argc, char **argv)
{
	argv = 0;
    if (argc != 1)
    {
        printf("Wrong format\n");
        printf("Correct one: ./server\n");
        return (0);
    }
    printf("Initated server\n"); /*pasar a funcio propia printf*/
    printf("PID's server is: %d\n", getpid()); /*pasar a funcio propia printf*/
    printf("Waiting signal...\n");
    while(1)
	{
		signal(SIGUSR1, ft_receive);
		signal(SIGUSR2, ft_receive);
		pause();
	}
	return (0);
}

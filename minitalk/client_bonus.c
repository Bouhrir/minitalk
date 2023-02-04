/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 22:43:41 by obouhrir          #+#    #+#             */
/*   Updated: 2023/01/25 13:37:01 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	printf_pid_eroor(void)
{
	write (1, "Process ID not available", 24);
	exit(1);
}

void	send_chars(char *pid, int c)
{
	int	tab[8];
	int	i;
	int	p;

	ft_memset(tab, 0, 8);
	i = 0;
	while (c)
	{
		tab[i] = (c % 2);
		c /= 2;
		i++;
	}
	p = ft_atoi(pid);
	if (p == 0 || p == 1 || p == -1)
		printf_pid_eroor();
	i = 7;
	while (i >= 0)
	{
		if (tab[i] == 0)
			kill(p, SIGUSR1);
		else if (tab[i] == 1)
			kill(p, SIGUSR2);
		usleep(100);
		i--;
	}
}

void	received(int sig)
{
	sig = 30;
	write(1, "succes\n", 7);
}

int	main(int ac, char **av)
{
	int	i;

	signal(SIGUSR1, received);
	i = 0;
	if (ac == 3)
	{
		while (av[2][i])
		{
			send_chars(av[1], (unsigned char)av[2][i]);
			i++;
		}
	}
	return (0);
}

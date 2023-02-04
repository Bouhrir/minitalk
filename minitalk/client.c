/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:45:33 by obouhrir          #+#    #+#             */
/*   Updated: 2023/01/25 13:36:09 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

int	main(int ac, char **av)
{
	int					i;

	i = 0;
	if (ac == 3)
	{
		while (av[2][i])
		{
			send_chars(av[1], av[2][i]);
			i++;
		}
	}
	return (0);
}

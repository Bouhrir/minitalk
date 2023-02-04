/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:45:22 by obouhrir          #+#    #+#             */
/*   Updated: 2023/01/25 13:20:00 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	convert_to_decimal(int *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < 8)
	{
		res = res * 2 + (str[i]);
		i++;
	}
	ft_putchar(res);
}

void	handler(int sig, siginfo_t *infon, void *uap)
{
	int				str[8];
	static int		i;
	static int		pid_cc;

	(void)uap;
	if (infon->si_pid != pid_cc)
	{
		pid_cc = infon->si_pid;
		i = 0;
	}
	if (sig == SIGUSR1)
		str[i++] = 0;
	else if (sig == SIGUSR2)
		str[i++] = 1;
	if (i == 8)
	{
		convert_to_decimal(str);
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	if (pid == 0 || pid == 1 || pid == -1)
	{
		write (1, "Process ID not available", 24);
		exit(1);
	}
	else
		putnbr(pid);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		;
	return (0);
}

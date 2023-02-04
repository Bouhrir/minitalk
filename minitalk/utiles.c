/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:45:04 by obouhrir          #+#    #+#             */
/*   Updated: 2023/01/22 12:08:57 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char	*str)
{
	int	i;
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	else if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (sign * res);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	putnbr(int nbr)
{
	if (nbr >= 0 && nbr <= 9)
	{
		ft_putchar(nbr + '0');
	}
	if (nbr >= 10)
	{
		putnbr(nbr / 10);
		putnbr(nbr % 10);
	}
}

void	*ft_memset(void	*b, int c, int len)
{
	int	*str;
	int	i;

	str = (int *) b;
	i = 0;
	while (i < len)
		str[i++] = (int)c;
	return (str);
}

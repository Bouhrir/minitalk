/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:33:02 by obouhrir          #+#    #+#             */
/*   Updated: 2023/01/25 12:22:30 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

int		ft_atoi(char	*str);
void	putnbr(int nbr);
void	ft_putchar(char c);
void	*ft_memset(void	*b, int c, int len);

#endif

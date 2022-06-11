/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:07:53 by ssadiki           #+#    #+#             */
/*   Updated: 2022/06/07 22:58:39 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

void	ft_putnbr(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}

int	ft_atoi(const char *str)
{
	size_t		s;
	size_t		i;
	size_t		nb;

	i = -1;
	s = 1;
	nb = 0;
	if (str[++i] == '-')
			s *= -1;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		nb *= 10;
		nb += str[i] - 48;
		if (str[i + 1] < '0' || str[i + 1] > '9')
			break ;
		i++;
	}
	return ((int) s * nb);
}

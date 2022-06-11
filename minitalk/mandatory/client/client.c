/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 12:08:44 by ssadiki           #+#    #+#             */
/*   Updated: 2022/06/10 15:53:40 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

char	g_count = 8;

void	send_signal(int bit, int s_pid)
{
	if (bit == 0)
	{
		if (kill(s_pid, SIGUSR1) == -1)
		{
			ft_putstr("Error in SIGUSR1!\n");
			exit(1);
		}
	}
	else
	{
		if (kill(s_pid, SIGUSR2) == -1)
		{
			ft_putstr("Error in SIGUSR2!\n");
			exit(1);
		}
	}
}

void	client(int s_pid, char c)
{
	while (--g_count >= 0)
	{
		if ((c >> g_count) & 1)
			send_signal(1, s_pid);
		else
			send_signal(0, s_pid);
		usleep(800);
	}
}

int	is_num(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 3)
	{
		ft_putstr("Invalid number of arguments!");
		exit(1);
	}
	else
	{
		if (!(is_num(argv[1])) || ft_atoi(argv[1]) <= 0)
		{
			ft_putstr("Error in server PID!\n");
			return (0);
		}
		i = -1;
		while (argv[2][++i])
		{
			client (ft_atoi(argv[1]), argv[2][i]);
			g_count = 8;
		}
	}
	return (0);
}

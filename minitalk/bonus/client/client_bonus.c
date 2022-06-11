/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 12:08:44 by ssadiki           #+#    #+#             */
/*   Updated: 2022/06/10 15:55:39 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_bonus.h"

void	confirm(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr("Your message has been received :>", 0);
}

void	client(int s_pid, char c)
{
	static int	g_count = 8;

	while (--g_count >= 0)
	{
		if ((c >> g_count) & 1)
		{
			if (kill(s_pid, SIGUSR2) == -1)
				ft_putstr("Error in SIGUSR2!\n", 1);
		}
		else
		{
			if (kill(s_pid, SIGUSR1) == -1)
				ft_putstr("Error in SIGUSR1!\n", 1);
		}
		signal(SIGUSR1, confirm);
		usleep(800);
	}
	g_count = 8;
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 3)
		ft_putstr("Invalid number of arguments!", 1);
	else
	{
		if (!(is_num(argv[1])) || ft_atoi(argv[1]) <= 0)
			ft_putstr("Error in server PID!\n", 1);
		i = -1;
		while (argv[2][++i])
			client (ft_atoi(argv[1]), argv[2][i]);
		client (ft_atoi(argv[1]), argv[2][i]);
	}
	return (0);
}

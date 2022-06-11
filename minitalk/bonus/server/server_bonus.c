/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 12:07:56 by ssadiki           #+#    #+#             */
/*   Updated: 2022/06/10 10:56:27 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_bonus.h"

//int	test;

void	handle(int sig, siginfo_t *info, void *uap)
{
	static int	count = 7;
	static char	c;
	static int	c_pid = 0;

	uap = NULL;
	if (c_pid != info->si_pid)
	{
		c = '\0';
		count = 7;
		c_pid = info->si_pid;
	}
	if (sig == 30)
		c = c | (0 << count--);
	else
		c = c | (1 << count--);
	if (count < 0)
	{
		write(1, &c, 1);
		if (c == '\0')
			if (kill(c_pid, SIGUSR1) == -1)
				ft_putstr("Error while confirming message to client!\n", 1);
		c = '\0';
		count = 7;
	}
}

int	main(void)
{
	int					s_pid;
	struct sigaction	new_act;

	s_pid = getpid();
	ft_putstr("Server PID: ", 0);
	ft_putnbr(s_pid);
	write(1, "\n", 1);
	new_act.sa_flags = SA_SIGINFO;
	new_act.sa_sigaction = handle;
	sigaction(SIGUSR1, &new_act, NULL);
	sigaction(SIGUSR2, &new_act, NULL);
	while (1)
		pause();
}

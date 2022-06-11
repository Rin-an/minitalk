/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 12:07:10 by ssadiki           #+#    #+#             */
/*   Updated: 2022/06/10 10:54:53 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

void	client(int s_pid, char bit);
void	server(void);
int		ft_atoi(const char *str);
void	ft_putnbr(int nbr);
void	ft_putchar(char c);
void	ft_putstr(char *str, int flag);
int		is_num(char *str);
#endif

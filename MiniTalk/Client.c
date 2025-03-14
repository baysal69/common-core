/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:43:57 by waissi            #+#    #+#             */
/*   Updated: 2025/03/14 01:50:41 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/ft_printf.h"
#include "./libft/libft.h"
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

volatile int	g_ack_received;

void	ack_handler(int signum)
{
	(void)signum;
	g_ack_received = 1;
}

void	send_signal(int pid, int bit)
{
	g_ack_received = 0;
	if (bit == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	while (!g_ack_received)
		usleep(100);
}

void	send_message(int pid, char *message)
{
	int	i;
	int	j;

	i = 0;
	while (message[i])
	{
		j = 7;
		while (j >= 0)
		{
			send_signal(pid, (message[i] >> j) & 1);
			j--;
		}
		i++;
	}
	j = 7;
	while (j >= 0)
	{
		send_signal(pid, 0);
		j--;
	}
}

int	main(int argc, char *argv[])
{
	int					pid;
	struct sigaction	sa;

	if (argc != 3)
		ft_printf("Usage: ./Client [PID] [Message]\n");
	pid = ft_atoi(argv[1]);
	sa.sa_flags = 0;
	sa.sa_handler = ack_handler;
	sigaction(SIGUSR1, &sa, NULL);
	send_message(pid, argv[2]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:43:57 by waissi            #+#    #+#             */
/*   Updated: 2025/03/23 17:00:58 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

volatile int	g_ack_received;

void	ack_handler(int signum)
{
	(void)signum;
	if (signum == SIGUSR1)
		g_ack_received = 1;
}

void	send_signal(int pid, int bit)
{
	g_ack_received = 0;
	if (bit == 0)
	{
		if (kill(pid, SIGUSR1) < 0)
		{
			ft_printf("Inputted PID is invalid: No such process\n");
			exit(1);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) < 0)
		{
			ft_printf("Inputted PID is invalid: No such process\n");
			exit(1);
		}
	}
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
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	send_message(pid, argv[2]);
}

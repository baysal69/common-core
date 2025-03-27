/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:43:57 by waissi            #+#    #+#             */
/*   Updated: 2025/03/27 03:00:24 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

int	g_ack_received;

void ft_error(int code)
{
	if (code == 1)
	{
		ft_printf("\033[31mMessage interrupted: Something is wrong\033[0m\n");
		exit(0);
	}
	else if (code == 2)
	{
		ft_printf("\033[31mInputted PID is invalid: No such process\033[0m\n");
		exit(0);
	}
	else if (code == 3)
	{
		ft_printf("Usage: ./Client [PID] [Message]\n");
		exit(0);
	}
}

void	ack_handler(int signum)
{
	(void)signum;
	if (signum == SIGUSR1)
		g_ack_received = 1;
}

int	send_signal(int pid, int bit)
{
	g_ack_received = 0;
	if (bit == 0)
	{
		if (kill(pid, SIGUSR1) < 0)
			ft_error(2);
	}
	else
	{
		if (kill(pid, SIGUSR2) < 0)
			ft_error(2);
	}
	while (!g_ack_received)
	{
		if (kill(pid,0) == -1)
			ft_error(1);
	}
	return 1;
}

void	send_message(int pid, char *message)
{
	int	i;
	int	j;
	int	done;

	i = 0;
	done = 0;
	while (message[i])
	{
		j = 7;
		while (j >= 0)
		{
			done = send_signal(pid, (message[i] >> j) & 1);
			j--;
		}
		i++;
	}
	if (done == 1)
		ft_printf("\033[32mMessage sent successfully!\033[0m\n");
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
		ft_error(3);
	if (argv[1][0] < '0' || argv[1][0] > '9')
		exit(0);
	pid = ft_atoi(argv[1]);
	if (pid < 0)
		exit(0);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_handler = ack_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	send_message(pid, argv[2]);
}

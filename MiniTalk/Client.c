/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 00:25:35 by waissi            #+#    #+#             */
/*   Updated: 2025/03/12 00:28:52 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	send_signal(int pid, int bit)
{
	if (bit == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(150);
}

void	send_message(int pid, char *message)
{
	int	i;
	int	j;
	int	bit;
	int	bit;

	i = 0;
	j = 7;
	while (message[i] != '\0')
	{
		while (j >= 0)
		{
			bit = (message[i] >> j) & 1;
			send_signal(pid, bit);
			j--;
		}
		i++;
		j = 7;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		send_message(pid, argv[2]);
	}
	else
	{
		ft_printf("Unknow option for Client\n");
		ft_printf("Usage: ./Client [pid] [message]\n");
	}
}

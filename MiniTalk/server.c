/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 00:24:49 by waissi            #+#    #+#             */
/*   Updated: 2025/03/16 03:00:51 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/ft_printf.h"
#include "./libft/libft.h"
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	g_current_client;

void	text(int signum, siginfo_t *info, void *context)
{
	static int	i;
	static char	character;

	(void)context;
	if (g_current_client != info->si_pid)
	{
		i = 0;
		character = 0;
		g_current_client = info->si_pid;
	}
	if (signum == SIGUSR1)
		character = (character << 1) | 0;
	else if (signum == SIGUSR2)
		character = (character << 1) | 1;
	i++;
	if (i == 8)
	{
		if (character == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", character);
		i = 0;
		character = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sa.sa_sigaction = text;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("The server PID is: %d\n", getpid());
	while (1)
		pause();
}

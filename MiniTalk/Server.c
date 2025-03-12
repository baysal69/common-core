/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 00:24:49 by waissi            #+#    #+#             */
/*   Updated: 2025/03/12 00:24:57 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	text(int signum)
{
	static int	i;
	char		character;
	int			gotten_bit;

	i = 0;
	if (signum == SIGUSR1)
		gotten_bit = 0;
	else if (signum == SIGUSR2)
		gotten_bit = 1;
	character = (character << 1) | gotten_bit;
	i++;
	if (i == 8)
	{
		ft_printf("%c", character);
		character = 0;
		i = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	signal(SIGUSR1, text);
	signal(SIGUSR2, text);
	ft_printf("The server PID is : %d\n", PID);
	ft_printf("To connect to this server follow this syntax.\n");
	ft_printf("./client [PID] [Message]\n ");
	while (1)
	{
		pause();
	}
}

#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"
#include <signal.h>

extern char *message;

int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		int PID = ft_atoi(argv[1]);
		message = malloc(sizeof(char) * (ft_strlen(argv[2]) + 1));
		ft_strcpy(message ,argv[2]);
		kill(PID,SIGUSR1);
	}
	else{}
}

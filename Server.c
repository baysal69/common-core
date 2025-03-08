#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"
char *message;
void text()
{
	ft_printf("%s",message);
}

int main()
{
	int PID = getpid();
	signal(SIGUSR1,text);
	ft_printf("The server PID is : %d\n", PID);
	ft_printf("To connect to this server follow this syntax.\n./client [PID] [Message]\n ");
	while(1)
	{
	}



}

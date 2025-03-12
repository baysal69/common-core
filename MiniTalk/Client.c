#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"
#include <signal.h>
extern char *message = NULL;

void send_signal(int PID, int bit)
{
	if (bit == 0)
		kill(PID,SIGUSR1);
	else
		kill(PID,SIGUSR2);
	usleep(150);
}

void send_message(int PID, char *message)
{
	int i = 0;
	int j = 7;
	while(message[i] != '\0')
	{
		while(j >= 0)
		{
			int bit = (message[i] >> j) & 1;
			send_signal(PID,bit);
			j--;
		}
		i++;
		j=7;
	
	}
	/*(j = 7;
	while (j >= 0)
    	{
        	int bit = ('\0' >> j) & 1;
        	send_signal(PID, bit);
        	j--;
	}*/

}
int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		int PID = ft_atoi(argv[1]);
		send_message(PID,argv[2]);
	}
	else
		ft_printf("Unknow option for Client\n Usage: ./Client [PID] [message]\n");
}

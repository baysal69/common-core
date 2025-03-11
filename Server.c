#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"
void text(int signum)
{
	int i = 0;
	char character;
	int gotten_bit;
	if(signum == SIGUSR1)
		gotten_bit = 0;
	else if (signum == SIGUSR2)
		gotten_bit = 1;
	character = (character << 1) | gotten_bit;
       	i++;
	ft_printf("Received bit: %d, current character: %c (%d), bit count: %d\n",
              gotten_bit, character, character, i);
	if(i == 8)
	{
		ft_printf("%c",character);
		character = 0;
		i = 0;
	}	
}

int main()
{
	int PID = getpid();
	signal(SIGUSR1,text);
	signal(SIGUSR2,text);
	ft_printf("The server PID is : %d\n", PID);
	ft_printf("To connect to this server follow this syntax.\n./client [PID] [Message]\n ");
	while(1)
	{
		pause();
	}



}

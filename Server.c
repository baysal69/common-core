#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"
#include "message.h"
char *message;
void text()
{
	 if (message != NULL) {
        printf("Server received: %s\n", message);
    } else {
        printf("Server received: (NULL)\n");
    }
}

int main()
{
	int PID = getpid();
	signal(SIGUSR1,text);
	ft_printf("The server PID is : %d\n", PID);
	ft_printf("To connect to this server follow this syntax.\n./client [PID] [Message]\n ");
	while(1)
	{
		pause();
	}



}

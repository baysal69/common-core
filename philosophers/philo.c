#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

pthread_mutex_t lock;
volatile int is_locked = 0;

int checkarg(char *str)
{
	int i = 0;
	while(str[i] == ' ')
			i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return 0;
		i++;
	}
	return 1;
}

void error(int code)
{
	if (code == 1)
	{
		printf("Invalid arguments\n Please refer to ./philo -h\n");
		exit(1);
	}
	else if (code == 2)
	{
		printf ("Invalid arguments content\n");
		exit(1);
	}
}
int check_args(int ac, char *av[])
{
	int i = 1, nb;
	if (ac < 5 || ac > 6)
		error(1);
	while (i < ac)
	{
		if(!checkarg(av[i]))
			error(2);
		i++;
	}
	i = 1;
	while (i < ac)
	{
		nb = atoi(av[i]);
		if (!nb || nb < INT_MIN || nb > INT_MAX)
			error(2);
	}
	return 1;

}


void *sleeping();
void *thinking(void)
{
	pthread_mutex_lock(&lock);
		printf("thinking...\n");
		usleep(1100);
	pthread_mutex_unlock(&lock);
	return NULL;
}

void *sleeping()
{
		pthread_mutex_lock(&lock);
		printf("sleeping...\n");
		usleep(100000);
		pthread_mutex_unlock(&lock);
	return NULL;
}

size_t gettime()
{
	typedef struct timeval		t_timeval;
	t_timeval tv;
	gettimeofday(&tv,NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int main(int ac,char *av[])
{
	if (ac >= 2)
	{
		check_args(ac,av);
		int philos = atoi(av[1]);
		int i = 0, f = 0;
		pthread_t *threads;
	       	threads	= malloc (philos * sizeof(pthread_t));
		pthread_mutex_init(&lock,NULL);
		while (i < philos)
		{
			pthread_create(&threads[i],NULL,(void *)sleeping,NULL);
			i++;
		}
		i = 0;
		while (i < philos)
		{
			pthread_join(threads[i],NULL);
			i++;
		}
	}
}

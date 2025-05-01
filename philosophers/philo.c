#include "philo.h"

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
	else if (code == 3)
	{
		printf("Invalid number of meals\n");
		exit(1);
	}
	else if (code == 4)
	{
		printf("Mutex initialization failed\n");
		exit(1);
	}
}

void init_mtx(t_lock *f, t_lock *m, t_content *curr)
{
	int i = 0;
	if (pthread_mutex_init(&curr->print, NULL))
		error(4);
	if (pthread_mutex_init(&curr->death_lock, NULL))
		error(4);
	while(i < curr->nphilos)
	{
		if (pthread_mutex_init(&f[i],NULL))
			error(4);
		if (pthread_mutex_init(&m[i],NULL))
			error(4);
		i++;
	}
}

size_t get_time()
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
		t_lock f[200];
		t_lock m[200];
		t_lock p[200];
		t_content curr;
		check_args(ac,av);
		give_params(&curr,ac,av);
		init_mtx(f,m,&curr);
		int philos = ft_atoi(av[1]);
		int i = 0;
		pthread_t *threads;
	       	threads	= malloc (philos * sizeof(pthread_t));
		// pthread_mutex_init(&lock,NULL);
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

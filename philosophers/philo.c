#include "philo.h"

int check_full(t_pstats *p, t_content *curr)
{
	int i = 0;
	while( i < curr->nphilos)
	{
		pthread_mutex_lock(p[i].meal_lock);
		if (p[i].full == 1)
		{
			curr->full++;
			p[i].full = 0;
		}
		pthread_mutex_unlock(p[i].meal_lock);
		if (curr->full == curr->nphilos)
		{
			pthread_mutex_lock(&curr->death_lock);
			curr->death = 1;
			pthread_mutex_unlock(&curr->death_lock);
			return 1;
		}
		i++;
	}
	return 0;
}

void *monitoring(void *arg)
{
	t_pstats *p;
	t_content *in;
	int p_death = 0;
	p = (t_pstats *)arg;
	in = p->in;
	while (alive(p->in))
	{
		
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
		t_pstats p[200];
		t_content curr;
		check_args(ac,av);
		give_params(&curr,ac,av);
		init_mtx(f,m,&curr);
		give_philos(p,m,&curr,f);
		int i = 0;
		// while (i < philos)
		// {
		// 	pthread_join(threads[i],NULL);
		// 	i++;
		// }
	}
}

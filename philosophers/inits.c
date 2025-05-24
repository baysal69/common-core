#include "philo.h"

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

int init_thrds(t_pstats *p, t_content *curr)
{
	int i = 0;
	if (pthread_create(&curr->monitor,NULL,monitoring,p))
		error(5);
	while (i < curr->nphilos)
	{
		if (pthread_create(&p[i].thread, NULL, routine, &p[i]))
			error(5);
		i++;
	}
	return 1;
}
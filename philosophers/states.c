#include "philo.h"

void *thinking()
{
	// pthread_mutex_lock(&lock);
	printf("thinking...\n");
	ft_usleep(1100);
	// pthread_mutex_unlock(&lock);
	return NULL;
}

void *sleeping()
{
	// pthread_mutex_lock(&lock);
	printf("sleeping...\n");
	ft_usleep(1000);
	// pthread_mutex_unlock(&lock);
	return NULL;
}

int is_alive (t_content *curr)
{
	pthread_mutex_lock(&curr->death_lock);
	if (curr->death == 1)
		return (pthread_mutex_unlock(&curr->death_lock), 0);
	pthread_mutex_unlock(&curr->death_lock);
	return 1;
}

void *routine(void *arg)
{
 t_pstats *p = (t_pstats *)arg;
 t_content *curr = p->in;

 if (curr->nphilos == 1)
 {
  printf("Philosopher %d died of loneliness\n", p->id);
  ft_usleep(curr->tdie);
  return NULL;
 }
 if (p->id % 2 == 0)
  ft_usleep(curr->tthink * 1000);
 while (is_alive(curr))
 {
 
 }
 return NULL;
}

#include "philo.h"

void *thinking()
{
	// pthread_mutex_lock(&lock);
	printf("thinking...\n");
	usleep(1100);
	// pthread_mutex_unlock(&lock);
	return NULL;
}

void *sleeping()
{
	// pthread_mutex_lock(&lock);
	printf("sleeping...\n");
	usleep(1000);
	// pthread_mutex_unlock(&lock);
	return NULL;
}

int alive (t_content *curr)
{
	pthread_mutex_lock(&curr->death_lock);
	if (curr->death == 1)
		return (pthread_mutex_unlock(&curr->death_lock), 0);
	pthread_mutex_unlock(&curr->death_lock);
	return 1;
}

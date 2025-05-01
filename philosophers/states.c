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

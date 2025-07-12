#include "philo.h"

void thinking(t_pstats *p)
{
	put_message("thinking...\n", p);
	ft_usleep(5);
}

void sleeping(t_pstats *p)
{
	put_message("sleeping...\n",p);
	ft_usleep(p->in->tsleep);
}

int eating(t_pstats *p)
{
	f_lock(p);
	meal_update(p);
	put_message("started eating", p);
	ft_usleep(p->in->teat);
	pthread_mutex_lock(p->meal_lock);
	p->eating = 0;
	pthread_mutex_unlock(p->meal_lock);
	pthread_mutex_unlock(p->rfork);
	pthread_mutex_unlock(p->lfork);
	if (p->in->counter[p->id] == p->in->nmeals)
	{
		pthread_mutex_lock(p->meal_lock);
		p->full = 1;
		return (pthread_mutex_unlock(p->meal_lock), 1);
	}
	return 0;
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
	if (eating(p))
		break;
	sleeping(p);
	thinking(p);
 }
 return NULL;
}

void f_lock(t_pstats *p)
{
	if(p->lfork < p->rfork)
	{
		pthread_mutex_lock(p->lfork);
		put_message("has taken the left fork",p);
		pthread_mutex_lock(p->rfork);
		put_message("has taken the right fork",p);
	}
	else
	{
		pthread_mutex_lock(p->rfork);
		put_message("has taken the right fork",p);
		pthread_mutex_lock(p->lfork);
		put_message("has taken the left fork",p);
	}
}

void meal_update(t_pstats *p)
{
	pthread_mutex_lock(p->meal_lock);
	p->lastmeal = get_time();
	p->eating = 1;
	p->in->counter[p->id]++;
	pthread_mutex_unlock(p->meal_lock);
}

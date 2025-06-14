#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <limits.h>

typedef pthread_mutex_t t_lock;

typedef struct timeval		t_timeval;
typedef struct s_content
{
	pthread_t monitor;
	size_t teat;
	size_t tsleep;
	size_t tdie;
	int counter[250];
	int nphilos;
	int nmeals;
	int death;
	int full;
	size_t start;
	int tthink;
	pthread_mutex_t death_lock;
	pthread_mutex_t print;
} t_content;

typedef struct s_pstats
{
	pthread_t thread;
	int id;
	int eating;
	int full;
	int turn;
	size_t lastmeal;
	int tthink;
	t_content *in;
	pthread_mutex_t *meal_lock;
	pthread_mutex_t *lfork;
	pthread_mutex_t *rfork;
}	t_pstats;

void give_philos(t_pstats *p, t_lock *m, t_content *curr, t_lock *f );
int init_thrds(t_pstats *p, t_content *curr);
long    ft_atoi(const char *str);
size_t get_time();
void *sleeping();
void *thinking();
void init_mtx(t_lock *f, t_lock *m, t_content *curr);
void give_params(t_content *it, int ac, char **av);
size_t get_time();
int checkarg(char *str);
void error(int code);
int check_args(int ac, char *av[]);
int end_death(t_pstats *p, t_content *curr);
int is_alive(t_content *curr);
int check_full(t_pstats *p, t_content *curr);
void *monitoring(void *arg);
void *routine(void *arg);
void ft_usleep(size_t ms);









#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:11:00 by waissi            #+#    #+#             */
/*   Updated: 2025/08/10 19:17:18 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define RED "\033[1;31m"
# define RESET "\033[0m"

typedef pthread_mutex_t	t_lock;
typedef struct timeval	t_timeval;

typedef struct s_content
{
	int					counter[250];
	int					full;
	int					death;
	int					nmeals;
	int					tthink;
	int					nphilos;
	size_t				teat;
	size_t				tdie;
	size_t				tsleep;
	size_t				start;
	pthread_t			monitor;
	pthread_mutex_t		print;
	pthread_mutex_t		death_lock;
}						t_content;

typedef struct s_pstats
{
	int					id;
	int					full;
	int					eating;
	pthread_mutex_t		*rfork;
	pthread_mutex_t		*lfork;
	pthread_mutex_t		*meal_lock;
	t_content			*in;
	size_t				lastmeal;
	pthread_t			philo;
}						t_pstats;

int						ft_parse(t_pstats **p, pthread_mutex_t **forks,
							t_content curr);
int						error(int code);
int						checkarg(char *str);
int						check_args(int ac, char **av);

void					f_lock(t_pstats *p);
void					put_dead(t_content *curr, int i);
void					put_message(char *s, t_pstats *p);

void					*monitoring(void *arg);
void					*routine(void *arg);
int						eating(t_pstats *p);
void					thinking(t_pstats *p);
void					sleeping(t_pstats *p);

long long				get_time(void);
void					ft_usleep(long long ms);
long					ft_atoi(const char *str);
int						is_alive(t_content *curr);
void					*is_one(t_pstats *p, size_t tdie);
int						end_death(t_pstats *p, t_content *curr);
void					clean_up(t_pstats *p, t_lock *forks);

void					meal_update(t_pstats *p);
int						check_full(t_pstats *p, t_content *curr);

int						init_thrds(t_content *curr, t_pstats *p);
void					init_content(t_content *it, int ac, char **av);
int						init_pstats(t_pstats *p, t_content *curr,
							t_lock *forks);
void					philo_born(t_pstats *p, int *nphilos, size_t *tdie,
							size_t *teat);

#endif

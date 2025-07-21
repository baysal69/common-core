/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:11:00 by sel-khao          #+#    #+#             */
/*   Updated: 2025/07/14 09:11:00 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

# define RED "\033[1;31m"
# define RESET "\033[0m"

typedef pthread_mutex_t		t_lock;
typedef struct timeval		t_timeval;

typedef struct s_content
{
	int				counter[250];
	int				full;
	int				death;
	int				nmeals;
	int				tthink;
	int				nphilos;
	size_t			teat;
	size_t			tdie;
	size_t			tsleep;
	size_t			start;
	pthread_t		monitor;
	pthread_mutex_t	print;
	pthread_mutex_t	death_lock;
}	t_content;

typedef struct s_pstats
{
	int				id;
	int				full;
	int				turn;
	int				eating;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*meal_lock;
	t_content		*in;
	size_t			lastmeal;
	pthread_t		philo;
}	t_pstats;

void		error(int code);
int			checkarg(char *str);
int			check_args(int ac, char **av);

void		f_lock(t_pstats *p);
void		put_dead(t_content *curr, int i);
void		put_message(char *s, t_pstats *p);

void		*monitoring(void *arg);
void		*routine(void *arg);
int			eating(t_pstats *p);
void		thinking(t_pstats *p);
void		sleeping(t_pstats *p);

long long	get_time(void);
void		ft_usleep(long long ms);
long		ft_atoi(const char *str);
void		put_time(t_content curr);
int			is_alive(t_content *curr);
void		*is_one(t_pstats *p, size_t tdie);
int			end_death(t_pstats *p, t_content *curr);
void		clean_up(t_pstats *p, t_lock *forks);

void		meal_update(t_pstats *p);
int			check_full(t_pstats *p, t_content *curr);

void		init_thrds(t_content *curr, t_pstats *p);
void		init_content(t_content *it, int ac, char **av);
void		init_pstats(t_pstats *p, t_content *curr, t_lock *forks);
void		philo_born(t_pstats *p, int *nphilos, size_t *tdie, size_t *teat);

#endif

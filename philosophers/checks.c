#include "philo.h"

int check_args(int ac, char *av[])
{
	int	i = 1;
	long	nb = 0;
	if (ac < 5 || ac > 6)
		error(1);
	while (i < ac)
	{
		if(!checkarg(av[i]))
			error(2);
		i++;
	}
	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (!nb || nb < INT_MIN || nb > INT_MAX)
			error(2);
		i++;
	}
	return 1;

}

int checkarg(char *str)
{
	int i = 0;
	while(str[i] == ' ')
			i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return 0;
		i++;
	}
	return 1;
}

void give_params(t_content *it, int ac, char **av)
{
	int i = 0;
	it->nphilos = ft_atoi(av[1]);
	it->tdie = ft_atoi(av[2]);
	it->teat = ft_atoi(av[3]);
	it->tsleep = ft_atoi(av[4]);
	it->full = 0;
	it->death = 0;
	it->start = get_time();
	if (ac == 5)
		it->nmeals = -1;
	else if (ac == 6)
		it->nmeals = ft_atoi(av[5]);
	while (i <= it->nphilos)
		it->counter[i++] = 0;
	
}

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
	else if (code == 5)
	{
		printf("Threads creation failed\n");
		exit(1);
	}
}

void give_philos(t_pstats *p, t_lock *m, t_content *curr, t_lock *f )
{
	int i = 0;
	if (curr->tdie < 100 && curr->teat < 100)
		curr->tthink = 5;
	else
		curr->tthink = 20;
	while ( i < curr->nphilos)
	{
		p[i].id = i + 1;
		p[i].lastmeal = get_time();
		p[i].eating = 0;
		p[i].full = 0;
		p[i].turn = 0;
		p[i].meal_lock = &m[i];
		p[i].rfork = &f[i];
		p[i].lfork = &f[(i + 1) % curr->nphilos];
		p[i].in = curr;
		i++;
	}
}


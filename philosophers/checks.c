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


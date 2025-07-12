#include "philo.h"

void ft_usleep(size_t ms)
{
        long start;
        start = get_time();
        while ((get_time() - start) <= ms)
                asm volatile ("pause");        
}

long    ft_atoi(const char *str)
{
        int     i;
        long    res;
        int     sign;

        i = 0;
        res = 0;
        sign = 1;
        while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
                i++;
        if (str[i] == '-')
        {
                sign *= (-1);
                i++;
        }
        else if (str[i] == '+')
                i++;
        while (str[i] >= '0' && str[i] <= '9')
        {
                res = (res * 10) + str[i] - 48;
                i++;
        }
        return (res * sign);
}

void put_dead(t_content *curr, int i)
{
        pthread_mutex_lock(&curr->print);
        put_time(*curr);
        printf("lfilasof %i mat layr7mo\n",i);
        pthread_mutex_unlock(&curr->print);
}

void put_time(t_content curr)
{
        size_t time;
        time = get_time() - curr.start;
        printf("%lu ", time);
}

void put_message(char *s, t_pstats *p)
{
        pthread_mutex_lock(&p->in->print);
        pthread_mutex_lock(p->meal_lock);
        if (is_alive(p->in) == 1)
        {
                put_time(*p->in);
                printf("The philosopher %d is %s\n", p->id, s);
        }
        pthread_mutex_unlock(&p->in->print);
        pthread_mutex_unlock(p->meal_lock);
}

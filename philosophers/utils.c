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
#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/*int ft_putchar(char c)
{
	int count = 0;
	count = write(1,&c,1);
	return count;
}*/
int ft_putstr(char *s, char c, int f)
{
	int i = 0;
	int count = 0;
	if (f == 1)
		count += write(1,&c,1);
	else
	{
		while (s[i])
		{
			count += write(1,&s[i],1);
			i++;
		}
	}
	return count;
}

int	ft_putnbr(long nb)
{
	int		count;

	count = 0;
	if (nb < 0)
	{
		count += ft_putstr(0,'-',1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	else
		count += ft_putstr(0,nb + '0',1);
	return (count);

}

int ft_puthex(unsigned long n, char c,char f)
{
	int count = 0;
	/*if (!n)
	{
		write(1,"(nil)",5);
		return ;
	}*/
	if(f == 1)
		count += write(1,"0x",2);

	
	const char *hex;
	if (c == 'X')
		hex = "0123456789ABCDEF";
	else if (c == 'x')
		hex = "0123456789abcdef";
	else
		return 0;
	if ( n>= 16)
	{
		count += ft_puthex(n/16,c,0);
		count += ft_puthex(n%16,c,0);
	}
	else
		count += ft_putstr(0,hex[n],1);
	
	return count;
}


/*void ft_putaddr(unsigned long n)
{
	if (!n)
	{
		write(1,"(nil)",5);
		return 0;
	}
	write(1,"0x",2);
	ft_puthex(n,'x');
}
*/
int ft_printf(const char *s, ...)
{
	va_list args;
	va_start(args,s);
	int i = 0;
	int count = 0;
	while(s[i])
	{
		if(s[i] != '%')
			count += ft_putstr(0,s[i],1);
		else if(s[i] == '%')
		{
			if(s[i+1] == 'd' || s[i+1] == 'i')
			{
				count += ft_putnbr(va_arg(args,int));
				i++;
			}
			else if(s[i+1] == 's')
			{
				count+=ft_putstr(va_arg(args,char*),0,0);
				i++;
			}
			else if(s[i+1] == 'c')
			{
				count += ft_putstr(0,va_arg(args,int),1);
				i++;
			}
			else  if(s[i+1] == '%')
			{
				count += ft_putstr(0,'%',1);
				i++;
			}
			else if(s[i+1] == 'u')
			{
				count +=ft_putnbr(va_arg(args, unsigned int));
				i++;
			}
			else if(s[i+1] == 'x' || s[i+1] == 'X')
			{
				if (s[i+1] == 'x')
					count += ft_puthex(va_arg(args,unsigned int),'x',0);
				else
					count += ft_puthex(va_arg(args,unsigned int),'X',0);
				i++;
			}
			else if(s[i+1] == 'p')
			{
				unsigned long long x = (unsigned long long)va_arg(args,void *);
				if (!x)
				{
					count += write(1,"(nil)",5);
				}
				else
					count += ft_puthex(x,'x',1);
				i++;
			}
		}
	i++;
	}
	return count;
}
#include <limits.h>
/*int main()
{
	int a = 1234567;
	int *aa = &a;
	int *b = NULL;
	ft_printf("%d\n",ft_printf("%x\n", LONG_MAX));
	printf("%d\n",printf("%x\n", LONG_MAX));
}*/

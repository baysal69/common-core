#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}
int is_val(char *str)
{
	int i = 0, open = 0, close = 0;
	while (str[i])
	{
		if (str[i] == '(')
			open++;
		else if (str[i] == ')')
		{
			if (open > 0)
				open--;
			else
				close++;
		}
		i++;
	}
	return open + close;
}

void rip(char *str, int fix, int n_fix, int dep)
{
	if (fix == n_fix && !is_val(str))
	{
		puts(str);
		return;
	}
	int i = 0;
	while (str[i])
	{
		if (str[i] == '(' || str[i] == ')')
		{
			char c = str[i];
			str[i] = ' ';
			rip(str, fix, n_fix + 1, i);
			str[i] = c;
		}
		i++;
	}
}
int main(int ac, char **av)
{
	if (ac != 2 )
		return 1;
	int fix = is_val(av[1]);
	rip(av[1],fix,0,0);
}

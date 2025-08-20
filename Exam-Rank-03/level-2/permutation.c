#include <stdlib.h>
#include <unistd.h>
int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return i;
}
int check_dup(char *str)
{
	int i = 0, j = 1, a = 0;
	while(str[i])
	{
		j = 0;
		while (str[j])
		{
			if (j == a)
				j++;
			if (str[i] == str[j])
				return 1;
			j++;
		}
		a++;
		i++;
	}
	return 0;
}

void sort(char *str)
{
	int i = 0,j = 0;
	char tmp;
	while (str[i])
	{
		j = 0;
		while(str[j])
		{
			if (str[i] > str[j])
			{
				tmp = str[i];
				str[i] = str[j];
				str[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
			
void perm(char *str,char *result, int *used, int dep)
{
	int i = 0, len = ft_strlen(str);

	if (dep == len)
	{
		write(1,result,len);
		write(1,"\n",1);
	}
	while (str[i])
	{
		if (used[i] == 0)
		{
			result[dep] = str[i];
			used[i] = 1;
			perm(str,result,used,dep + 1);
			used[i] = 0;
		}
		i++;
	}

}
int main(int ac, char **av)
{
	if (ac != 2 || check_dup(av[1]))
		return 1;
	int i = 0;
	int len = ft_strlen(av[1]);
	i = 0;
	char *result = malloc(len);
	int *used = calloc (len,sizeof(int));
	sort(av[1]);
	perm(av[1],result,used,0);
	free(result);
	free(used);
}


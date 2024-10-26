#include <stdio.h>
#include <string.h>

int main()
{
	char str1[] = "baysal";
	char str2[] = "raso kbir";
	printf("%s\n",strcat(str1,str2));
	printf("%d\n", strlcat (str1,str2,6));
}

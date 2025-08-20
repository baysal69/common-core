#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int safe(int *pos,int curr_col, int curr_row)
{
	int prev_col = 0,prev_row=0;
	while(prev_col < curr_col)
	{
		prev_row = pos[prev_col];
		if (prev_row - prev_col == curr_row - curr_col || prev_row + prev_col == curr_row + curr_col || prev_row == curr_row)
			return 0;
		prev_col++;
	}
	return 1;
}

void queen(int *pos, int len, int col)
{
	int i = 0;
	if (col == len)
	{
		while (i < len)
		{
			if (i > 0)
				printf(" ");
			printf("%d",pos[i]);
			i++;
		}
		printf("\n");
		return;
	}
	int row=0;
	while (row < len)
	{
		if (safe(pos,col,row))
		{
			pos[col] = row;
			queen(pos, len, col+1);
		}
		row++;
	}
}





int main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	int queens = atoi(av[1]);
	int *pos = calloc(queens, sizeof(int));
	queen(pos,queens,0);
}

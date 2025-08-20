#include <stdio.h>
#include <stdlib.h>

void powerset(int *nums, int len, int target, int *result, int res_index, int index, int curr_sum)
{
	int i = 0;
	if (index == len)
	{
		if (curr_sum == target)
		{
			while(i < res_index)
			{
				printf("%d",result[i]);
				if (i != res_index - 1)
					printf(" ");
				i++;
			}
			printf("\n");
		}
			return;
	}
	powerset(nums, len, target, result, res_index, index +1, curr_sum);
	result[res_index] = nums[index];
	powerset(nums,len,target,result,res_index + 1, index + 1, curr_sum + nums[index]);
}
			

int main(int ac, char **av)
{
	if (ac < 2)
		return 1;
	int *nums = calloc(ac - 2, sizeof(int));
	int *res = calloc (ac - 2, sizeof(int));
	int len = ac -2;
	int target = atoi(av[1]);
	int i = 0, j = 1;
	while (i < (ac-2))
	{
		nums[i] = atoi(av[j]);
		i++;
		j++;
	}
	powerset(nums, len, target, res, 0, 0, 0);
}

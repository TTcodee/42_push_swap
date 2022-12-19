#include "../../include/psw.h"

void	arr_swap(int *nums, int *indexes, int i, int j)
{
	int	tmp;

	tmp = nums[i];
	nums[i] = nums[j];
	nums[i] = tmp;
	indexes[i] = j;
	indexes[j] = i;
	return ;
}

//sort and return index after being sorted;
int	*ist_sort(int *nums, int n)
{
	int	*ret;
	int	i;
	int	j;

	i = -1;
	ret = malloc(sizeof(int) * (n + 1));
	if (!ret)
		return (NULL);
	while (++i < n)
		ret[i] = i;
	i = 0;
	while (++i < n)
	{
		j = -1;
		while (++j < i)
			if (nums[j] < nums[i])
				arr_swap(nums, ret, i, j);
	}
	return (ret);
}

//***unoptimized version***
int	find_median(t_stack *stack, int start, int end)
{
	int	*nums;
	t_dnode	*walker;
	int	i;
	int	*indexes;

	i = 0;
	nums = malloc((stack->size + 1) * sizeof(int));
	if (!nums)
		return (-1);
	while (walker && i++ < start)
		walker = walker->next;
	while (i < end)
	{
		nums[i - start] = *(int *)walker->data;
		i++;
	}
	indexes = ist_sort(nums, stack->size);
	if (!indexes)
		return (-1);
	return (indexes[stack->size / 2]);
}

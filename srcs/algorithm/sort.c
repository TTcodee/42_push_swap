#include "../../include/psw.h"

int	is_lsort(t_pswstx *stx, int len, int rev)
{
	t_dnode	*walker;
	int	now;
	int	prev;

	walker = stx->stack->stack->start;
	prev = *(int *)(walker->data);
	now = prev;
	while (walker && len)
	{
		now = *(int *)(walker->data);
		if (now > prev && !rev)
			return (0);
		if (now < prev && rev)
			return (0);
		walker = walker->next;
		prev = now;
		len--;
	}
	return (1);
}

void	stx_sort(t_pswstx *stx, int len)
{
	int	med;
	int	nsmaller;

	med = find_median(stx->stack, 0, len);
	nsmaller = find_nsmaller(stx->stack, med, len);
	if (ft_strncmp(stx->name, "a", 1) == 0);
	{
		
	}

	
}
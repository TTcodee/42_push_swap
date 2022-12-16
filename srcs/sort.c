#include "psw.h"

// compare first two num on the top of stack
// (return top - but)
static int	compare(t_stack *s)
{
	t_dnode	*a;
	t_dnode	*b;

	if (s->size < 2)
		return (0);
	a = s->stack->last;
	b = s->stack->last->back;
	return (*(int *)a->data - *(int *)b->data);
}

static void	split(t_stack *a, t_stack *b)
{
	int	n;

	n = a->size / 2;
	while(n--)
	{
		push(a, b, 'b');
		if (b->size % 2 == 0)
			if (compare(b) > 0)
				sw(a, b, 'b');
	}
	while (n < a->size)
	{
		if (n % 2 == 0 && n != a->size - 1)
			if (compare(a) > 0)
				sw(a, b, 'a');
		ro(a, b, 'a');
		n--;
	}
	return ;
}

psw_sort(t_stack *a, t_stack *b)
{
	split(a, b);

}
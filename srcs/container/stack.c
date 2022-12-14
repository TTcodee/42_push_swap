#include "stack.h"

int	push(t_stack *self, void *data)
{
	self->size = self->stack->len + 1;
	return (self->stack->addlast(self->stack, data));
}

void	*pop(t_stack *self)
{
	void	*tmp;

	tmp = self->stack->last->data;
	self->stack->rmlast(self->stack, NULL);
	self->size = self->stack->len;
	return (tmp);
}

t_stack	*stack_init()
{
	t_stack	*ret;

	ret = malloc(sizeof(t_stack));
	if (!ret)
		return (NULL);
	ret->stack = dlist_init();
	if (!ret->stack)
		return (NULL);
	ret->size = 0;
	ret->push = push;
	ret->pop = pop;
	ret->rotate = rotate;
	ret->rev_rotate = rev_rotate;
	ret->swap = swap;
	return (ret);
}
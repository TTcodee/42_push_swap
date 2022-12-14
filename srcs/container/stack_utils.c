#include "stack.h"

void	swap(t_stack *self)
{
	void	*tmp1;
	void	*tmp2;

	if (self->size < 2)
		return ;
	tmp1 = self->pop(self);
	tmp2 = self->pop(self);
	self->push(self, tmp1);
	self->push(self, tmp2);
	return ;
}

void	rotate(t_stack *self)
{
	t_dnode	*top;
	t_dnode	*base;

	if (self->size < 2)
		return ;
	top = self->stack->last->back;
	base = self->stack->last;
	base->next = self->stack->start;
	self->stack->start->back = base;
	base->back = NULL;
	top->next = NULL;
	self->stack->start = base;
	self->stack->last = top;
	return ;
}

void	rev_rotate(t_stack *self)
{
	t_dnode	*top;
	t_dnode	*base;

	if (self->size < 2)
		return ;
	top = self->stack->start;
	base = self->stack->start->next;
	top->back = self->stack->last;
	self->stack->last->next = top;
	base->back = NULL;
	top->next = NULL;
	self->stack->start = base;
	self->stack->last = top;
}
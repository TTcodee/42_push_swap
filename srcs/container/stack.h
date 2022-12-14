#ifndef STACK_H
# define STACK_H
# include <stdlib.h>
# include "dlist.h"

typedef struct s_stack t_stack;

struct s_stack
{
	t_dlist		*stack;
	unsigned int	size;
	int		(*push)(t_stack *, void *);
	void		*(*pop)(t_stack *);
	void		(*swap)(t_stack *);
	void		(*rotate)(t_stack *);
	void		(*rev_rotate)(t_stack *);
};

int		push(t_stack *self, void *data);
void		*pop(t_stack *self);
void		swap(t_stack *self);
void		rotate(t_stack *self);
void		rev_rotate(t_stack *self);
t_stack		*stack_init(void);
#endif

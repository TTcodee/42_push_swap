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
};

int	push(t_stack *self, void *data);
void	*pop(t_stack *self);
t_stack	*stack_init(void);
#endif

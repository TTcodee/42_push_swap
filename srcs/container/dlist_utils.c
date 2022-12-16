#include "dlist.h"

void	clear(t_dlist *self, void (*del)(void *))
{
	t_dnode	*walker;
	t_dnode	*tmp;

	walker = self->start;
	while (walker)
	{
		if (del)
			del(walker->data);
		tmp = walker->next;
		free(walker);
		walker = tmp;
	}
	return ;
}
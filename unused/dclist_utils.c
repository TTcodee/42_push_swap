#include "dclist.h"

void	connect(t_dclist *l, t_dnode *bef, t_dnode *aft)
{
	if (l->dir = UP)
	{
		bef->next = aft;
		aft->back = bef;
	}
	else
	{
		bef->back = aft;
		aft->next = bef;
	}
	return ;
}
#include "dclist.h"

t_dnode	*get_last(t_dclist *self)
{
	if (self->len <= 1)
		return (self->start);
	if (self->dir == UP)
		return (self->start->next);
	return (self->start->back);
}

int	addfirst(t_dclist *self, void *data)
{
	t_dnode	*node;
	t_dnode	*tail;

	node = malloc(sizeof(t_dnode));
	if (!node)
		return (0);
	if (self->len != 0)
	{
		tail = self->get_last(self);
		connect(self, node, self->start);
		connect(self, tail, node);
	}
	self->start = node;
	self->len++;
	return (1);

}

int	addlast(t_dclist *self, void *data)
{
	t_dnode	*node;
	t_dnode	*tail;

	node = malloc(sizeof(t_dnode));
	if (!node)
		return (0);
	if (self->len++ != 0)
	{
		tail = self->get_last(self);
		connect(self, tail, node);
		connect(self, node, self->start);
	}
	else
		self->start = node;
	return (1);
}

void	rmfirst(t_dclist *self, void (*del)(void *))
{
	if (self->len >= 1)
	{
		if (self->len > 1)
			connect(self, self->get_last(self), self->start->next);
		if (del)
			del(self->start->data);
		free(self->start);
		self->start = NULL;
	}
	self->len--;
	return ;
}

void	rmlast(t_dclist *self, void (*del)(void *))
{
	t_dnode	*tail;

	tail = self->get_last(self);
	if (self->len >= 1)
	{
		if (self->len > 1)
		{
			if (self->dir == UP)
				connect(self, tail->back, self->start);
			else
				connect(self, self->start, tail->next);
		}
		if (del)
			del(tail->data);
		free(tail);
		self->len--;
	}
	return ;
}


t_dclist	*dclist_init()
{
	t_dclist	*ret;

	ret = malloc(sizeof(t_dclist));
	if (!ret)
		return (NULL);
	ret->len = 0;
	ret->start = NULL;
	ret->dir = UP;
	ret->addfirst = addfirst;
	ret->addlast = addlast;
	ret->rmfirst = rmfirst;
	ret->rmlast = rmlast;
	ret->get_last = get_last;

	return (ret);
}
#include "dlist.h"

static int	addfirst(t_dlist *self, void *data)
{
	t_dnode	*node;

	node = malloc(sizeof(t_dlist));
	if (!node)
		return (0);
	node->data = data;
	node->back = (void *)0;
	node->next = self->start;
	self->start = node;
	if (self->len == 0)
		self->last = self->start;
	self->len++;
	return (1);
}

static int	addlast(t_dlist *self, void *data)
{
	t_dnode	*node;

	node = malloc(sizeof(t_dlist));
	if (!node)
		return (0);
	node->data = data;
	node->next = (void *)0;
	node->back = self->last;
	self->last = node;
	if (self->len == 0)
		self->start = self->last;
	self->len++;
	return (1);
}

static void	rmfirst(t_dlist *self, void (*del)(void *))
{
	t_dnode	*tmp;

	if (self->len == 0)
		return ;
	tmp = self->start->next;
	if (del)
		del(self->start->data);
	free(self->start);
	self->start = tmp;
	self->len--;
	if (self->len <= 1)
		self->last = self->start;
	return ;
}

static void	rmlast(t_dlist *self, void (*del)(void *))
{
	t_dnode	*tmp;

	if (self->len == 0)
		return ;
	tmp = self->last->back;
	if (del)
		del(self->last->data);
	free(self->last);
	self->last = tmp;
	self->len--;
	if (self->len <= 1)
		self->start = self->last;
	return ;
}

t_dlist	*dlist_init()
{
	t_dlist	*ret;

	ret = malloc(sizeof(t_dlist));
	if (!ret)
		return (NULL);
	ret->len = 0;
	ret->start = NULL;
	ret->last = NULL;
	ret->addfirst = addfirst;
	ret->addlast = addlast;
	ret->rmfirst = rmfirst;
	ret->rmlast = rmlast;
	ret->clear = clear;
	return (ret);
}
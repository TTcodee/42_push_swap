#include "../../include/dlist.h"

int	lst_addfirst(t_dlist *self, void *data)
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

int	lst_addlast(t_dlist *self, void *data)
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

void	lst_rmfirst(t_dlist *self, void (*del)(void *))
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

void	lst_rmlast(t_dlist *self, void (*del)(void *))
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
	ret->addfirst = lst_addfirst;
	ret->addlast = lst_addlast;
	ret->rmfirst = lst_rmfirst;
	ret->rmlast = lst_rmlast;
	ret->clear = lst_clear;
	return (ret);
}
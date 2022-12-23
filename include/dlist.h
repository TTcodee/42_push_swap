#ifndef DLIST_H
# define DLIST_H
# include <stdlib.h>

typedef struct s_dnode t_dnode;
typedef struct s_dlist t_dlist;

struct s_dnode
{
	t_dnode	*next;
	t_dnode	*back;
	void	*data;
};

struct s_dlist
{
	t_dnode		*start;
	t_dnode		*last;
	unsigned int	len;
	int		(*addfirst)(t_dlist *self, void *);
	int		(*addlast)(t_dlist *self, void *);
	void		(*rmfirst)(t_dlist *self, void (*del)(void *));
	void		(*rmlast)(t_dlist *self, void (*del)(void *));
	void		(*clear)(t_dlist *self, void (*del)(void *));
};

int	lst_addfirst(t_dlist *self, void *data);
int	lst_addlast(t_dlist *self, void *data);
void	lst_rmfirst(t_dlist *self, void (*del)(void *));
void	lst_rmlast(t_dlist *self, void (*del)(void *));
void	lst_clear(t_dlist *self, void (*del)(void *));
t_dlist	*dlist_init(void);

#endif
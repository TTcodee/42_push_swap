/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dclist.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:31:08 by ppanpais          #+#    #+#             */
/*   Updated: 2022/12/12 21:02:33 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DCLIST_H
# define DCLIST_H
# include <stdlib.h>
# define UP 1
# define DOWN 0

typedef struct s_dnode	t_dnode;
typedef struct s_dclist	t_dclist;

struct s_dnode
{
	t_dnode	*next;
	t_dnode	*back;
	void	*data;
};

struct s_dclist
{
	t_dnode		*start;
	int		dir;
	unsigned int	len;
	int		(*addfirst)(t_dclist *self, void *);
	int		(*addlast)(t_dclist *self, void *);
	void		(*rmfirst)(t_dclist *self, void (*del)(void *));
	void		(*rmlast)(t_dclist *self, void (*del)(void *));
	t_dnode		*(*get_last)(t_dclist *self);
};

int	addfirst(t_dclist *self, void *data);
int	addlast(t_dclist *self, void *data);
void	rmfirst(t_dclist *self, void (*del)(void *));
void	rmlast(t_dclist *self, void (*del)(void *));
void	connect(t_dclist *l, t_dnode *bef, t_dnode *aft);
t_dnode		*get_last(t_dclist *self);
t_dclist	*dlist_init(void);

#endif
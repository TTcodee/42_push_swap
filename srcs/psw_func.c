/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 00:38:38 by ppanpais          #+#    #+#             */
/*   Updated: 2022/12/27 16:04:42 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/psw.h"

void	push(t_pswstx *self)
{
	void	*tmp;

	tmp = self->tmp->stack->pop(self->tmp->stack);
	self->stack->push(self->stack, tmp);
	ft_putstr_fd("p", 1);
	ft_putstr_fd(self->name, 1);
	ft_putchar_fd('\n', 1);
	return ;
}

void	sw(t_pswstx	*self)
{
	self->stack->swap(self->stack);
	ft_putstr_fd("sw", 1);
	ft_putstr_fd(self->name, 1);
	ft_putchar_fd('\n', 1);
	return ;
}

void	ro(t_pswstx *self)
{
	self->stack->rotate(self->stack);
	ft_putstr_fd("r", 1);
	ft_putstr_fd(self->name, 1);
	ft_putchar_fd('\n', 1);
	return ;
}

void	rro(t_pswstx *self)
{
	self->stack->rev_rotate(self->stack);
	ft_putstr_fd("rr", 1);
	ft_putstr_fd(self->name, 1);
	ft_putchar_fd('\n', 1);
	return ;
}

t_pswstx	*pswstx_init(char *name)
{
	t_pswstx	*ret;
	
	ret = malloc(sizeof(t_pswstx));
	if (!ret)
		return (NULL);
	ret->name = name;
	ret->tmp = NULL;
	ret->stack = stack_init();
	if (!ret->stack)
		return (NULL);
	ret->push = push;
	ret->sw = sw;
	ret->ro = ro;
	ret->rro = rro;
	return (ret);
}
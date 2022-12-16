/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 00:38:38 by ppanpais          #+#    #+#             */
/*   Updated: 2022/12/15 00:43:23 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw.h"

void	push(t_stack *a, t_stack *b, char c)
{
	if (c == 'a')
	{
		ft_putchar_fd("pa\n", 1);
		a->push(a, b->pop(b));
	}
	else if (c == 'b')
	{
		ft_putstr_fd("pb\n", 1);
		b->push(b, a->pop(a));
	}
	else	
		ft_putstr_fd("\n!!!!!!!!!\nMISSED TYPING\n", 1);
	return ;
}

void	sw(t_stack *a, t_stack *b, char c)
{
	if (c == 'a')
	{
		ft_putchar_fd("sa\n", 1);
		a->swap(a);
	}
	else if (c == 'b')
	{
		ft_putstr_fd("sb\n", 1);
		b->swap(b);
	}
	else	
		ft_putstr_fd("\n!!!!!!!!!\nMISSED TYPING\n", 1);
	return ;
}

void	ro(t_stack *a, t_stack *b, char c)
{
	if (c == 'a')
	{
		ft_putchar_fd("ra\n", 1);
		a->rotate(a);
	}
	else if (c == 'b')
	{
		ft_putstr_fd("rb\n", 1);
		b->rotate(b);
	}
	else	
		ft_putstr_fd("\n!!!!!!!!!\nMISSED TYPING\n", 1);
	return ;
}

void	rro(t_stack *a, t_stack *b, char c)
{
	if (c == 'a')
	{
		ft_putchar_fd("rra\n", 1);
		a->rev_rotate(a);
	}
	else if (c == 'b')
	{
		ft_putstr_fd("rrb\n", 1);
		b->rev_rotate(b);
	}
	else	
		ft_putstr_fd("\n!!!!!!!!!\nMISSED TYPING\n", 1);
	return ;
}
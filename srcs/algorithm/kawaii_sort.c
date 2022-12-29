/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kawaii_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:11:50 by ppanpais          #+#    #+#             */
/*   Updated: 2022/12/27 16:11:46 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/psw.h"
// size = 2 compare the swap if unsorted
// size = 3 
//	1	2	2	1	3	3
//	2	1	3	3	2	1
//	3	3	1	2	1	2
//	ok	sw	rev	p sw pu	rro rro	ro

void	sort3(t_pswstx	*stx, t_stack *s)
{
	int	tmp3[3];

	tmp3[0] = *(int *)s->stack->start->data;
	tmp3[1] = *(int *)s->stack->start->next->data;
	tmp3[2] = *(int *)s->stack->last->data;
	if (tmp3[0] < tmp3[1])
	{
		if (tmp3[1] < tmp3[2])
		{
			stx->rro(stx);
			stx->rro(stx);
		}
		else if (tmp3[0] > tmp3[2])
		{
			stx->tmp->push(stx->tmp);
			stx->sw(stx);
			stx->push(stx);
		}
		else
			stx->rro(stx);
	}
	else
	{
		if (tmp3[0] < tmp3[2])
			stx->ro(stx);
		else
			stx->sw(stx);
	}
}

void	small_sort(t_pswstx *stx)
{
	t_stack	* s;
	
	s = stx->stack;
	if (is_lsort(stx, s->size, 0))
		return ;
	if (s->size == 2)
		stx->sw(stx);
	else if (s->size == 3)
		sort3(stx, s);
	else if (s->size <= 5)
	{
		ft_putstr_fd("AH SHIT NONONO\n", 1);
	}
}
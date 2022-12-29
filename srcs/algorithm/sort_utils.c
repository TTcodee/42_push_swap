/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 23:14:07 by ppanpais          #+#    #+#             */
/*   Updated: 2022/12/29 01:30:02 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/psw.h"

int	find_nsmaller(t_stack *s, int num, int len)
{
	int	ret;
	t_dnode	*walker;

	walker = s->stack->start;
	ret = 0;
	while (walker && len)
	{
		if (*(int *)walker->data < num)
			ret++;
		len--;
		walker = walker->next;
	}
	return (ret);
}

void	mv_to_smaller(t_pswstx *stx, int len, int med)
{
	t_dnode	*forth;
	t_dnode	*back;
	int	tmp;
	int	round;

	round = 1;
	tmp = len;
	forth = stx->stack->stack->start;
	back = forth;
	forth = forth->next;
	while (--len)
		back = back->next;
	while (tmp > 0)
	{
		if (*(int *)forth->data < med)
			break;
		if (*(int *)back->data < med)
		{
			round = -1 * round;
			break;
		}
		round++;
		tmp -= 2;
		forth = forth->next;
		back = back->back;
	}
	while (round != 0)
	{
		if (round > 0)
		{
			stx->ro(stx);
			round--;
		}
		else
		{
			stx->rro(stx);
			round++;
		}
	}
}
void	eco_split(t_pswstx *stx, int len, int med)
{
	t_stack	*s;
	int	nsmaller;

	s = stx->stack;
	nsmaller = find_nsmaller(stx->stack, med, len);
	while (nsmaller--)
	{
		if (*(int *)s->stack->last < med)
			stx->tmp->push(stx->tmp);
		else
		{
			mv_to_smaller(stx, len, med);
			stx->tmp->push(stx->tmp);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kawaii_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:11:50 by ppanpais          #+#    #+#             */
/*   Updated: 2022/12/22 17:23:10 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/psw.h"
// size = 2 compare the swap if unsorted
// size = 3 
//	1	2	2	1	3	3
//	2	1	3	3	2	1
//	3	3	1	2	1	2
//	ok	sw	rev	p sw pu	ro ro	ro


void	small_sort(t_stack *s)
{
	if (s->size == 2)
	{
		if (s->stack->last > s->stack->start)
			sw(s, NULL, 'a');

	}
}
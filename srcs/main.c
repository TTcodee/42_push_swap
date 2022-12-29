/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:38:58 by ppanpais          #+#    #+#             */
/*   Updated: 2022/12/27 21:20:17 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw.h"
int	prepare_stack(t_pswstx	*a, t_pswstx *b)
{
	if (!a || !b)
		return (0);
	a->tmp = b;
	b->tmp = a;
	a->stack->clear(a->stack, NULL);
	a->name	= "a";
	b->name = "b";
	return (1);
}

int	main(int argc, char **argv)
{
	t_pswstx	*a;
	t_pswstx	*b;

	a = pswstx_init();
	b = pswstx_init();
	if (!prepare_stack(a, b))
		return (0);
	a->stack = receive_input(argc, argv);
	if (argc <= 1)
		return (0);
	if (!a->stack)
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	print_stack(a->stack);
	small_sort(a);
	print_stack(a->stack);
	return (0);
}
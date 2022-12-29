/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:59:13 by ppanpais          #+#    #+#             */
/*   Updated: 2022/12/27 16:03:36 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/psw.h"

int	m_floor(double n)
{
	int	m;

	m = n;
	return (m);
}

int	m_ciel(double n)
{
	int	m;

	m = n;
	if (n - m > 0)
		return (m + 1);
	return (m);
}

int	ft_isnum(char *str)
{
	if (!str)
		return (0);
	if (*str == '-')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

t_stack	*receive_input(int argc, char **argv)
{
	t_stack	*stack;
	int	*nptr;

	stack = stack_init();
	if (!stack )
		return (NULL);
	while (argc > 1)
	{
		if (!ft_isnum(argv[argc - 1]))
		{
			stack->clear(stack, free);
			return (NULL);
		}
		nptr = malloc(sizeof(int));
		*nptr = ft_atoi(argv[--argc]);
		stack->push(stack, nptr);
	}
	return (stack);
}
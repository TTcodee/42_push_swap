/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:38:58 by ppanpais          #+#    #+#             */
/*   Updated: 2022/12/14 23:34:20 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = receive_input(argc, argv);
	if (argc <= 1)
		return (0);
	if (!a)
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	
	return (0);
}
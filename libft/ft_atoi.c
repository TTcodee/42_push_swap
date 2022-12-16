/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 01:23:46 by ppanpais          #+#    #+#             */
/*   Updated: 2022/09/04 21:13:21 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The string may begin with an arbitrary amount of white space (as
       determined by isspace(3)) followed by a single optional '+' or
       '-' sign.
*/
int	ft_isspace(int c)
{
	if (c == '\f' || c == '\n' || c == '\r')
		return (1);
	else if (c == '\t' || c == '\v' || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;

	sign = 1;
	result = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + *nptr - '0';
		nptr++;
	}
	return (sign * result);
}
/*
int	checksign(const char *nptr, int *n, int found)
{
	if (*nptr == '+' && ft_isdigit(nptr[1]) && !found)
		return (1);
	else if (*nptr == '-' && ft_isdigit(nptr[1]) && !found)
	{
		*n = 1;
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	result;
	int	found;
	int	neg;

	neg = 0;
	found = 0;
	result = 0;
	while (*nptr)
	{
		if (ft_isdigit(*nptr))
		{
			result = result * 10 + *nptr - '0';
			found = 1;
		}
		else if (ft_isspace(*nptr) && !found)
			;
		else if (checksign(nptr, &neg, found))
			;
		else
			break ;
		nptr++;
	}
	if (neg)
		return (-1 * result);
	return (result);
}*/

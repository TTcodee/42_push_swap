/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:37:55 by ppanpais          #+#    #+#             */
/*   Updated: 2022/09/15 17:24:24 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**allocate_res(char const *s, char c)
{
	char	**res;
	int		i;
	int		bef;
	int		size;

	bef = 0;
	i = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (bef != i)
				size++;
			bef = i + 1;
		}
		i++;
	}
	if (bef < i)
		size++;
	res = (char **)malloc(sizeof(char **) * (size + 1));
	if (!res)
		return (NULL);
	res[size] = NULL;
	return (res);
}

char	**check_allocation_failed(char **res, char **end)
{
	int	diff;

	diff = end - res;
	while (res != end)
	{
		if (!*res++)
			return (NULL);
	}
	res -= diff;
	return (res);
}

char	**splitting(char const *s, char c, char **end)
{
	int	i;
	int	bef;

	i = 0;
	bef = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (i != bef)
				*end++ = ft_substr(s, bef, i - bef);
			bef = i + 1;
		}
		i++;
	}
	if (bef < i)
		*end++ = ft_substr(s, bef, i - bef);
	return (end);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	**p;

	if (!s)
		return (0);
	res = allocate_res(s, c);
	if (!res)
		return (NULL);
	p = splitting(s, c, res);
	return (check_allocation_failed(res, p));
}

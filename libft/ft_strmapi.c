/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:27:54 by ppanpais          #+#    #+#             */
/*   Updated: 2022/09/15 17:05:08 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	l;
	unsigned int	i;
	char			*res;

	if (!s)
		return (0);
	i = 0;
	l = ft_strlen(s);
	res = (char *)malloc(l + 1);
	if (!res)
		return (NULL);
	res[l] = '\0';
	while (i < l)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	return (res);
}

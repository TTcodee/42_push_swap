/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:56:44 by ppanpais          #+#    #+#             */
/*   Updated: 2022/09/15 15:23:43 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	isin(char c, char const *s)
{
	while (*s)
		if (*s++ == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	while (len > 0)
	{
		if (!isin(s1[len - 1], set))
			break ;
		len--;
	}
	while (*s1 && len)
	{
		if (!isin(*s1, set))
			break ;
		s1++;
		len--;
	}
	ret = ft_substr(s1, 0, len);
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	return (ret);
}

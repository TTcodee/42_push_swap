/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 01:14:09 by ppanpais          #+#    #+#             */
/*   Updated: 2022/09/15 15:24:32 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	pos;
	size_t	lpos;

	pos = 0;
	if (*little == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (big[pos] && pos < len)
	{
		lpos = 0;
		while (big[pos + lpos] == little[lpos] && pos + lpos < len)
		{
			if (big[pos + lpos] && little[lpos])
				lpos++;
			else
				break ;
		}
		if (little[lpos] == '\0')
			return ((char *)(big + pos));
		pos++;
	}
	return (NULL);
}

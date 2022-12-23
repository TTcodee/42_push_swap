/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:50:51 by ppanpais          #+#    #+#             */
/*   Updated: 2022/09/05 00:27:46 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		diff;
	size_t	i;

	diff = 0;
	i = 0;
	while (i < n && *(s1) && *(s2))
	{
		diff = *((unsigned char *)s1++) - *((unsigned char *)s2++);
		if (diff != 0)
			return (diff);
		i++;
	}
	if (i < n)
		diff = *((unsigned char *)s1) - *((unsigned char *)s2);
	return (diff);
}

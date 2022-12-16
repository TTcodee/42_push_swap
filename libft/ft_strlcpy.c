/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 23:14:29 by ppanpais          #+#    #+#             */
/*   Updated: 2022/09/03 14:32:23 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	cpy at most size - 1 and add '\0' : return length of src
 * */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;

	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (--size && *src)
		*dest++ = *src++;
	*dest = '\0';
	return (len);
}

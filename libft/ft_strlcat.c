/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 23:54:59 by ppanpais          #+#    #+#             */
/*   Updated: 2022/09/14 21:39:08 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*p;
	char	*psrc;
	int		len;

	if (size == 0 || size <= ft_strlen(dst))
		return (ft_strlen(src) + size);
	len = 0;
	p = dst;
	psrc = (char *)src;
	while (*p && size)
	{
		p++;
		size--;
	}
	len = ft_strlen(src) + p - dst;
	while (--size && *psrc)
		*p++ = *psrc++;
	*p = '\0';
	return (len);
}
/*
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*p;
	size_t	len;
	size_t	ret;

	len = ft_strlen(dst);
	p = dst;
	ret = ft_strlen(src) + size;
	if (ret >= len + ft_strlen(src))
		ret = len + ft_strlen(src);
	while (*p)
		p++;
	if (size >= len)
		ft_strlcpy(p, src, size - len);
	return (ret);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:21:09 by ppanpais          #+#    #+#             */
/*   Updated: 2022/09/15 19:53:14 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	size;
	unsigned int	i;
	unsigned int	m_size;

	if (!s)
		return (NULL);
	i = 0;
	size = ft_strlen(s);
	if (start >= size)
		m_size = 1;
	else if (size - start >= len)
		m_size = len + 1;
	else
		m_size = size - start + 1;
	ret = (char *)malloc(sizeof(char) * m_size);
	if (!ret)
		return (NULL);
	while (start < size && s[start] && len--)
		ret[i++] = s[start++];
	ret[i] = '\0';
	return (ret);
}

// int main()
// {
// 	char *s = ft_substr("tripouille", 100, 1);
// }

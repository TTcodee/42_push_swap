/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:57:07 by ppanpais          #+#    #+#             */
/*   Updated: 2022/09/12 23:39:29 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_len(long long int n)
{
	if (n < 0)
		return (1 + find_len(-1 * n));
	if (n < 10)
		return (1);
	return (1 + find_len(n / 10));
}

int	tenpow(int n)
{
	if (n == 0)
		return (1);
	return (10 * tenpow(n - 1));
}

void	convert(char *s, long long int n, int len)
{
	if (n < 0)
	{
		*s = '-';
		n = -1 * n;
		len--;
		convert(s + 1, n, len);
	}
	else if (len == 1)
		*s = (char)(n + '0');
	else
	{
		s[len - 1] = (char)(n % 10 + '0');
		convert(s, n / 10, len - 1);
	}
	return ;
}

char	*ft_itoa(int n)
{
	char	*ans;
	int		size;

	size = find_len(n);
	ans = (char *)malloc(size + 1);
	if (!ans)
		return (NULL);
	ans[size] = '\0';
	convert(ans, n, size);
	return (ans);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:50:42 by ppanpais          #+#    #+#             */
/*   Updated: 2022/09/15 17:11:27 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*last;
	t_list	*org;

	if (!lst || !f | !del)
		return (NULL);
	org = ft_lstnew(f(lst -> content));
	if (!org)
	{
		ft_lstclear(&org, del);
		return (NULL);
	}
	last = org;
	lst = lst -> next;
	while (lst)
	{
		last -> next = ft_lstnew(f(lst -> content));
		if (!(last -> next))
		{
			ft_lstclear(&org, del);
			return (NULL);
		}
		last = last -> next;
		lst = lst -> next;
	}
	return (org);
}

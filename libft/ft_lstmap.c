/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:54:18 by apons             #+#    #+#             */
/*   Updated: 2018/12/07 14:21:51 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*link;
	t_list	*chain;

	if (lst && f)
	{
		if (!(chain = ft_lstnew(lst->content, lst->content_size)))
			return (NULL);
		chain = f(chain);
		head = chain;
		lst = lst->next;
		while (lst)
		{
			if (!(link = ft_lstnew(lst->content, lst->content_size)))
				return (NULL);
			link = f(link);
			chain->next = link;
			chain = chain->next;
			link = NULL;
			lst = lst->next;
		}
		return (head);
	}
	return (NULL);
}

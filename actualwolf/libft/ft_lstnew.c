/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 10:36:58 by apons             #+#    #+#             */
/*   Updated: 2018/12/07 14:26:37 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *link;

	if (!(link = (t_list *)malloc(sizeof(t_list) * 2)))
		return (NULL);
	if (!(link->content = ft_memalloc(content_size)))
		return (NULL);
	if (!(content))
	{
		link->content = NULL;
		link->content_size = 0;
	}
	else
	{
		link->content = ft_memcpy(link->content, content, content_size);
		link->content_size = content_size;
	}
	link->next = NULL;
	return (link);
}

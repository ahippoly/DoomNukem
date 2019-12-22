/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:16:36 by ahippoly          #+#    #+#             */
/*   Updated: 2018/11/19 19:12:42 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlist;
	void	*newcontent;

	if (!(newlist = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == 0)
	{
		newlist->content = NULL;
		newlist->content_size = 0;
	}
	else
	{
		if (!(newcontent = (char*)malloc(content_size)))
			return (NULL);
		ft_memcpy(newcontent, content, content_size);
		newlist->content_size = content_size;
		newlist->content = newcontent;
	}
	newlist->next = NULL;
	return (newlist);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:14:40 by ahippoly          #+#    #+#             */
/*   Updated: 2018/11/21 18:38:51 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newchain;

	if (lst)
	{
		if (!(newchain = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		*newchain = *f(lst);
		newchain->next = ft_lstmap(lst->next, f);
		return (newchain);
	}
	return (lst);
}

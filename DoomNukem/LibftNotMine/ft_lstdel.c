/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 12:53:34 by apons             #+#    #+#             */
/*   Updated: 2018/12/07 14:19:28 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tonull;
	t_list	*first;

	if (alst && del)
	{
		first = *alst;
		while (*alst)
		{
			tonull = *alst;
			*alst = (*alst)->next;
			del(tonull->content, tonull->content_size);
			free(tonull);
		}
		first = NULL;
	}
}

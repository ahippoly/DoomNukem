/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:50:49 by arsciand          #+#    #+#             */
/*   Updated: 2018/11/20 16:22:07 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstmerge(t_list **alst1, t_list *alst2)
{
	if (!*alst1)
		*alst1 = alst2;
	else if (!(*alst1)->next)
		(*alst1)->next = alst2;
	else
		ft_lstmerge(&((*alst1)->next), alst2);
}

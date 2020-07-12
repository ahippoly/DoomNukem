/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_env1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 21:50:09 by alebui            #+#    #+#             */
/*   Updated: 2020/07/09 15:38:21 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

t_ssprite		*malloc_ssprite(int size)
{
	t_ssprite	*sprite;

	if (!(sprite = (t_ssprite *)ft_memalloc(sizeof(t_ssprite) * (size + 1))))
		return (NULL);
	return (sprite);
}

t_button		*malloc_button(int size)
{
	t_button	*button;

	if (!(button = (t_button*)ft_memalloc(sizeof(t_button) * (size + 1))))
		return (NULL);
	return (button);
}

t_txt_img		*malloc_txtimg(int size)
{
	t_txt_img	*txt;

	if (!(txt = (t_txt_img *)ft_memalloc(sizeof(t_txt_img) * (size + 1))))
		return (NULL);
	return (txt);
}

t_input			*malloc_input(int size)
{
	t_input		*input;

	if (!(input = (t_input *)ft_memalloc(sizeof(t_input) * (size + 1))))
		return (NULL);
	return (input);
}

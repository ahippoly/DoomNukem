/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <alebui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 21:50:48 by alebui            #+#    #+#             */
/*   Updated: 2020/07/05 21:50:49 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

SDL_Texture		**malloc_texture_tab(int size)
{
	SDL_Texture	**tab;

	if (!(tab = (SDL_Texture**)ft_memalloc(sizeof(SDL_Texture *) * (size + 1))))
		return (NULL);
	return (tab);
}

t_range			*malloc_range(int size)
{
	t_range		*range;

	if (!(range = (t_range*)ft_memalloc(sizeof(t_range) * (size + 1))))
		return (NULL);
	return (range);
}

int				*malloc_int_tab(int size)
{
	int			*tab;

	if (!(tab = (int *)ft_memalloc(sizeof(int) * (size + 1))))
		return (NULL);
	return (tab);
}

t_icon			*malloc_icon(int size)
{
	t_icon		*ptr;

	if (!(ptr = (t_icon *)ft_memalloc(sizeof(t_icon) * (size + 1))))
		return (NULL);
	return (ptr);
}

/*
t_wall			*malloc_wall(int size)
{
	t_icon		*ptr;

	if (!(ptr = (t_wall *)ft_memalloc(sizeof(t_wall) * (size + 1))))
		return (NULL);
	return (ptr);
}
*/

t_img			*malloc_img(int size)
{
	t_img		*img;

	if (!(img = (t_img *)ft_memalloc(sizeof(t_img) * (size + 1))))
		return (NULL);
	return (img);
}


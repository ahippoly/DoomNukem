/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:24:50 by apons             #+#    #+#             */
/*   Updated: 2020/02/05 15:24:50 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		init_stat(t_stat *stat, int max, int current)
{
	stat->current = current;
	stat->max = max;
}

SDL_Rect	sdl_set_rect(int x, int y, int w, int h)
{
	SDL_Rect rectangle;
	
	rectangle.x = x;
	rectangle.y = y;
	rectangle.w = w;
	rectangle.h = h;
	return (rectangle);
}
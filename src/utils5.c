/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:36:29 by robin             #+#    #+#             */
/*   Updated: 2020/07/06 15:38:06 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void		*ft_memmove2(void *dst, const void *src, size_t len)
{
	char	*csrc;
	char	*cdst;
	size_t	i;

	if (src == dst)
		return (dst);
	csrc = (char *)src;
	cdst = (char *)dst;
	if (src < dst)
	{
		i = len;
		while (i-- > 0)
			cdst[i] = csrc[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			cdst[i] = csrc[i];
			i++;
		}
	}
	return (dst);
}

void		del_from_array(void *list, int *size, void *to_remove,
				int obj_size)
{
	int i;

	i = 0;
	while (i < *size)
	{
		if ((list + obj_size * i) == to_remove)
			break ;
		i++;
	}
	(*size)--;
	ft_memmove2(list + obj_size * i, list + obj_size * (i + 1), (*size - i) *
		obj_size);
}

void		print_text_screen(unsigned int *p_tab, t_img *text, SDL_Rect draw)
{
	SDL_Point		end;
	t_point			t_scale;
	t_point			t_step;
	int				ty;
	float			tx_start;
	int				x_start;
	unsigned int	*pixels;

	t_step.x = (float)text->w / draw.w;
	t_step.y = (float)text->h / draw.h;
	end.x = ft_min(draw.x + draw.w, WIN_SIZE_X);
	end.y = ft_min(draw.y + draw.h, WIN_SIZE_Y) * WIN_SIZE_Y;
	tx_start = 0;
	if (draw.x < 0)
		tx_start = t_step.x * -draw.x;
	if (draw.y < 0)
		t_scale.y = t_step.y * -draw.y;
	draw.y = ft_max(draw.y, 0) * WIN_SIZE_Y;
	x_start = ft_max(draw.x, 0);
	pixels = (unsigned int*)text->pixels;
	while (draw.y < end.y)
	{
		t_scale.x = tx_start;
		ty = (int)t_scale.y * text->w;
		draw.x = x_start;
		while (draw.x < end.x)
		{
			p_tab[draw.x + draw.y] = pixels[(int)t_scale.x + ty];
			t_scale.x += t_step.x;
			draw.x++;
		}
		t_scale.y += t_step.y;
		draw.y += WIN_SIZE_Y;
	}
}

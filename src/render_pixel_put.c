/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 23:36:37 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/05 17:42:06 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void	put_pix(unsigned int *pixels, t_draw p_pos, t_img text,
	SDL_Point t_cord)
{
	pixels[p_pos.start_x + p_pos.start_y] = text.pixels[t_cord.x + t_cord.y
		* text.w];
}

void	put_pix_alpha(unsigned int *pixels, t_draw p_pos,
		unsigned int color, float alpha)
{
	int				pixel_pos;
	unsigned int	dst_color;

	pixel_pos = p_pos.start_x + p_pos.start_y;
	dst_color = pixels[pixel_pos];
	calc_transparency(&color, &dst_color, alpha);
	pixels[pixel_pos] = color;
}

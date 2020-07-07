/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_draw_slice.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 04:25:12 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/06 23:39:46 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void	put_p(unsigned int *addr, t_color_alp color)
{
	*addr = color.color;
}

void	put_p_alpha(unsigned int *addr, t_color_alp color)
{
	*addr = calc_transparency2(*addr, color.color, color.alpha);
}

void	adapt_ty_and_range(t_draw *range, float *ty, float ty_step)
{
	if (range->start_y < 0)
	{
		*ty += ty_step * -range->start_y;
		range->start_y = 0;
	}
	range->start_y *= WIN_SIZE_X;
	range->end_y *= WIN_SIZE_X;
	range->end_y = ft_min(range->end_y, WIN_SIZE_Y * WIN_SIZE_X);
}

void	draw_text_slice(unsigned int *pixels, t_draw range, t_obj obj,
	t_ray ray)
{
	float	ty_step;
	float	ty;
	int		tx;
	int		p_cord;
	void	(*put_pix)(unsigned int*, t_color_alp);

	tx = ray.mod_scale * obj.w;
	ty_step = (float)obj.h * (ray.z_text) / (range.end_y - range.start_y);
	ty = (1 - get_float_part(ray.z_height.pos + ray.z_height.size
		- obj.z_text_offset)) * obj.h;
	adapt_ty_and_range(&range, &ty, ty_step);
	p_cord = range.start_x + range.start_y;
	if (obj.alpha < 0.001)
		put_pix = &put_p;
	else
		put_pix = &put_p_alpha;
	while (p_cord < range.end_y)
	{
		while (ty > obj.h - INTER_TOLERANCE)
			ty -= obj.h;
		(*put_pix)(&pixels[p_cord], (t_color_alp){obj.pixels[tx + (int)ty * obj.w], obj.alpha});
		ty += ty_step;
		p_cord += WIN_SIZE_X;
	}
}

t_draw	calc_ray_draw_range(t_data *d, t_ray ray, int x)
{
	t_draw	draw;

	draw.start_x = x;
	draw.end_x = x;
	draw.start_y = d->screen_height - ((ray.z_height.pos + ray.z_height.size
		- d->player_height) * WIN_SIZE_Y) / ray.dist;
	draw.end_y = (draw.start_y + (ray.z_height.size * WIN_SIZE_Y) / ray.dist);
	draw.step_y = WIN_SIZE_X;
	return (draw);
}

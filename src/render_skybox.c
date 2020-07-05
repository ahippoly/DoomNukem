/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_skybox.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 21:47:14 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/05 17:25:13 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

t_point	init_sky_param(t_img *skybox, int *pos_y, int *y_max)
{
	t_point	scale;

	scale.x = (float)skybox->w * 0.25 / WIN_SIZE_X;
	scale.y = (float)skybox->h * 0.8 / WIN_SIZE_Y;
	*pos_y = 0;
	*y_max = WIN_SIZE_Y * WIN_SIZE_X;
	return (scale);
}

void	print_skybox(t_data *d, t_img skybox, float rot, unsigned int *screen)
{
	t_point		p;
	t_point		scale;
	SDL_Point	pos;
	t_range		y;
	int			start_x;

	rot = mod_pi(rot);
	start_x = rot * skybox.w / PI_X_2;
	p.y = (1 - (float)d->screen_height / WIN_SIZE_Y) * skybox.h * 0.2;
	scale = init_sky_param(&skybox, &pos.y, &y.end);
	while (pos.y < y.end)
	{
		y.start = (int)p.y * skybox.w;
		pos.x = -1;
		p.x = start_x;
		while (++pos.x < WIN_SIZE_X)
		{
			if (screen[pos.x + pos.y] == 0)
				screen[pos.x + pos.y] = skybox.pixels[y.start + (int)p.x];
			if ((p.x += scale.x) > skybox.w)
				p.x = 0;
		}
		pos.y += WIN_SIZE_X;
		p.y += scale.y;
	}
}

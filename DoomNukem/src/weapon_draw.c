/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 10:51:21 by apons             #+#    #+#             */
/*   Updated: 2020/02/12 10:51:21 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		weapon_draw(t_enval *env)
{
	int			id;
	t_intxy		offset;
	t_intxy		c;
	uint32_t	zpixel;
	uint32_t	pixel;

	id = env->game.pc.equip.current * 2 + env->game.pc.equip.weapon_state;
	offset.x = env->game.pc.arsenal[id / 2].offset + env->user.bobbing.x;
	offset.y = 20 + env->user.bobbing.y;
	zpixel = get_pixel_weapon(env, id, 0, 0);
	c.x = -1;
	while (++c.x < env->weapontex[id].img->w * 3)
	{
		c.y = -1;
		while (++c.y < env->weapontex[id].img->h * 3)
		{
			pixel = get_pixel_weapon(env, id, c.x / 3, c.y / 3);
			if (pixel == zpixel)
			 	continue;
			put_pixel(env->sdl.screen,
			(WIN_W / 2) - (env->weapontex[id].img->w * 3 / 2) + c.x + offset.x,
			(WIN_H - env->weapontex[id].img->h * 3) + c.y + offset.y, pixel);
		}
	}
}
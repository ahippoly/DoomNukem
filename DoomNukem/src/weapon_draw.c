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

static int	get_shotgun_id(double current, double max)
{
	if (current >= max * 0.90)
		return (1);
	if (current >= max * 0.70 || (current < max * 0.10))
		return (0);
	if (current >= max * 0.60 || (current >= max * 0.10 && current < max * 0.20))
		return (2);
	if (current >= max * 0.50 || (current >= max * 0.20 && current < max * 0.30))
		return (3);
	return (4);
}

static int	get_bmp_id(t_enval *env, t_intxy *id)
{
	if (env->game.pc.equip.weapon_state == WEAPON_STATE_READY)
		return(0);
	if(env->game.pc.equip.weapon_state == WEAPON_STATE_CHARGING)
		return(2);
	if (env->game.pc.equip.weapon_state == WEAPON_STATE_RELOADING)
	{	
		id->x = 5;
		return (0);
	}
	if (id->x == 2)
		return (get_shotgun_id(env->game.pc.arsenal[id->x].attack.delay.current,
		env->game.pc.arsenal[id->x].attack.delay.max));
	if (env->game.pc.arsenal[id->x].attack.delay.current
	>= (double)env->game.pc.arsenal[id->x].attack.delay.max * 0.75)
		return(1);
	if (env->game.pc.arsenal[id->x].attack.delay.current
	>= (double)env->game.pc.arsenal[id->x].attack.delay.max * 0.50)
		return(2);
	return(3);

}

void		weapon_draw(t_enval *env)
{
	t_intxy		id;
	t_intxy		offset;
	t_intxy		c;
	uint32_t	zpixel;
	uint32_t	pixel;

	id.x = env->game.pc.equip.current;
	// ft_putnbr(id);
	// ft_putendl(" is the id.");
	offset.x = env->game.pc.arsenal[id.x].offset + env->user.bobbing.x;
	id.y = get_bmp_id(env, &id);
	offset.y = 20 + env->user.bobbing.y;
	zpixel = get_pixel_weapon(env, id, 0, 0);
	c.x = -1;
	while (++c.x < env->wptex[id.x][id.y].img->w * 3)
	{
		c.y = -1;
		while (++c.y < env->wptex[id.x][id.y].img->h * 3)
		{
			pixel = get_pixel_weapon(env, id, c.x / 3, c.y / 3);
			if (pixel == zpixel)
			 	continue;
			put_pixel(env->sdl.screen,
			(WIN_W / 2) - (env->wptex[id.x][id.y].img->w * 3 / 2) + c.x + offset.x,
			(WIN_H - env->wptex[id.x][id.y].img->h * 3) + c.y + offset.y, pixel);
		}
	}
}
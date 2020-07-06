/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init_gun.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 01:21:40 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/06 13:39:07 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void	init_sprite(t_data *d)
{
	load_sprite_gun(d);
	d->gun_ind = 0;
	d->sprite[d->gun_ind].index = 0;
}

int		load_sprite_gun(t_data *d)
{
	SDL_Texture *texture;

	texture = load_sprite_bmp(MELEE_PATH, d);
	d->sprite[MELEE] = sprite_init_melee(texture);
	texture = load_sprite_bmp(REVOLVER_PATH, d);
	d->sprite[REVOLVER] = sprite_init_revolver(texture);
	texture = load_sprite_bmp(SSG_PATH, d);
	d->sprite[SSG] = sprite_init_ssg(texture);
	texture = load_sprite_bmp(ASSAULT_RIFLE_PATH, d);
	d->sprite[ASSAULT_RIFLE] = sprite_init_ar(texture);
	texture = load_sprite_bmp(LMG_PATH, d);
	d->sprite[LMG] = sprite_init_lmg(texture);
	texture = load_sprite_bmp(DEATH_DEALER_PATH, d);
	d->sprite[DEATH_DEALER] = sprite_init_dd(texture);
	return (EXIT_SUCCESS);
}

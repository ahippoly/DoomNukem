/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init_gun4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:44:23 by robin             #+#    #+#             */
/*   Updated: 2020/07/06 13:46:07 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

static void			init_anim_lmg2(t_sprite *sprite)
{
	sprite->anim[RELOAD].pos->x = 4;
	sprite->anim[RELOAD].pos->y = 1;
	sprite->anim[RELOAD].nb_frame = 22;
	sprite->anim[RELOAD].offset.x = 0;
	sprite->anim[RELOAD].offset.y = 32;
	sprite->anim[AIMFIRE].pos->x = 1;
	sprite->anim[AIMFIRE].pos->y = 6;
	sprite->anim[AIMFIRE].nb_frame = 3;
	sprite->anim[AIMFIRE].offset.x = 0;
	sprite->anim[AIMFIRE].offset.y = 0;
	sprite->anim[ICON].pos->x = 3;
	sprite->anim[ICON].pos->y = 1;
	sprite->anim[ICON].nb_frame = 1;
	sprite->anim[ICON].offset.x = 0;
	sprite->anim[ICON].offset.y = 0;
}

static void			init_anim_lmg(t_sprite *sprite)
{
	sprite->anim[IDLE].pos->x = 3;
	sprite->anim[IDLE].pos->y = 7;
	sprite->anim[IDLE].nb_frame = 1;
	sprite->anim[IDLE].offset.x = 0;
	sprite->anim[IDLE].offset.y = 32;
	sprite->anim[FIRE].pos->x = 4;
	sprite->anim[FIRE].pos->y = 6;
	sprite->anim[FIRE].nb_frame = 3;
	sprite->anim[FIRE].offset.x = 0;
	sprite->anim[FIRE].offset.y = 32;
	sprite->anim[AIM].pos->x = 0;
	sprite->anim[AIM].pos->y = 0;
	sprite->anim[AIM].nb_frame = 1;
	sprite->anim[AIM].offset.x = 0;
	sprite->anim[AIM].offset.y = 0;
	init_anim_lmg2(sprite);
}

t_sprite			sprite_init_lmg(SDL_Texture *text)
{
	t_sprite sprite;

	sprite.size.x = 400;
	sprite.size.y = 400;
	sprite.aim_on = 0;
	sprite.anim_end = 0;
	sprite.time = 0;
	sprite.on = -1;
	sprite.index = 3;
	sprite.total_size.w = 1600;
	sprite.total_size.h = 1600;
	sprite.nb_frame.x = 5;
	sprite.nb_frame.y = 8;
	sprite.frame_size.w = sprite.total_size.w / sprite.nb_frame.x;
	sprite.frame_size.h = sprite.total_size.h / sprite.nb_frame.y;
	sprite.idle_frame.x = 0;
	sprite.idle_frame.y = 7;
	sprite.displayed_part.x = 0;
	sprite.displayed_part.y = 0;
	sprite.nb_anim = 7;
	sprite.idle_animation = 2;
	sprite.text = text;
	init_anim_lmg(&sprite);
	return (sprite);
}

static void			init_anim_rev(t_sprite *sprite)
{
	sprite->anim[IDLE].pos->x = 2;
	sprite->anim[IDLE].pos->y = 6;
	sprite->anim[IDLE].nb_frame = 1;
	sprite->anim[IDLE].offset.x = 0;
	sprite->anim[IDLE].offset.y = 0;
	sprite->anim[FIRE].pos->x = 1;
	sprite->anim[FIRE].pos->y = 2;
	sprite->anim[FIRE].nb_frame = 4;
	sprite->anim[FIRE].offset.x = 0;
	sprite->anim[FIRE].offset.y = 0;
	sprite->anim[AIM].pos->x = 2;
	sprite->anim[AIM].pos->y = 6;
	sprite->anim[AIM].nb_frame = 1;
	sprite->anim[AIM].offset.x = 0;
	sprite->anim[AIM].offset.y = 0;
	sprite->anim[RELOAD].pos->x = 1;
	sprite->anim[RELOAD].pos->y = 3;
	sprite->anim[RELOAD].nb_frame = 13;
	sprite->anim[RELOAD].offset.x = 0;
	sprite->anim[RELOAD].offset.y = 0;
	sprite->anim[ALTFIRE].pos->x = 0;
	sprite->anim[ALTFIRE].pos->y = 0;
	sprite->anim[ALTFIRE].nb_frame = 9;
	sprite->anim[ALTFIRE].offset.x = 0;
	sprite->anim[ALTFIRE].offset.y = 0;
}

t_sprite			sprite_init_revolver(SDL_Texture *text)
{
	t_sprite sprite;

	sprite.size.x = 400;
	sprite.size.y = 300;
	sprite.aim_on = 0;
	sprite.anim_end = 0;
	sprite.time = 0;
	sprite.on = -1;
	sprite.index = 3;
	sprite.total_size.w = 1280;
	sprite.total_size.h = 1176;
	sprite.nb_frame.x = 4;
	sprite.nb_frame.y = 7;
	sprite.frame_size.w = sprite.total_size.w / sprite.nb_frame.x;
	sprite.frame_size.h = sprite.total_size.h / sprite.nb_frame.y;
	sprite.idle_frame.x = 0;
	sprite.idle_frame.y = 7;
	sprite.displayed_part.x = 0;
	sprite.displayed_part.y = 0;
	sprite.nb_anim = 5;
	sprite.idle_animation = 3;
	sprite.text = text;
	init_anim_rev(&sprite);
	return (sprite);
}

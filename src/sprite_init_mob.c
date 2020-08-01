/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init_mob.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 14:03:18 by robin             #+#    #+#             */
/*   Updated: 2020/08/01 06:39:23 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

static void		init_anim_afrit2(t_ssprite *afrit)
{
	afrit->anim[ANIM_MOB_DEATH].nb_frame = 11;
	afrit->anim[ANIM_MOB_DEATH].offset.x = 0;
	afrit->anim[ANIM_MOB_DEATH].offset.y = 0;
	afrit->anim[ANIM_MOB_DEATH].speed = 150;
	init_anim_range_x(afrit, &afrit->anim[ANIM_MOB_DEATH],
		(SDL_Point){7, 0}, 10);
	afrit->anim[ANIM_MOB_DEATH].pos[10].x = 0;		
	afrit->anim[ANIM_MOB_DEATH].pos[10].y = 0;
	afrit->anim[ANIM_MOB_DEATH].size[10].w = 1;		
	afrit->anim[ANIM_MOB_DEATH].size[10].h = 1;		
	afrit->anim[ANIM_MOB_SHOOT].nb_frame = 9;
	afrit->anim[ANIM_MOB_SHOOT].offset.x = 0;
	afrit->anim[ANIM_MOB_SHOOT].offset.y = 0;
	afrit->anim[ANIM_MOB_SHOOT].speed = 150;
	init_anim_range_x(afrit, &afrit->anim[ANIM_MOB_SHOOT],
		(SDL_Point){6, 1}, 9);
	afrit->frame_disp_size.w = afrit->frame_size.w / 1.2;
	afrit->frame_disp_size.h = afrit->frame_size.h / 1.2;
}

static void		init_anim_afrit(t_ssprite *afrit)
{
	afrit->anim[ANIM_MOB_IDLE].nb_frame = 4;
	afrit->anim[ANIM_MOB_IDLE].offset.x = -2;
	afrit->anim[ANIM_MOB_IDLE].offset.y = 0;
	afrit->anim[ANIM_MOB_IDLE].speed = 350;
	afrit->frame_disp_size.w = afrit->frame_size.w / 1.8;
	afrit->frame_disp_size.h = afrit->frame_size.h / 1.8;
	init_anim_range_x(afrit, &afrit->anim[ANIM_MOB_IDLE],
			(SDL_Point){2, 1}, 4);
	afrit->anim[ANIM_MOB_MELEE].nb_frame = 3;
	afrit->anim[ANIM_MOB_MELEE].offset.x = 0;
	afrit->anim[ANIM_MOB_MELEE].offset.y = 0;
	afrit->anim[ANIM_MOB_MELEE].speed = 200;
	afrit->frame_disp_size.w = afrit->frame_size.w / 1.2;
	afrit->frame_disp_size.h = afrit->frame_size.h / 1.2;
	init_anim_range_x(afrit, &afrit->anim[ANIM_MOB_MELEE],
		(SDL_Point){0, 0}, 4);
	init_anim_afrit2(afrit);
	init_curr_frames(afrit);
}

t_ssprite		sprite_init_afrit(t_img src_img)
{
	t_ssprite afrit;

	afrit.current_anim = ANIM_MOB_IDLE;
	afrit.idle_anim = ANIM_MOB_IDLE;
	afrit.src.w = 1920;
	afrit.src.h = 320;
	afrit.nb_frame.x = 15;
	afrit.nb_frame.y = 2;
	afrit.frame_size.w = afrit.src.w / afrit.nb_frame.x;
	afrit.frame_size.h = afrit.src.h / afrit.nb_frame.y;
	afrit.frame_disp_size.w = afrit.frame_size.w / 1.2;
	afrit.frame_disp_size.h = afrit.frame_size.h / 1.2;
	afrit.default_frame.x = 0;
	afrit.default_frame.y = 0;
	afrit.time = 0;
	afrit.src = src_img;
	afrit.dst_w = afrit.frame_disp_size.w;
	afrit.dst_h = afrit.frame_disp_size.h;
	afrit.dst = alloc_image(afrit.dst_w, afrit.dst_h);
	init_anim_afrit(&afrit);
	copy_frame_ssprite(&afrit, afrit.default_frame, afrit.frame_disp_size);
	afrit.callback = NULL;
	return (afrit);
}

static void		init_anim_pyro(t_ssprite *pyro)
{
	pyro->anim[ANIM_MOB_IDLE].nb_frame = 4;
	pyro->anim[ANIM_MOB_IDLE].offset.x = -20;
	pyro->anim[ANIM_MOB_IDLE].offset.y = 20;
	pyro->anim[ANIM_MOB_IDLE].speed = 350;
	pyro->frame_disp_size.w = pyro->frame_size.w / 1.3;
	pyro->frame_disp_size.h = pyro->frame_size.h / 1.3;
	init_anim_range_x(pyro, &pyro->anim[ANIM_MOB_IDLE], (SDL_Point){7, 1}, 4);
	pyro->anim[ANIM_MOB_MELEE].nb_frame = 8;
	pyro->anim[ANIM_MOB_MELEE].offset.x = 0;
	pyro->anim[ANIM_MOB_MELEE].offset.y = 0;
	pyro->anim[ANIM_MOB_MELEE].speed = 150;
	init_anim_range_x(pyro, &pyro->anim[ANIM_MOB_MELEE], (SDL_Point){0, 0}, 8);
	pyro->anim[ANIM_MOB_DEATH].nb_frame = 9;
	pyro->anim[ANIM_MOB_DEATH].offset.x = 0;
	pyro->anim[ANIM_MOB_DEATH].offset.y = 0;
	pyro->anim[ANIM_MOB_DEATH].speed = 150;
	init_anim_range_x(pyro, &pyro->anim[ANIM_MOB_DEATH], (SDL_Point){8, 0}, 9);
	pyro->frame_disp_size.w = pyro->frame_size.w / 1;
	pyro->frame_disp_size.h = pyro->frame_size.h / 1;
	init_curr_frames(pyro);
}

t_ssprite		sprite_init_pyro(t_img src_img)
{
	t_ssprite pyro;

	pyro.current_anim = ANIM_MOB_IDLE;
	pyro.idle_anim = ANIM_MOB_IDLE;
	pyro.src.w = src_img.w;
	pyro.src.h = src_img.h;
	pyro.nb_frame.x = 10;
	pyro.nb_frame.y = 4;
	pyro.frame_size.w = pyro.src.w / pyro.nb_frame.x;
	pyro.frame_size.h = pyro.src.h / pyro.nb_frame.y;
	pyro.frame_disp_size.w = pyro.frame_size.w / 1;
	pyro.frame_disp_size.h = pyro.frame_size.h / 1;
	pyro.default_frame.x = 0;
	pyro.default_frame.y = 0;
	pyro.time = 0;
	pyro.src = src_img;
	pyro.dst_w = pyro.frame_disp_size.w;
	pyro.dst_h = pyro.frame_disp_size.h;
	pyro.dst = alloc_image(pyro.dst_w, pyro.dst_h);
	init_anim_pyro(&pyro);
	copy_frame_ssprite(&pyro, pyro.default_frame, pyro.frame_disp_size);
	pyro.callback = NULL;
	return (pyro);
}

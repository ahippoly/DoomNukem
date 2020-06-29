/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssprite.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 21:20:41 by ahippoly          #+#    #+#             */
/*   Updated: 2020/06/28 21:49:27 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "proto_global.h"


void init_sprites_img(t_data *d)
{
	d->sprite_img[SPRITE_ID_AFRIT] = read_img_surface(SPRITE_PATH_AFRIT, SDL_PIXELFORMAT_ARGB32);
	d->sprite_img[SPRITE_ID_PYRO] = read_img_surface(SPRITE_PATH_PYRO, SDL_PIXELFORMAT_ARGB32);
	//d->sprite_img[SPRITE_ID_REVOLVER] = read_img_surface(WEAPON_PATH_0, SDL_PIXELFORMAT_ARGB32);
}

void init_sprites_img_env(t_env *e)
{
	e->sprite_img[SPRITE_ID_AFRIT] = read_img_surface(SPRITE_PATH_AFRIT, SDL_PIXELFORMAT_RGBA32);
	e->sprite_img[SPRITE_ID_PYRO] = read_img_surface(SPRITE_PATH_PYRO, SDL_PIXELFORMAT_RGBA32);
}

void init_anim_range_x(t_ssprite *sprite, t_anim *anim, SDL_Point start, int nb_frame)
{
	int i;

	i = 0;
	while (i < nb_frame)
	{
		
		if (start.y >= sprite->nb_frame.y)
			return ;
		anim->pos[i].x = start.x * sprite->frame_size.w + anim->offset.x;
		anim->pos[i].y = start.y * sprite->frame_size.h + anim->offset.y;
		anim->size[i].w = sprite->frame_disp_size.w;
		anim->size[i].h = sprite->frame_disp_size.h;
		start.x++;
		i++;
		if (start.x >= sprite->nb_frame.x)
		{
			start.x = 0;
			start.y += 1;
		}
	}
	
}

void copy_frame_ssprite(t_ssprite *sprite, SDL_Point pos_anim, t_size size_anim)
{
	//copy_frame(sprite->dst, (SDL_Rect){0, 0, sprite->frame_disp_size.w, sprite->frame_disp_size.h}, sprite->src.pixels, (SDL_Rect){pos_anim.x, pos_anim.y, sprite->src.w, sprite->src.h});
	copy_frame_scale(sprite->dst, (SDL_Rect){size_anim.w, size_anim.h, sprite->frame_disp_size.w, sprite->frame_disp_size.h}, sprite->src.pixels, (SDL_Rect){pos_anim.x, pos_anim.y, sprite->src.w, sprite->src.h});
}

void init_curr_frames(t_ssprite *sprite)
{
	int i;

	i = 0;
	while (i < NB_ANIM)
		sprite->anim[i++].current_frame = 0;
}

static void      init_anim_afrit2(t_ssprite *afrit)
{
    afrit->anim[ANIM_MOB_IDLE].nb_frame = 4;
    afrit->anim[ANIM_MOB_IDLE].offset.x = -2;
    afrit->anim[ANIM_MOB_IDLE].offset.y = 0;
    afrit->anim[ANIM_MOB_IDLE].speed = 350;
	afrit->frame_disp_size.w = afrit->frame_size.w / 1.8;
	afrit->frame_disp_size.h = afrit->frame_size.h / 1.8;
	init_anim_range_x(afrit, &afrit->anim[ANIM_MOB_IDLE], (SDL_Point){2, 1}, 4);
    afrit->anim[ANIM_MOB_MELEE].nb_frame = 3;
    afrit->anim[ANIM_MOB_MELEE].offset.x = 0;
    afrit->anim[ANIM_MOB_MELEE].offset.y = 0;
    afrit->anim[ANIM_MOB_MELEE].speed = 200;
	afrit->frame_disp_size.w = afrit->frame_size.w / 1.2;
	afrit->frame_disp_size.h = afrit->frame_size.h / 1.2;
	init_anim_range_x(afrit, &afrit->anim[ANIM_MOB_MELEE], (SDL_Point){0, 0}, 3);
    afrit->anim[ANIM_MOB_DEATH].nb_frame = 10;
    afrit->anim[ANIM_MOB_DEATH].offset.x = 0;
    afrit->anim[ANIM_MOB_DEATH].offset.y = 0;
    afrit->anim[ANIM_MOB_DEATH].speed = 150;
	init_anim_range_x(afrit, &afrit->anim[ANIM_MOB_DEATH], (SDL_Point){7, 0}, 10);
    afrit->anim[ANIM_MOB_SHOOT].nb_frame = 9;
    afrit->anim[ANIM_MOB_SHOOT].offset.x = 0;
    afrit->anim[ANIM_MOB_SHOOT].offset.y = 0;
    afrit->anim[ANIM_MOB_SHOOT].speed = 150;
	init_anim_range_x(afrit, &afrit->anim[ANIM_MOB_SHOOT], (SDL_Point){6, 1}, 9);
	afrit->frame_disp_size.w = afrit->frame_size.w / 1.2;
	afrit->frame_disp_size.h = afrit->frame_size.h / 1.2;
	init_curr_frames(afrit);
}

t_ssprite    sprite_init_afrit2(t_img src_img)
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
    init_anim_afrit2(&afrit);
	copy_frame_ssprite(&afrit, afrit.default_frame, afrit.frame_disp_size);
	afrit.callback = NULL;
    return (afrit);
}

static void      init_anim_pyro2(t_ssprite *pyro)
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

t_ssprite    sprite_init_pyro2(t_img src_img)
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
    init_anim_pyro2(&pyro);
	copy_frame_ssprite(&pyro, pyro.default_frame, pyro.frame_disp_size);
	pyro.callback = NULL;
    return (pyro);
}

void init_sprites(t_data *d)
{
	
}

void load_anim(t_ssprite *sprite, int time, int anim_id)
{
	SDL_Point	curr_anim_pos;
	t_size		curr_anim_size;

	sprite->current_anim = anim_id;
	sprite->anim[anim_id].current_frame = 0;
	sprite->time = time;
	curr_anim_pos = sprite->anim[anim_id].pos[0];
	curr_anim_size = sprite->anim[anim_id].size[0];
	copy_frame_ssprite(sprite, curr_anim_pos, curr_anim_size);
	// copy_frame(sprite->dst, (SDL_Rect){0, 0, sprite->dst_w, sprite->dst_h}, sprite->src.pixels, (SDL_Rect){curr_anim_pos.x, curr_anim_pos.y, sprite->src.w, sprite->src.h});
}

void set_sprite_callback(t_ssprite *sprite, void (*funct)(t_param), t_param param)
{
	sprite->callback = funct;
	sprite->param = param;
}

void process_anim(t_ssprite *sprite, int time)
{
	t_anim		*anim;
	SDL_Point	curr_anim_pos;
	t_size		curr_anim_size;
	
	if (sprite->current_anim < 0)
		return ;
	anim = &sprite->anim[sprite->current_anim];
	if (time - sprite->time > anim->speed)
	{
		sprite->time = time;
		anim->current_frame += 1;
		if (anim->current_frame >= anim->nb_frame)
		{
			// printf("load new anim\n");
			if (sprite->callback != NULL)
				sprite->callback(sprite->param);
			sprite->callback = NULL;
			if (sprite->idle_anim >= 0)
				load_anim(sprite, time, sprite->idle_anim);
			else
				sprite->current_anim = -1;
			return ;
		}
		curr_anim_pos = anim->pos[anim->current_frame];
		curr_anim_size = anim->size[anim->current_frame];
		// printf("step frame\n");
		copy_frame_ssprite(sprite, curr_anim_pos, curr_anim_size);
		//copy_frame(sprite->dst, (SDL_Rect){0, 0, sprite->frame_size.w, sprite->frame_size.h}, sprite->src.pixels, (SDL_Rect){curr_anim_pos.x, curr_anim_pos.y, sprite->src.w, sprite->src.h});
	}
}

void process_mobs_anim(t_data *d)
{
	int i;

	i = 0;
	while (i < d->nb_mob)
	{
		process_anim(&d->mobs[i].sprite, d->time);
		i++;
	}
}
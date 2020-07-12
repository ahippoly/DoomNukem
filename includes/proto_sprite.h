/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto_sprite.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 23:48:12 by robin             #+#    #+#             */
/*   Updated: 2020/07/05 23:53:06 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_SPRITE_H
# define PROTO_SPRITE_H

# include "data.h"

SDL_Texture	*load_sprite_bmp(char *str, t_data *d);

/*
** sprite_init_gun.c
*/
t_sprite	sprite_init_ar(SDL_Texture *text);
t_sprite	sprite_init_dd(SDL_Texture *text);
t_sprite	sprite_init_lmg(SDL_Texture *text);
t_sprite	sprite_init_revolver(SDL_Texture *text);
t_sprite	sprite_init_ssg(SDL_Texture *text);
t_sprite	sprite_init_melee(SDL_Texture *text);
void		clean_sprite_gun(t_data *d);
int			load_sprite_gun(t_data *d);
void		init_sprite(t_data *d);

/*
** gun_anim.c
*/
void		sprite_anim_gun(t_data *d);
void		gun_idle_anim(t_data *d);

#endif

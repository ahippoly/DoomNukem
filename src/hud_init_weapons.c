/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_init_weapons.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 19:30:36 by alebui            #+#    #+#             */
/*   Updated: 2020/07/09 16:16:37 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

int				init_weapon_0(t_data *d, t_hud *hud)
{
	hud->perso_weapon[0]->id = 5;
	hud->perso_weapon[0]->name = WEAPON_NAME_5;
	hud->perso_weapon[0]->ammo_left = 999;
	hud->perso_weapon[0]->capacity = 999;
	hud->perso_weapon[0]->attack_delay = 1000;
	hud->perso_weapon[0]->reload_delay = 100;
	hud->perso_weapon[0]->dammage = 25;
	hud->perso_weapon[0]->range = 2;
	hud->perso_weapon[0]->z_force = 0.03;
	hud->perso_weapon[0]->shoot_repeat = 1;
	if (!(hud->perso_weapon[0]->surface = SDL_LoadBMP(WEAPON_PATH_0)))
		exit_game(d, "error : failed to load image");
	if (!(hud->perso_weapon[0]->texture = SDL_CreateTextureFromSurface(d->rend,
		hud->perso_weapon[0]->surface)))
		exit_game(d, "error : failed to create texture");
	SDL_FreeSurface(hud->perso_weapon[0]->surface);
	return (0);
}

int				init_weapon_1(t_data *d, t_hud *hud)
{
	hud->perso_weapon[1]->id = 1;
	hud->perso_weapon[1]->name = WEAPON_NAME_0;
	hud->perso_weapon[1]->ammo_left = 6;
	hud->perso_weapon[1]->capacity = 6;
	hud->perso_weapon[1]->attack_delay = 550;
	hud->perso_weapon[1]->reload_delay = 1200;
	hud->perso_weapon[1]->dammage = 35;
	hud->perso_weapon[1]->range = 10;
	hud->perso_weapon[1]->z_force = 0.015;
	hud->perso_weapon[1]->shoot_repeat = 0;
	if (!(hud->perso_weapon[1]->surface = SDL_LoadBMP(WEAPON_PATH_1)))
		exit_game(d, "error : failed to load image");
	if (!(hud->perso_weapon[1]->texture = SDL_CreateTextureFromSurface(d->rend,
		hud->perso_weapon[1]->surface)))
		exit_game(d, "error : failed to create texture");
	SDL_FreeSurface(hud->perso_weapon[1]->surface);
	return (0);
}

int				init_weapon_2(t_data *d, t_hud *hud)
{
	hud->perso_weapon[2]->id = 2;
	hud->perso_weapon[2]->name = WEAPON_NAME_1;
	hud->perso_weapon[2]->ammo_left = 2;
	hud->perso_weapon[2]->capacity = 2;
	hud->perso_weapon[2]->attack_delay = 650;
	hud->perso_weapon[2]->reload_delay = 1400;
	hud->perso_weapon[2]->dammage = 60;
	hud->perso_weapon[2]->range = 5;
	hud->perso_weapon[2]->z_force = 0.07;
	hud->perso_weapon[2]->shoot_repeat = 0;
	if (!(hud->perso_weapon[2]->surface = SDL_LoadBMP(WEAPON_PATH_2)))
		exit_game(d, "error : failed to load image");
	if (!(hud->perso_weapon[2]->texture = SDL_CreateTextureFromSurface(d->rend,
		hud->perso_weapon[2]->surface)))
		exit_game(d, "error : failed to create texture");
	SDL_FreeSurface(hud->perso_weapon[2]->surface);
	return (0);
}

int				init_weapon_3(t_data *d, t_hud *hud)
{
	hud->perso_weapon[3]->id = 3;
	hud->perso_weapon[3]->name = WEAPON_NAME_2;
	hud->perso_weapon[3]->ammo_left = 20;
	hud->perso_weapon[3]->capacity = 20;
	hud->perso_weapon[3]->attack_delay = 200;
	hud->perso_weapon[3]->reload_delay = 1700;
	hud->perso_weapon[3]->dammage = 15;
	hud->perso_weapon[3]->range = 10;
	hud->perso_weapon[3]->z_force = 0.005;
	hud->perso_weapon[3]->shoot_repeat = 1;
	if (!(hud->perso_weapon[3]->surface = SDL_LoadBMP(WEAPON_PATH_3)))
		exit_game(d, "error : failed to load image");
	if (!(hud->perso_weapon[3]->texture = SDL_CreateTextureFromSurface(d->rend,
		hud->perso_weapon[3]->surface)))
		exit_game(d, "error : failed to create texture");
	SDL_FreeSurface(hud->perso_weapon[3]->surface);
	return (0);
}

int				init_weapon_4(t_data *d, t_hud *hud)
{
	hud->perso_weapon[4]->id = 4;
	hud->perso_weapon[4]->name = WEAPON_NAME_3;
	hud->perso_weapon[4]->ammo_left = 20;
	hud->perso_weapon[4]->capacity = 20;
	hud->perso_weapon[4]->attack_delay = 200;
	hud->perso_weapon[4]->reload_delay = 1700;
	hud->perso_weapon[4]->dammage = 15;
	hud->perso_weapon[4]->range = 10;
	hud->perso_weapon[4]->z_force = 0.005;
	hud->perso_weapon[4]->shoot_repeat = 1;
	if (!(hud->perso_weapon[4]->surface = SDL_LoadBMP(WEAPON_PATH_4)))
		exit_game(d, "error : failed to load image");
	if (!(hud->perso_weapon[4]->texture = SDL_CreateTextureFromSurface(d->rend,
		hud->perso_weapon[4]->surface)))
		exit_game(d, "error : failed to create texture");
	SDL_FreeSurface(hud->perso_weapon[4]->surface);
	return (0);
}

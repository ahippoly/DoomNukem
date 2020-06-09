/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_weapon_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 08:52:21 by apons             #+#    #+#             */
/*   Updated: 2020/03/02 08:52:21 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

/*
** These initalize all the weapons's textures
*/

void	init_melee_texture(t_enval *env)
{
	if (!(env->wptex[0] = (t_sprite *)malloc(sizeof(t_sprite)
	* WEAPON_TEXTURES_MELEE)))
		ft_exit(env, "Melee texture loading error.", 1, 0);
	env->wptex[0][0].img = SDL_LoadBMP("img/apons_weapons/melee_idle.bmp");
	env->wptex[0][1].img = SDL_LoadBMP("img/apons_weapons/melee_punch1a.bmp");
	env->wptex[0][2].img = SDL_LoadBMP("img/apons_weapons/melee_punch2a.bmp");
	env->wptex[0][3].img = SDL_LoadBMP("img/apons_weapons/melee_punch1b.bmp");
	env->wptex[0][4].img = SDL_LoadBMP("img/apons_weapons/melee_punch2b.bmp");
	check_weapon_texture(env, 0, WEAPON_TEXTURES_MELEE);
}

void	init_pistol_texture(t_enval *env)
{
	if (!(env->wptex[1] = (t_sprite *)malloc(sizeof(t_sprite)
	* WEAPON_TEXTURES_PISTOL)))
		ft_exit(env, "Pistol texture loading error.", 1, 0);
	env->wptex[1][0].img = SDL_LoadBMP("img/apons_weapons/pistol_idle.bmp");
	env->wptex[1][1].img = SDL_LoadBMP("img/apons_weapons/pistol_firing1.bmp");
	env->wptex[1][2].img = SDL_LoadBMP("img/apons_weapons/pistol_firing2.bmp");
	env->wptex[1][3].img = SDL_LoadBMP("img/apons_weapons/pistol_firing3.bmp");
	env->wptex[1][4].img = SDL_LoadBMP("img/apons_weapons/pistol_firing4.bmp");
	check_weapon_texture(env, 1, WEAPON_TEXTURES_PISTOL);
}

void	init_shotgun_texture(t_enval *env)
{
	if (!(env->wptex[2] = (t_sprite *)malloc(sizeof(t_sprite)
	* WEAPON_TEXTURES_SHOTGUN)))
		ft_exit(env, "Shotgun texture loading error.", 1, 0);
	env->wptex[2][0].img = SDL_LoadBMP("img/apons_weapons/shotgun_idle.bmp");
	env->wptex[2][1].img = SDL_LoadBMP("img/apons_weapons/shotgun_firing1.bmp");
	env->wptex[2][2].img = SDL_LoadBMP("img/apons_weapons/shotgun_firing2.bmp");
	env->wptex[2][3].img = SDL_LoadBMP("img/apons_weapons/shotgun_firing3.bmp");
	env->wptex[2][4].img = SDL_LoadBMP("img/apons_weapons/shotgun_firing4.bmp");
	check_weapon_texture(env, 2, WEAPON_TEXTURES_SHOTGUN);
}

void	init_smg_texture(t_enval *env)
{
	if (!(env->wptex[3] = (t_sprite *)malloc(sizeof(t_sprite)
	* WEAPON_TEXTURES_SMG)))
		ft_exit(env, "SMG texture loading error.", 1, 0);
	env->wptex[3][0].img = SDL_LoadBMP("img/apons_weapons/smg_idle.bmp");
	env->wptex[3][1].img = SDL_LoadBMP("img/apons_weapons/smg_firing1.bmp");
	env->wptex[3][2].img = SDL_LoadBMP("img/apons_weapons/smg_firing2.bmp");
	check_weapon_texture(env, 3, WEAPON_TEXTURES_SMG);
}

void	init_bfg_texture(t_enval *env)
{
	if (!(env->wptex[4] = (t_sprite *)malloc(sizeof(t_sprite)
	* WEAPON_TEXTURES_BFG)))
		ft_exit(env, "BFG texture loading error.", 1, 0);
	env->wptex[4][0].img = SDL_LoadBMP("img/apons_weapons/bfg_idle.bmp");
	env->wptex[4][1].img = SDL_LoadBMP("img/apons_weapons/bfg_charging1.bmp");
	env->wptex[4][2].img = SDL_LoadBMP("img/apons_weapons/bfg_charging2.bmp");
	env->wptex[4][3].img = SDL_LoadBMP("img/apons_weapons/bfg_charging3.bmp");
	env->wptex[4][4].img = SDL_LoadBMP("img/apons_weapons/bfg_charging4.bmp");
	env->wptex[4][5].img = SDL_LoadBMP("img/apons_weapons/bfg_charging5.bmp");
	env->wptex[4][6].img = SDL_LoadBMP("img/apons_weapons/bfg_charging6.bmp");
	env->wptex[4][7].img = SDL_LoadBMP("img/apons_weapons/bfg_charging7.bmp");
	env->wptex[4][8].img = SDL_LoadBMP("img/apons_weapons/bfg_charging8.bmp");
	env->wptex[4][9].img = SDL_LoadBMP("img/apons_weapons/bfg_charging9.bmp");
	env->wptex[4][10].img = SDL_LoadBMP("img/apons_weapons/bfg_charging10.bmp");
	env->wptex[4][11].img = SDL_LoadBMP("img/apons_weapons/bfg_firing1.bmp");
	env->wptex[4][12].img = SDL_LoadBMP("img/apons_weapons/bfg_firing2.bmp");
	env->wptex[4][13].img = SDL_LoadBMP("img/apons_weapons/bfg_firing3.bmp");
	env->wptex[4][14].img = SDL_LoadBMP("img/apons_weapons/bfg_firing4.bmp");
	check_weapon_texture(env, 4, WEAPON_TEXTURES_BFG);
}

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

void	init_melee_texture(t_enval *env)
{
	int i;

	ft_putendl("Melee error ?");
	if (!(env->wptex[0] = (t_sprite *)malloc(sizeof(t_sprite) * WEAPON_TEXTURES_MELEE)))
		ft_error("melee texture loading error", env , 0);
	env->wptex[0][0].img = SDL_LoadBMP("img/weapons/hand.bmp");
	env->wptex[0][1].img = SDL_LoadBMP("img/weapons/hand2.bmp");
	env->wptex[0][2].img = SDL_LoadBMP("img/weapons/cac1.bmp");
	env->wptex[0][3].img = SDL_LoadBMP("img/weapons/cac2.bmp");
	i = 0;	
	while (i < WEAPON_TEXTURES_MELEE)
	{
		if (!env->wptex[0][i].img)
			ft_error("missing or corrupted melee texture(s).", env, 0);
		i++;
	}
}

void	init_pistol_texture(t_enval *env)
{
	int i;

	ft_putendl("Pistol error ?");
	if (!(env->wptex[1] = (t_sprite *)malloc(sizeof(t_sprite) * WEAPON_TEXTURES_PISTOL)))
		ft_error("pistol texture loading", env, 0);
 	env->wptex[1][0].img = SDL_LoadBMP("img/apons_weapons/pistol_idle.bmp");
	env->wptex[1][1].img = SDL_LoadBMP("img/apons_weapons/pistol_firing1.bmp");
	env->wptex[1][2].img = SDL_LoadBMP("img/apons_weapons/pistol_firing2.bmp");
	env->wptex[1][3].img = SDL_LoadBMP("img/apons_weapons/pistol_firing3.bmp");
	i = 0;
	while (i < WEAPON_TEXTURES_PISTOL)
	{
		if (!env->wptex[1][i].img)
			ft_error("missing or corrupted pistol texture(s).", env, 0);
		i++;
	}
}

void	init_shotgun_texture(t_enval *env)
{
	int i;

	ft_putendl("Shotgun error ?");
	if (!(env->wptex[2] = (t_sprite *)malloc(sizeof(t_sprite) * WEAPON_TEXTURES_SHOTGUN)))
		ft_error(" texture loading error", env, 0);
	env->wptex[2][0].img = SDL_LoadBMP("img/apons_weapons/shotgun_idle.bmp");
	env->wptex[2][1].img = SDL_LoadBMP("img/weapons/shotgunfire.bmp");
	env->wptex[2][2].img = SDL_LoadBMP("img/apons_weapons/shotgun_firing2.bmp");
	env->wptex[2][3].img = SDL_LoadBMP("img/apons_weapons/shotgun_firing3.bmp");
	env->wptex[2][4].img = SDL_LoadBMP("img/apons_weapons/shotgun_firing4.bmp");
	i = 0;
	while (i < WEAPON_TEXTURES_SHOTGUN)
	{
		if (!env->wptex[2][i].img)
			ft_error("missing or corrupted shotgun texture(s).", env, 0);
		i++;
	}
}

void	init_smg_texture(t_enval *env)
{
	int i;

	ft_putendl("SMG error ?");
	if (!(env->wptex[3] = (t_sprite *)malloc(sizeof(t_sprite) * WEAPON_TEXTURES_SMG)))
		ft_error(" texture loading error", env, 0);
	env->wptex[3][0].img = SDL_LoadBMP("img/weapons/rafle.bmp");
	env->wptex[3][1].img = SDL_LoadBMP("img/weapons/rafle2.bmp");
	env->wptex[3][2].img = SDL_LoadBMP("img/weapons/rafle.bmp");
	env->wptex[3][3].img = SDL_LoadBMP("img/weapons/rafle2.bmp");
	i = 0;
	while (i < WEAPON_TEXTURES_SMG)
	{
		if (!env->wptex[3][i].img)
			ft_error("missing or corrupted SMG texture(s).", env, 0);
		i++;
	}
}

void	init_bfg_texture(t_enval *env)
{
	int i;

	ft_putendl("BFG error ?");
	if (!(env->wptex[4] = (t_sprite *)malloc(sizeof(t_sprite) * WEAPON_TEXTURES_BFG)))
		ft_error(" texture loading error", env, 0);
	env->wptex[4][0].img = SDL_LoadBMP("img/weapons/autogun1.bmp");
	env->wptex[4][1].img = SDL_LoadBMP("img/weapons/autogun2.bmp");
	env->wptex[4][2].img = SDL_LoadBMP("img/weapons/gunfire.bmp");
	env->wptex[4][3].img = SDL_LoadBMP("img/cage.bmp");
	i = 0;
	while (i < WEAPON_TEXTURES_BFG)
	{
		if (!env->wptex[4][i].img)
			ft_error("missing or corrupted BFG texture(s).", env, 0);
		i++;
	}
}
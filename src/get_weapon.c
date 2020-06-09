/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_weapons.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:03:15 by apons             #+#    #+#             */
/*   Updated: 2020/01/31 12:03:15 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

/*
** "reload" and "speed" are the frames required to reload or fire
** with a specific weapon. when actual time gets used to play the
** animations this will be much better.
*/

t_weapon	get_weapon_fist(void)
{
	t_weapon	fist;

	fist.name = "Fists";
	init_stat(&fist.clip.size, INFINITE, INFINITE);
	fist.clip.reload = 1;
	init_stat(&fist.ammo, INFINITE, INFINITE);
	fist.attack.type = WEAPON_TYPE_SEMIAUTO;
	fist.attack.damage = 10;
	fist.attack.range = 0.5;
	init_stat(&fist.attack.delay, 500, 0);
	fist.attack.radius.width = 0;
	fist.attack.radius.width = 0;
	fist.offset = 0;
	return (fist);
}

t_weapon	get_weapon_pistol(void)
{
	t_weapon	pistol;

	pistol.name = "Pistol";
	init_stat(&pistol.clip.size, 12, 12);
	pistol.clip.reload = 1750;
	init_stat(&pistol.ammo, 120, 60);
	pistol.attack.type = WEAPON_TYPE_SEMIAUTO;
	pistol.attack.damage = 12;
	pistol.attack.range = 7;
	init_stat(&pistol.attack.delay, 150, 0);
	pistol.attack.radius.width = 0;
	pistol.attack.radius.depth = 0;
	pistol.offset = 50;
	return (pistol);
}

t_weapon	get_weapon_shotgun(void)
{
	t_weapon	shotgun;

	shotgun.name = "Shotgun";
	init_stat(&shotgun.clip.size, 4, 4);
	shotgun.clip.reload = 3250;
	init_stat(&shotgun.ammo, 32, 16);
	shotgun.attack.type = WEAPON_TYPE_SEMIAUTO;
	shotgun.attack.damage = 50;
	shotgun.attack.range = 3;
	init_stat(&shotgun.attack.delay, 1200, 0);
	shotgun.attack.radius.width = 0.5;
	shotgun.attack.radius.depth = 0;
	shotgun.offset = 0;
	return (shotgun);
}

t_weapon	get_weapon_submachinegun(void)
{
	t_weapon	submachinegun;

	submachinegun.name = "SMG";
	init_stat(&submachinegun.clip.size, 30, 30);
	submachinegun.clip.reload = 2250;
	init_stat(&submachinegun.ammo, 300, 150);
	submachinegun.attack.type = WEAPON_TYPE_AUTOMATIC;
	submachinegun.attack.damage = 9;
	submachinegun.attack.range = 6;
	init_stat(&submachinegun.attack.delay, 100, 0);
	submachinegun.attack.radius.width = 0;
	submachinegun.attack.radius.depth = 0;
	submachinegun.offset = 50;
	return (submachinegun);
}

t_weapon	get_weapon_bfg(void)
{
	t_weapon	bfg;

	bfg.name = "BFG";
	init_stat(&bfg.clip.size, 1, 1);
	bfg.clip.reload = 2500;
	init_stat(&bfg.ammo, 2, 2);
	bfg.attack.type = WEAPON_TYPE_CHARGED;
	bfg.attack.damage = 250;
	bfg.attack.range = 20;
	init_stat(&bfg.attack.delay, 850, 0);
	bfg.attack.radius.width = 1.5;
	bfg.attack.radius.depth = 1.5;
	bfg.offset = 0;
	return (bfg);
}

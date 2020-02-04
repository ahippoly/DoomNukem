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

#include "../includes/gameplay.h"

/*
** "reload" and "speed" are the frames required to reload or fire
** with a specific weapon. when actual time gets used to play the
** animations this will be much better.
*/

t_weapon	get_fist(void)
{
	t_weapon	fist;

	fist.name = "Fists";
	fist.clip.size.max = INFINITE;
	fist.clip.size.current = INFINITE;
	fist.clip.reload = 0;
	fist.ammo.max = INFINITE;
	fist.ammo.current = INFINITE;
	fist.attack.type = WEAPON_TYPE_MELEE;
	fist.attack.damage = 10;
	fist.attack.range = 0.4;
	fist.attack.speed = 10;
	fist.attack.radius.width = 0;
	fist.attack.radius.width = 0;
	return (fist);
}

t_weapon	get_pistol(void)
{
	t_weapon	pistol;

	pistol.name = "Pistol";
	pistol.clip.size.max = 12;
	pistol.clip.size.current = 12;
	pistol.clip.reload = 60;
	pistol.ammo.max = 120;
	pistol.ammo.current = 60;
	pistol.attack.type = WEAPON_TYPE_SEMIAUTO;
	pistol.attack.damage = 10;
	pistol.attack.range = 7;
	pistol.attack.speed = 3;
	pistol.attack.radius.width = 0;
	pistol.attack.radius.depth = 0;
	return (pistol);
}

t_weapon	get_shotgun(void)
{
	t_weapon	shotgun;

	shotgun.name = "Shotgun";
	shotgun.clip.size.max = 4;
	shotgun.clip.size.current = 4;
	shotgun.clip.reload = 100;
	shotgun.ammo.max = 32;
	shotgun.ammo.current = 16;
	shotgun.attack.type = WEAPON_TYPE_SEMIAUTO;
	shotgun.attack.damage = 100; 
	shotgun.attack.range = 1;
	shotgun.attack.speed = 40;
	shotgun.attack.radius.width = 0.5;
	shotgun.attack.radius.depth = 0;
	return (shotgun);
}

t_weapon	get_submachinegun(void)
{
	t_weapon	submachinegun;

	submachinegun.name = "Submachine gun";
	submachinegun.clip.size.max = 30;
	submachinegun.clip.size.current = 30;
	submachinegun.clip.reload = 80;
	submachinegun.ammo.max = 300;
	submachinegun.ammo.current = 150;
	submachinegun.attack.type = WEAPON_TYPE_AUTOMATIC;
	submachinegun.attack.damage = 9;
	submachinegun.attack.range = 6;
	submachinegun.attack.speed = 1;
	submachinegun.attack.radius.width = 0;
	submachinegun.attack.radius.depth = 0;
	return (submachinegun);
}

t_weapon	get_bfg(void)
{
	t_weapon	bfg;

	bfg.name = "bfg";
	bfg.clip.size.max = 1;
	bfg.clip.size.current = 1;
	bfg.clip.reload = 150;
	bfg.ammo.max = 3;
	bfg.ammo.current = 3;
	bfg.attack.type = WEAPON_TYPE_CHARGED;
	bfg.attack.damage = 1000;
	bfg.attack.range = 10;
	bfg.attack.speed = 120;
	bfg.attack.radius.width = 1.5;
	bfg.attack.radius.depth = 1.5;
	return (bfg);
}
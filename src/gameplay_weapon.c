/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_weapon.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 18:34:27 by ahippoly          #+#    #+#             */
/*   Updated: 2020/06/29 01:43:56 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

// void init_weapons(t_data *d)
// {
// 	t_weapon *weapon;

// 	weapon = &d->weapon_list[WEAPON_FIST_ID];
// 	weapon->id = WEAPON_FIST_ID;
// 	weapon->attack_range = WEAPON_FIST_RANGE;
// 	weapon->attack_delay = WEAPON_FIST_DELAY;
// 	weapon->damage = WEAPON_FIST_DAMAGE;
// 	weapon->z_force = WEAPON_FIST_Z_FORCE;
// 	weapon->time = 0;

// 	d->actual_weapon = &d->weapon_list[WEAPON_DEFAULT];
// }

void anim_reload(t_data *d)
{
	d->sprite[d->gun_ind].time = SDL_GetTicks();
	d->sprite[d->gun_ind].index = RELOAD;
	d->sprite[d->gun_ind].on = 0;
	d->sprite[d->gun_ind].aim_on = 0;
	d->sprite[d->gun_ind].anim_end = 0;
	if (d->gun_ind > 0 && d->gun_ind < 5)
		play_sound(d, d->gun_ind + 5);
}

void reload_weapon(t_data *d, t_weapon *weapon)
{
	if (!weapon->is_reloading)
	{
		weapon->time = d->time + weapon->reload_delay;
		weapon->is_reloading = 1;
		anim_reload(d);
	}
}


void anim_weapon(t_data *d)
{
	d->sprite[d->gun_ind].time = d->time;
	if (d->sprite[d->gun_ind].aim_on == 0)
		d->sprite[d->gun_ind].index = FIRE;
	else if (d->gun_ind == 3 || d->gun_ind == 4)
		d->sprite[d->gun_ind].index = AIMFIRE;
	d->sprite[d->gun_ind].on = 0;
	d->sprite[d->gun_ind].anim_end = 0;
	printf("sound played\n");
	play_sound(d, d->gun_ind);
}

void shoot_attempt(t_data *d, t_weapon *weapon)
{
	// printf("diff time = %i\n", d->time - weapon->time);
	if (weapon->ammo_left > 0)
	{
		if (d->time - weapon->time > weapon->attack_delay)
		{
			shoot_gun(d, weapon);
			if (weapon->shoot_repeat == 1)
				d->shoot_repeat = 1;
			weapon->time = d->time;
			weapon->ammo_left -= 1;
			anim_weapon(d);
		}
	}
	else
		reload_weapon(d, weapon);
}


void aim_gun(t_data *d)
{
	if (d->gun_ind == 3 || d->gun_ind == 4)
	{
		d->sprite[d->gun_ind].time = SDL_GetTicks();
		d->sprite[d->gun_ind].index = AIM;
		d->sprite[d->gun_ind].on = 0;
		if (d->sprite[d->gun_ind].aim_on == 0)
			d->sprite[d->gun_ind].aim_on = 1;
		else
			d->sprite[d->gun_ind].aim_on = 0;
	}
}

void process_gun(t_weapon *weapon, int time, t_data *d)
{
	if (weapon->is_reloading)
	{
		// printf("weap time = %i, time = %i\n", weapon->time, time);
		if (time - weapon->time > 0)
		{
			weapon->ammo_left = weapon->capacity;
			weapon->is_reloading = 0;
		}
	}
	if (d->shoot_repeat && weapon->shoot_repeat)
	{
		shoot_attempt(d, weapon);
	}
}
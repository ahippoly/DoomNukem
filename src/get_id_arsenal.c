/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_id_arsenal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:38:43 by apons             #+#    #+#             */
/*   Updated: 2020/03/05 15:38:43 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

/*
** These functions apply the necessary texture according to (mostly) time
** and are used by get_id_weapon_texture (weapon_draw.c)
*/

int		get_id_arsenal_s(int id, double cur, double max, int side)
{
	if (id == 0)
	{
		if (cur >= max * 0.95 || (cur < max * 0.15))
			return (1 + side);
		return (2 + side);
	}
	if (cur >= max * 0.80)
		return (1);
	if (cur >= max * 0.60)
		return (2);
	if (cur >= max * 0.40)
		return (3);
	return (4);
}

int		get_id_arsenal_xl(int id, double cur, double max)
{
	if (id == 2)
	{
		if (cur >= max * 0.85)
			return (1);
		if (cur >= max * 0.70 || (cur < max * 0.10))
			return (0);
		if (cur >= max * 0.60 || (cur >= max * 0.10 && cur < max * 0.20))
			return (2);
		if (cur >= max * 0.50 || (cur >= max * 0.20 && cur < max * 0.30))
			return (3);
		return (4);
	}
	if (cur >= max * 0.66)
		return (1);
	if (cur >= max * 0.33)
		return (2);
	return (0);
}

int		get_id_bfg_charging(double cur, double max)
{
	if (cur >= max * 0.90)
		return (1);
	if (cur >= max * 0.80)
		return (2);
	if (cur >= max * 0.70)
		return (3);
	if (cur >= max * 0.60)
		return (4);
	if (cur >= max * 0.50)
		return (5);
	if (cur >= max * 0.40)
		return (6);
	if (cur >= max * 0.30)
		return (7);
	if (cur >= max * 0.20)
		return (8);
	if (cur >= max * 0.10)
		return (9);
	return (10);
}

int		get_id_arsenal_bfg(double cur, double max, int state)
{
	if (state == WEAPON_STATE_CHARGING)
		return (get_id_bfg_charging(cur, max * 2));
	if (cur >= max * 0.55)
		return (11);
	if (cur >= max * 0.40)
		return (12);
	if (cur >= max * 0.20)
		return (13);
	return (14);
}

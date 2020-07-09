/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_weapon2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 11:58:20 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/09 11:58:45 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void	aim_gun(t_data *d)
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
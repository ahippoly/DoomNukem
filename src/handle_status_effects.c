/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_status_effects.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:29:07 by apons             #+#    #+#             */
/*   Updated: 2020/02/03 14:29:07 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

/*
** These functions handle the status effects
*/

void		apply_stat_eff(t_buff *effect, int id, double value, int duration)
{
	effect->value[id] = ft_max(effect->value[id], value);
	effect->duration[id] = ft_max(effect->duration[id], duration);
}

void		countdown_status_effect_one(t_buff *effect, int delay)
{
	int i;

	i = 0;
	while (i < EFFECT_AMOUNT)
	{
		effect->duration[i] = ft_max(effect->duration[i] - delay, 0);
		if (!effect->duration[i])
			effect->value[i] = 0;
		i++;
	}
}

void		countdown_status_effect_all(t_status *status, int delay)
{
	countdown_status_effect_one(&status->dmg_resist, delay);
	countdown_status_effect_one(&status->att_dmg, delay);
	countdown_status_effect_one(&status->att_spd, delay);
}

void		clean_status_effect(t_buff *effect)
{
	int i;

	i = 0;
	while (i < EFFECT_AMOUNT)
	{
		effect->value[i] = 0;
		effect->duration[i] = 0;
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_effects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:29:07 by apons             #+#    #+#             */
/*   Updated: 2020/02/03 14:29:07 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gameplay.h"

/*
** These functions modify either the player's or the npcs' stats
*/

double		get_modifier(t_buff buff)
{
	double	amp;
	int i;

	amp = 1.0;
	i = 0;
	while (i++ < 4)
		amp += buff.value[0];
	return (amp);
}

void	apply_status_effect(t_buff status, int id,double value, int duration)
{

}

void		handle_status(t_status *effects)
{
	
}
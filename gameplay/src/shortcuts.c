/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:24:50 by apons             #+#    #+#             */
/*   Updated: 2020/02/05 15:24:50 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gameplay.h"

void	init_stat(t_stat *stat, int max, int current)
{
	stat->current = current;
	stat->max = max;
}

void	init_att_stat_basic(t_attack *att, int dmg, double spd, int range)
{

}
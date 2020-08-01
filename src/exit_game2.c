/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 11:13:19 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/17 14:18:39 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void	free_img(t_img *img, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (img[i].pixels)
			free(img[i].pixels);
		i++;
	}
}

void	free_mobs_sprite(t_data *d)
{
	int i;

	i = 0;
	while (i < d->nb_mob)
	{
		free(d->mobs[i].sprite.dst);
		i++;
	}
}

void	free_img_list(t_data *d)
{
	free_img(d->img, NB_IMG);
	free_img(d->texture, NB_TEXTURE);
	free_img(d->sprite_img, 2);
}

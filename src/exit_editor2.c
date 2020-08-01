/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_editor2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:12:46 by robin             #+#    #+#             */
/*   Updated: 2020/07/17 14:15:22 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

static void		free_img_pixel(t_txt_img *img, int size)
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

static void		free_button_pixel(t_button *but, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(but[i].normal.pixels);
		free(but[i].hovered.pixels);
		i++;
	}
}

void			free_sprites_edit(t_env *e)
{
	free(e->sprites[SPRITE_ID_AFRIT].dst);
	free(e->sprites[SPRITE_ID_PYRO].dst);
	free_img(e->sprite_img, 2);
	free_img_pixel(e->txt_lst, NB_TXT);
	free_button_pixel(e->buttons_lst, NB_BUTTONS);
}

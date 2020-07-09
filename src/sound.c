/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <alebui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:50:11 by alebui            #+#    #+#             */
/*   Updated: 2020/07/09 15:04:44 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

static void	init_system_sound(t_data *d)
{
	FMOD_System_Create(&d->system);
	FMOD_System_Init(d->system, 2, FMOD_INIT_NORMAL, NULL);
}

static void	channel_set_volume(t_data *d)
{
	FMOD_CHANNELGROUP *channel;

	FMOD_System_GetMasterChannelGroup(d->system, &channel);
	FMOD_ChannelGroup_SetVolume(channel, 0.3);
}

void		clean_sounds(t_data *d)
{
	int		i;

	i = 0;
	while (i < MAX_SOUNDS)
	{
		FMOD_Sound_Release(d->sound[i]);
		d->sound[i] = NULL;
		i++;
	}
	FMOD_System_Close(d->system);
	FMOD_System_Release(d->system);
}

int			play_sound(t_data *d, int index)
{
	FMOD_System_PlaySound(d->system, d->sound[index], 0, 0, NULL);
	return (0);
}

void		init_sound(t_data *d)
{
	init_system_sound(d);
	process_create_sound0(d);
	process_create_sound1(d);
	channel_set_volume(d);
	FMOD_Sound_SetLoopCount(d->sound[MUS1], -1);
	FMOD_Sound_SetLoopCount(d->sound[MUS2], -1);
}

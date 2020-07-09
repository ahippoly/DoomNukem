/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <alebui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 15:02:42 by alebui            #+#    #+#             */
/*   Updated: 2020/07/09 15:13:40 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void	process_create_sound0(t_data *d)
{
	FMOD_System_CreateSound(d->system, MELEESHORT_PATH,
		FMOD_CREATESAMPLE, 0, &d->sound[MELEESHORT]);
	FMOD_System_CreateSound(d->system, REVSHORT_PATH,
		FMOD_CREATESAMPLE, 0, &d->sound[REVSHORT]);
	FMOD_System_CreateSound(d->system,
		SHOTGUNSHORT_PATH, FMOD_CREATESAMPLE, 0, &d->sound[SHOTGUNSHORT]);
	FMOD_System_CreateSound(d->system,
		ARLONG_PATH, FMOD_CREATESAMPLE, 0, &d->sound[ARLONG]);
	FMOD_System_CreateSound(d->system,
		LMGLONG_PATH, FMOD_CREATESAMPLE, 0, &d->sound[LMGLONG]);
	FMOD_System_CreateSound(d->system,
		DDLONG_PATH, FMOD_CREATESAMPLE, 0, &d->sound[DDLONG]);
	FMOD_System_CreateSound(d->system,
		REVRELOAD_PATH, FMOD_CREATESAMPLE, 0, &d->sound[REVRELOAD]);
}

void	process_create_sound1(t_data *d)
{
	FMOD_System_CreateSound(d->system,
		SHOTGUNRELOAD_PATH, FMOD_CREATESAMPLE, 0, &d->sound[SHOTGUNRELOAD]);
	FMOD_System_CreateSound(d->system,
		ARRELOAD_PATH, FMOD_CREATESAMPLE, 0, &d->sound[ARRELOAD]);
	FMOD_System_CreateSound(d->system,
		LMGRELOAD_PATH, FMOD_CREATESAMPLE, 0, &d->sound[LMGRELOAD]);
	FMOD_System_CreateSound(d->system,
		ARSHORT_PATH, FMOD_CREATESAMPLE, 0, &d->sound[ARSHORT]);
	FMOD_System_CreateSound(d->system,
		LMGSHORT_PATH, FMOD_CREATESAMPLE, 0, &d->sound[LMGSHORT]);
	FMOD_System_CreateSound(d->system,
		DDSHORT_PATH, FMOD_CREATESAMPLE, 0, &d->sound[DDSHORT]);
	FMOD_System_CreateSound(d->system,
		MUS_PATH1, FMOD_2D | FMOD_CREATESTREAM | FMOD_LOOP_NORMAL,
		0, &d->sound[MUS1]);
	FMOD_System_CreateSound(d->system,
		MUS_PATH2, FMOD_2D | FMOD_CREATESTREAM | FMOD_LOOP_NORMAL,
		0, &d->sound[MUS2]);
}

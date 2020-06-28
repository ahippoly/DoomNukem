#include "proto_global.h"


void	stop_sound(t_data *d, int index)
{
	FMOD_CHANNEL *channel;
	FMOD_BOOL etat;

	FMOD_System_GetChannel(d->system, index, &channel);

	FMOD_Channel_GetPaused(channel, &etat);
	FMOD_Channel_SetPaused(channel, 1);
}

int		play_sound(t_data *d, int index)
{
	FMOD_System_PlaySound(d->system, d->sound[index], 0, 0, NULL);
	return (0);
}

void    init_sound(t_data *d)
{
	FMOD_CHANNELGROUP *channel;

	FMOD_System_Create(&d->system);
	FMOD_System_Init(d->system, 2, FMOD_INIT_NORMAL, NULL);

	FMOD_System_CreateSound(d->system, MELEESHORT_PATH, FMOD_CREATESAMPLE, 0, &d->sound[MELEESHORT]);
	FMOD_System_CreateSound(d->system, REVSHORT_PATH, FMOD_CREATESAMPLE, 0, &d->sound[REVSHORT]);
	FMOD_System_CreateSound(d->system, SHOTGUNSHORT_PATH, FMOD_CREATESAMPLE, 0, &d->sound[SHOTGUNSHORT]);
	FMOD_System_CreateSound(d->system, ARLONG_PATH, FMOD_CREATESAMPLE, 0, &d->sound[ARLONG]);
	FMOD_System_CreateSound(d->system, LMGLONG_PATH, FMOD_CREATESAMPLE, 0, &d->sound[LMGLONG]);
	FMOD_System_CreateSound(d->system, DDLONG_PATH, FMOD_CREATESAMPLE, 0, &d->sound[DDLONG]);
	FMOD_System_CreateSound(d->system, REVRELOAD_PATH, FMOD_CREATESAMPLE, 0, &d->sound[REVRELOAD]);
	FMOD_System_CreateSound(d->system, SHOTGUNRELOAD_PATH, FMOD_CREATESAMPLE, 0, &d->sound[SHOTGUNRELOAD]);
	FMOD_System_CreateSound(d->system, ARRELOAD_PATH, FMOD_CREATESAMPLE, 0, &d->sound[ARRELOAD]);
	FMOD_System_CreateSound(d->system, LMGRELOAD_PATH, FMOD_CREATESAMPLE, 0, &d->sound[LMGRELOAD]);
	FMOD_System_CreateSound(d->system, ARSHORT_PATH, FMOD_CREATESAMPLE, 0, &d->sound[ARSHORT]);
	FMOD_System_CreateSound(d->system, LMGSHORT_PATH, FMOD_CREATESAMPLE, 0, &d->sound[LMGSHORT]);
	FMOD_System_CreateSound(d->system, DDSHORT_PATH, FMOD_CREATESAMPLE, 0, &d->sound[DDSHORT]);
	

	FMOD_System_CreateSound(d->system, WALKSOUND_PATH, FMOD_CREATESAMPLE, 0, &d->sound[WALKSOUND]);
	FMOD_System_CreateSound(d->system, RUNSOUND_PATH, FMOD_CREATESAMPLE, 0, &d->sound[RUNSOUND]);
	FMOD_System_CreateSound(d->system, JUMPSOUND_PATH, FMOD_CREATESAMPLE, 0, &d->sound[JUMPSOUND]);
	FMOD_System_CreateSound(d->system, PLAYERDEATHSCREAM_PATH, FMOD_CREATESAMPLE, 0, &d->sound[PLAYERDEATHSCREAM]);
	FMOD_System_CreateSound(d->system, PLAYERPAIN_PATH, FMOD_CREATESAMPLE, 0, &d->sound[PLAYERPAIN]);
	FMOD_System_CreateSound(d->system, PLAYERBREATH_PATH, FMOD_CREATESAMPLE, 0, &d->sound[PLAYERBREATH]);
	FMOD_System_CreateSound(d->system, AFRITROAR_PATH, FMOD_CREATESAMPLE, 0, &d->sound[AFRITROAR]);
	FMOD_System_CreateSound(d->system, PYROROAR_PATH, FMOD_CREATESAMPLE, 0, &d->sound[PYROROAR]);


	FMOD_System_CreateSound(d->system, MUS_PATH1, FMOD_2D | FMOD_CREATESTREAM | FMOD_LOOP_NORMAL, 0, &d->sound[MUS1]);


	FMOD_System_GetMasterChannelGroup(d->system, &channel);
	FMOD_ChannelGroup_SetVolume(channel, 0.3);

	FMOD_Sound_SetLoopCount(d->sound[MUS1], -1);
}

void	clean_sounds(t_data *d)
{
	int i;

	i = 0;
	while (i < MAX_SOUNDS)
	{
		FMOD_Sound_Release(d->sound[i]);
		d->sound[i] = NULL;
		i++;
	}
	FMOD_System_Close(system);
	FMOD_System_Release(system);
}
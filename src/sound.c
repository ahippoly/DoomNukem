#include "proto_global.h"
#include "proto_global.h"
#include "proto_global.h"
#include "proto_global.h"
#include "proto_global.h"

int    play_sound(t_data *d, int index)
{
	FMOD_System_PlaySound(d->system, d->sound[index],0, 0, NULL);
    return (0);
}


void    init_sound(t_data *d)
{
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
	
	FMOD_System_CreateSound(d->system, MUS_PATH1, FMOD_CREATESAMPLE, 0, &d->sound[MUS1]);

	/* Free */
	//FMOD_Sound_Release(&sound[MELEESHORT]);

	//FMOD_System_Close(system);
	//FMOD_System_Release(system);
}
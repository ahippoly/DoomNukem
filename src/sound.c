#include "global_header.h"
#include "render.h"
#include "editor.h"
#include "img_file.h"
#include "sprite.h"


static Uint8 *audio_pos;
static Uint32 audio_len;

void my_audio_callback(void *userdata, Uint8 *stream, int len) 
{	
	if (audio_len == 0)
		return;
	
	len = (len > audio_len ? audio_len : len);
	SDL_memcpy (stream, audio_pos, len); 					// simply copy from one buffer into the other
	SDL_MixAudio(stream, audio_pos, len, SDL_MIX_MAXVOLUME);// mix from one buffer into another
	
	audio_pos += len;
	audio_len -= len;
}

int    play_sound(t_data *d, int index)
{
	if (!(audio_pos = d->sound[index].wav_buffer))
        return (1);
	if (!(audio_len = d->sound[index].wav_length))
        return (1);

	if (SDL_OpenAudio(&d->sound[index].wav_spec, NULL) < 0)
	  printf("couldnt open audio = %d\n", index);
	SDL_PauseAudio(0);
    return (0);
}

void    load_sounds(t_data *d)
{
    int i;

    i = 0;
    while (i < 8)
    {
    d->sound[i].wav_spec.callback = my_audio_callback;
	d->sound[i].wav_spec.userdata = NULL;
    i++;
    }
}

void    init_sound(t_data *d)
{
    if (SDL_Init(SDL_INIT_AUDIO) < 0)
	    ft_putendl("error initializing audio");
    if(SDL_LoadWAV(MELEESHORT_PATH, &d->sound[MELEESHORT].wav_spec, &d->sound[MELEESHORT].wav_buffer, &d->sound[MELEESHORT].wav_length) == NULL)
	    ft_putendl("error loading audio8");
    if(SDL_LoadWAV(REVSHORT_PATH, &d->sound[REVSHORT].wav_spec, &d->sound[REVSHORT].wav_buffer, &d->sound[REVSHORT].wav_length) == NULL)
	    ft_putendl("error loading audio7");
    if(SDL_LoadWAV(SHOTGUNSHORT_PATH, &d->sound[SHOTGUNSHORT].wav_spec, &d->sound[SHOTGUNSHORT].wav_buffer, &d->sound[SHOTGUNSHORT].wav_length) == NULL)
	    ft_putendl("error loading audio9");
	if(SDL_LoadWAV(ARLONG_PATH, &d->sound[ARLONG].wav_spec, &d->sound[ARLONG].wav_buffer, &d->sound[ARLONG].wav_length) == NULL)
	    ft_putendl("error loading audio1");
	if(SDL_LoadWAV(LMGLONG_PATH, &d->sound[LMGLONG].wav_spec, &d->sound[LMGLONG].wav_buffer, &d->sound[LMGLONG].wav_length) == NULL)
	    ft_putendl("error loading audio5");
    if(SDL_LoadWAV(DDLONG_PATH, &d->sound[DDLONG].wav_spec, &d->sound[DDLONG].wav_buffer, &d->sound[DDLONG].wav_length) == NULL)
	    ft_putendl("error loading audio3");
	
    if(SDL_LoadWAV(REVRELOAD_PATH, &d->sound[REVRELOAD].wav_spec, &d->sound[REVRELOAD].wav_buffer, &d->sound[REVRELOAD].wav_length) == NULL)
	    ft_putendl("error loading audio10");    
    if(SDL_LoadWAV(SHOTGUNRELOAD_PATH, &d->sound[SHOTGUNRELOAD].wav_spec, &d->sound[SHOTGUNRELOAD].wav_buffer, &d->sound[SHOTGUNRELOAD].wav_length) == NULL)
	    ft_putendl("error loading audio10");
    if(SDL_LoadWAV(ARRELOAD_PATH, &d->sound[ARRELOAD].wav_spec, &d->sound[ARRELOAD].wav_buffer, &d->sound[ARRELOAD].wav_length) == NULL)
	    ft_putendl("error loading audio10");
    if(SDL_LoadWAV(LMGRELOAD_PATH, &d->sound[LMGRELOAD].wav_spec, &d->sound[LMGRELOAD].wav_buffer, &d->sound[LMGRELOAD].wav_length) == NULL)
	    ft_putendl("error loading audio10");


    if(SDL_LoadWAV(ARSHORT_PATH, &d->sound[ARSHORT].wav_spec, &d->sound[ARSHORT].wav_buffer, &d->sound[ARSHORT].wav_length) == NULL)
	    ft_putendl("error loading audio2");
    if(SDL_LoadWAV(DDSHORT_PATH, &d->sound[DDSHORT].wav_spec, &d->sound[DDSHORT].wav_buffer, &d->sound[DDSHORT].wav_length) == NULL)
	    ft_putendl("error loading audio4");
    if(SDL_LoadWAV(LMGSHORT_PATH, &d->sound[LMGSHORT].wav_spec, &d->sound[LMGSHORT].wav_buffer, &d->sound[LMGSHORT].wav_length) == NULL)
	    ft_putendl("error loading audio6");

    if(SDL_LoadWAV(MUS_PATH1, &d->sound[MUS1].wav_spec, &d->sound[MUS1].wav_buffer, &d->sound[MUS1].wav_length) == NULL)
	    ft_putendl("error loading audio10");

    load_sounds(d);
	//SDL_FreeWAV(d->sound[ARSHORT].wav_buffer);
}
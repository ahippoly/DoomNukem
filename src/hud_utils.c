#include "proto_global.h"

//OK
SDL_Surface		*copy_surface(t_data *d, SDL_Surface *src, t_hud *hud)
{
	SDL_Surface	*dest;
	Uint32		rmask;
	Uint32		gmask;
	Uint32		bmask;
	Uint32		amask;
	
	rmask = 0xff000000;
	gmask = 0x00ff0000;
	bmask = BLUE;
	amask = 0x000000ff;
	if (!hud)
		exit_game(d, "error : no hud loaded");
	if (!(dest = SDL_CreateRGBSurface(0, 30, 30, 32, rmask, gmask, bmask, amask)))
		exit_game(d, "error : failed to create rgb surface");
	if (dest != NULL)
	{
		if ((SDL_BlitSurface(src, NULL, dest, NULL)) < 0)
			exit_game(d, "error : failed to blit surface");
	}
	return (dest);
}

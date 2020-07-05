#include "proto_global.h"

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
	if (!(dest = SDL_CreateRGBSurface(0, 30, 30, 32, rmask, gmask, bmask, amask)))
	{
		printf("Erreur de chargement de l'image : %s", SDL_GetError());
		exit_hud(hud);
	}
	if (dest != NULL)
	{
		if (SDL_BlitSurface(src, NULL, dest, NULL))
			exit_hud(hud);
	}
	return (dest);
}

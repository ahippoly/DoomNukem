#include <hud.h>

SDL_Surface		*copy_surface(t_data *d, SDL_Surface *src, t_hud *hud)
{
	SDL_Surface *dest;

	if (!(dest = SDL_CreateRGBSurface(0, 30, 30, 32, 0, 0, 0, 0)))
	{
		printf("Erreur de chargement de l'image : %s", SDL_GetError());
		error(hud);
	}
	if (dest != NULL)
	{
		if (SDL_BlitSurface(src, NULL, dest, NULL))
			error(hud);
	}
	return (dest);
}

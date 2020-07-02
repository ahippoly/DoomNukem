#include "proto_global.h"

int				init_gameover_background(t_data *d)
{
	SDL_Surface	*surface;

	if (!(surface = SDL_LoadBMP(GAMEOVER_PATH)))
		return (exit_menu(d));
	if (!(d->menu.gameover_t = SDL_CreateTextureFromSurface(d->rend, surface)))
		return (exit_menu(d));
	SDL_FreeSurface(surface);
	return (0);
}

int				put_gameover_bg(t_data *d)
{
	if (SDL_RenderCopy(d->rend, d->menu.gameover_t, NULL, NULL))
	{
		printf("Erreur de render copy : %s", SDL_GetError());
		return (exit_menu(d));
	}
	return (0);
}

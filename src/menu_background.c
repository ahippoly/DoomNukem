#include "menu.h"

int				init_background(t_data *d)
{
	SDL_Surface	*surface;

	if (!(surface = SDL_LoadBMP(MENU_BG_PATH)))
		return (exit_menu(d));
	if (!(d->menu.menu_bg_t = SDL_CreateTextureFromSurface(d->rend, surface)))
		return (exit_menu(d));
	SDL_FreeSurface(surface);
	return (0);
}

int				put_menu_bg(t_data *d)
{
	if (SDL_RenderCopy(d->rend, d->menu.menu_bg_t, NULL, NULL))
	{
		printf("Erreur de render copy : %s", SDL_GetError());
		return (exit_menu(d));
	}
	return (0);
}
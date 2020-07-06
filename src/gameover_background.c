#include "proto_global.h"

int				init_gameover_background(t_data *d)
{
	SDL_Surface	*surface;

	if (!(surface = SDL_LoadBMP(GAMEOVER_PATH)))
		exit_game(d, "error : failed to load bmp for gameover background");
	if (!(d->menu.gameover_t = SDL_CreateTextureFromSurface(d->rend, surface)))
		exit_game(d, "error : failed to create texture");
	SDL_FreeSurface(surface);
	return (0);
}

int				put_gameover_bg(t_data *d)
{
	if ((SDL_RenderCopy(d->rend, d->menu.gameover_t, NULL, NULL)) < 0)
		exit_game(d, "error : failed to render copy");
	return (0);
}

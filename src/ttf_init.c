#include "hud.h"

int				init_ttf(t_data *d)
{
	if (TTF_Init() < 0)
	{
		printf("Erreur d'initialisation de la lib TTF : %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}
	d->font_nb = TTF_OpenFont("font/halflife2.ttf", 20);
	d->font_text = TTF_OpenFont("font/airborn.ttf", 20);
	d->hud.color.r = 255;
	d->hud.color.g = 229;
	d->hud.color.b = 41;
	d->hud.color.a = 180;
	return (0);
}

int				quit_ttf(t_data *d)
{
	if (d->font_text)
		TTF_CloseFont(d->font_text);
	if (d->font_nb)
		TTF_CloseFont(d->font_nb);
	TTF_Quit();
	return (0);
}
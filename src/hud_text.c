#include <hud.h>

int				init_ttf(t_hud *hud)
{
	if (TTF_Init() < 0)
	{
		printf("Erreur d'initialisation de la lib TTF : %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}
	// hud->font = TTF_OpenFont("font/keepcalm_font.ttf", 20);
	hud->font_nb = TTF_OpenFont("font/halflife2.ttf", 20);
	hud->font_text = TTF_OpenFont("font/airborn.ttf", 20);
	// hud->font_text = TTF_OpenFont("font/keepcalm_font.ttf", 20);
	hud->color.r = 255;
	hud->color.g = 229;
	hud->color.b = 41;
	hud->color.a = 180;
	return (0);
}

int				quit_ttf(t_hud *hud)
{
	if (hud->font_text)
		TTF_CloseFont(hud->font_text);
	if (hud->font_nb)
		TTF_CloseFont(hud->font_nb);
	TTF_Quit();
	return (0);
}


#include <hud.h>

int				init_ttf(t_hud *hud)
{
	if (TTF_Init() < 0)
	{
		printf("Erreur d'initialisation de la lib TTF : %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}
	hud->font = TTF_OpenFont("/font/keepcalm_font.ttf", 20);
	hud->color.r = 255;
	hud->color.g = 255;
	hud->color.b = 255;
	hud->color.a = 255;
	return (0);
}

int				quit_ttf(t_hud *hud)
{
	TTF_CloseFont(hud->font);
	TTF_Quit();		
}

void			display_text(t_data *d, t_hud *hud, char *message, SDL_Rect message_pos)
{
	SDL_Rect	tmp;

	if(!(hud->message_surface = TTF_RenderText_Solid(hud->font, message, hud->color)))
		printf("Erreur d'affichage du texte TTF : %s\n", TTF_GetError());
	if (!(hud->message_texture = SDL_CreateTextureFromSurface(d->rend, hud->message_surface)))
		printf("OULA Erreur de converstion de la surface : %s\n", SDL_GetError());
    SDL_FreeSurface(hud->message_surface);
	tmp = message_pos;
	SDL_RenderCopy(d->rend, hud->message_texture, NULL, &tmp);
}
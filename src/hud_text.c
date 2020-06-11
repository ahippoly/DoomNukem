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

void			put_text(t_data *d, t_hud *hud, int nb, SDL_Rect message_pos)
{
	SDL_Rect	tmp;
	char		*text;
	SDL_Texture	*t_cpy;
	SDL_Surface	*s_cpy;

	tmp = message_pos;
	
	text = ft_itoa(hud->perso_weapon[hud->current_weap_id]->ammo_left);
	if(!(s_cpy = TTF_RenderText_Solid(hud->font, text, hud->color)))
		printf("Erreur d'affichage du texte TTF : %s\n", TTF_GetError());
	if (!(t_cpy = SDL_CreateTextureFromSurface(d->rend, s_cpy)))
		printf("OULA Erreur de converstion de la surface : %s\n", SDL_GetError());
    SDL_FreeSurface(s_cpy);
	SDL_RenderCopy(d->rend, t_cpy, NULL, &tmp);
	SDL_DestroyTexture(t_cpy);
}

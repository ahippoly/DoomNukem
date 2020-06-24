#include "hud.h"

int					init_key_icon(t_data *d, t_hud *hud)
{
	SDL_Surface		*surface;

	if (!(surface = SDL_LoadBMP(KEY_PATH)))
	{
		printf("0 Erreur de chargement de l'image : %s", SDL_GetError());
		return (exit_hud(hud));
	}
	if (!(hud->inv.key_icon_t = SDL_CreateTextureFromSurface(d->rend, surface)))
	{
		printf("Erreur de conversion de la surface : %s", SDL_GetError());
		return (exit_hud(hud));
	}
	SDL_FreeSurface(surface);
	return (0);
}

int					put_key_icon(t_data *d, t_hud *hud, SDL_Rect pos)
{
	if (SDL_RenderCopy(d->rend, hud->inv.key_icon_t, NULL, &pos))
	{
		printf("Erreur render copy : %s", SDL_GetError());
		return (exit_hud(hud));
	}
	return (0);
}

int					set_key_info(t_data *d, t_hud *hud, int nb)
{
	SDL_Texture		*t_cpy;
	SDL_Surface		*s_cpy;	
	char			*text;

	text = ft_itoa(nb);
	if(!(s_cpy = TTF_RenderText_Blended(d->font_nb, text, hud->color)))
	{
		printf("Erreur d'affichage du texte TTF : %s\n", TTF_GetError());
		return (exit_hud(hud));
	}
	if (!(hud->inv.key_info_s = copy_surface(d, s_cpy, hud)))
	{
		printf("Erreur d'affichage du texte TTF : %s\n", TTF_GetError());
		return (exit_hud(hud));
	}
	SDL_FreeSurface(s_cpy);
	return (0);
}

int					render_key_info(t_data *d, t_hud *hud, SDL_Rect pos)
{
	if (!(hud->inv.key_info_t = SDL_CreateTextureFromSurface(d->rend, hud->inv.key_info_s)))
	{
		printf("Erreur de conversion de la surface : %s", SDL_GetError());
		return (exit_hud(hud));
	}
	if (SDL_RenderCopy(d->rend, hud->inv.key_info_t, NULL, &pos))
	{
		printf("Erreur render copy : %s", SDL_GetError());
		return (exit_hud(hud));
	}
	return (0);
}
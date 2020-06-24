#include "proto_global.h"

int					init_ammo_icon(t_data *d, t_hud *hud)
{
	SDL_Surface		*surface;

	if (!(surface = SDL_LoadBMP(AMMO_ICON_PATH)))
	{
		printf("Erreur de chargement de l'image : %s", SDL_GetError());
		return (exit_hud(hud));
	}
	if (!(hud->ammo_texture = SDL_CreateTextureFromSurface(d->rend, surface)))
	{
		printf("Erreur de conversion de la surface : %s", SDL_GetError());
		return (exit_hud(hud));
	}
	SDL_FreeSurface(surface);
	return (0);
}

int					put_ammo_icon(t_data *d, t_hud *hud, SDL_Rect pos)
{
	if (SDL_RenderCopy(d->rend, hud->ammo_texture, NULL, &pos))
	{
		printf("Erreur de render copy : %s", SDL_GetError());
		return (exit_hud(hud));
	}
	return (0);
}

int					set_ammo_info(t_data *d, t_hud *hud, int nb)
{
	SDL_Texture		*t_cpy;
	SDL_Surface		*s_cpy;	
	char			*text;
	
	if (nb <= 0)
		nb = 0;
	if (!(text = ft_itoa(nb)))
		return (exit_hud(hud));
	
	if(!(s_cpy = TTF_RenderText_Blended(d->font_nb, text, hud->color)))
	{
		printf("Erreur d'affichage du texte TTF : %s\n", TTF_GetError());
		return (exit_hud(hud));
	}
	if (!(hud->message_ammo_s = copy_surface(d, s_cpy, hud)))
		return (exit_hud(hud));
	SDL_FreeSurface(s_cpy);
	return (0);
}

int					render_ammo_info(t_data *d, t_hud *hud, SDL_Rect pos)
{
	SDL_Texture		*t_cpy;

	if (!(hud->message_ammo_t = SDL_CreateTextureFromSurface(d->rend, hud->message_ammo_s)))
	{
		printf("Erreur de conversion de la surface : %s", SDL_GetError());
		return (exit_hud(hud));
	}
	if (SDL_RenderCopy(d->rend, hud->message_ammo_t, NULL, &pos))
	{
		printf("Erreur de conversion de la surface : %s", SDL_GetError());
		return (exit_hud(hud));
	}
	return (0);
}

#include "proto_global.h"

/* initialise et creation de la texture pour l'icone de HP  */

int					init_health_icon(t_data *d, t_hud *hud)
{
	SDL_Surface		*surface;

	if (!(surface = SDL_LoadBMP(HEALTH_ICON_PATH)))
	{
		printf("Erreur de chargement de l'image : %s", SDL_GetError());
		return (exit_hud(hud));
	}
	if (!(hud->health_texture = SDL_CreateTextureFromSurface(d->rend, surface)))
	{
		printf("Erreur de conversion de la surface : %s", SDL_GetError());
		return (exit_hud(hud));
	}
	SDL_FreeSurface(surface);
	return (0);
}

int				put_health_icon(t_data *d, t_hud *hud, SDL_Rect pos)
{	
	if (SDL_RenderCopy(d->rend, hud->health_texture, NULL, &pos))
	{
		printf("Erreur de conversion de la surface : %s", SDL_GetError());
		return (exit_hud(hud));
	}
	return (0);
}

/* initialise et creation de la texture pour afficher le texte de HP  */

int					set_health_info(t_data *d, t_hud *hud, int nb)
{
	SDL_Surface		*s_cpy;	
	char			*text;

	if (nb <= 0)
		nb = 0;
	else if (nb > 100)
		nb = 100;
	if (!(text = ft_itoa(nb)))
		return (exit_hud(hud));
	if(!(s_cpy = TTF_RenderText_Blended(d->font_nb, text, hud->color)))
	{
		printf("Erreur d'affichage du texte TTF : %s\n", TTF_GetError());
		return (exit_hud(hud));
	}
	if (!(hud->message_health_s = copy_surface(s_cpy, hud)))
		return (exit_hud(hud));
	SDL_FreeSurface(s_cpy);
	return (0);
}

int				render_health_info(t_data *d, t_hud *hud, SDL_Rect pos)
{
	if (!(hud->message_health_t = SDL_CreateTextureFromSurface(d->rend, hud->message_health_s)))
	{
		printf("Erreur de conversion de la surface : %s", SDL_GetError());
		return (exit_hud(hud));
	}
	if (SDL_RenderCopy(d->rend, hud->message_health_t, NULL, &pos))
	{
		printf("Erreur Render Copy : %s", SDL_GetError());
		return (exit_hud(hud));
	}
	return (0);
}

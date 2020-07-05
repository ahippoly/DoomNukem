#include "proto_global.h"

int					init_health_pack(t_data *d, t_hud *hud)
{
	if (!(hud->inv.healthpack_icon_s = SDL_LoadBMP(HEALTHPACK_PATH)))
	{
		printf("Erreur de chargement de l'image : %s", SDL_GetError());
		return (exit_hud(hud));
	}
	if (!(hud->inv.healthpack_icon_t = SDL_CreateTextureFromSurface(d->rend, hud->inv.healthpack_icon_s)))
	{
		printf("Erreur de conversion de la surface : %s", SDL_GetError());
		return (exit_hud(hud));
	}
	SDL_FreeSurface(hud->inv.healthpack_icon_s);
	return (0);
}

int					put_healthpack_icon(t_data *d, t_hud *hud, SDL_Rect pos)
{
	if (SDL_RenderCopy(d->rend, hud->inv.healthpack_icon_t, NULL, &pos))
	{
		printf("Erreur Render Copy : %s", SDL_GetError());
		return (exit_hud(hud));
	}
	return (0);
}

int					set_healthpack_info(t_data *d, t_hud *hud, int nb)
{
	SDL_Surface		*s_cpy;	
	char			*text;

	if (!(text = ft_itoa(nb)))
		return (exit_hud(hud));
	if(!(s_cpy = TTF_RenderText_Blended(d->font_nb, text, hud->color)))
	{
		printf("Erreur d'affichage du texte TTF : %s\n", TTF_GetError());
		return (exit_hud(hud));
	}
	if (!(hud->inv.healthpack_info_s = copy_surface(s_cpy, hud)))
	{
		printf("Erreur d'affichage du texte TTF : %s\n", TTF_GetError());
		return (exit_hud(hud));
	}
	SDL_FreeSurface(s_cpy);
	return (0);
}

int				render_healthpack_info(t_data *d, t_hud *hud, SDL_Rect pos)
{
	if (!(hud->inv.healthpack_info_t = SDL_CreateTextureFromSurface(d->rend, hud->inv.healthpack_info_s)))
	{
		printf("Erreur de conversion de la surface : %s", SDL_GetError());
		return (exit_hud(hud));
	}
	if (SDL_RenderCopy(d->rend, hud->inv.healthpack_info_t, NULL, &pos))
	{
		printf("Erreur Render Copy : %s", SDL_GetError());
		return (exit_hud(hud));
	}
	return (0);
}
#include "hud.h"

static int		update_perso(t_data *d, t_hud *hud)
{
	ft_bzero(&hud->perso, sizeof(hud->perso));
	if (hud->current_perso_id == PERSO_F)
	{
		if (!(hud->perso.surface = SDL_LoadBMP(PERSO_PATH_0)))
		{
			printf("Erreur de chargement de l'image : %s", SDL_GetError());
			return (error(hud));
		}
	}
	else if (hud->current_perso_id == PERSO_M)
	{
		if (!(hud->perso.surface = SDL_LoadBMP(PERSO_PATH_1)))
		{
			printf("Erreur de chargement de l'image : %s", SDL_GetError());
			return (error(hud));
		}
	}
	else
		return (error(hud));
	return (0);
}

int				init_perso(t_data *d, t_hud *hud)
{
	update_perso(d, hud);
	if (!(hud->perso.texture = SDL_CreateTextureFromSurface(d->rend, hud->perso.surface)))
	{
		printf("Erreur de conversion de la surface : %s", SDL_GetError());
		return(error(hud));
	}
	SDL_FreeSurface(hud->perso.surface);
	hud->perso.hp_max = 100;
	hud->perso.hp = 100;
	return (0);
}

/* Affiche le perso à l'écran */
int				put_perso_icon(t_data *d, t_hud *hud, SDL_Rect pos)
{
	if (SDL_RenderCopy(d->rend, hud->perso.texture, NULL, &pos))
	{
		printf("Erreur de render copy : %s", SDL_GetError());
		return(error(hud));
	}
	return (0);
}
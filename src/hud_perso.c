#include "hud.h"

static int		malloc_perso(t_hud *hud)
{
	int			i;
	
	i = 0;
	hud->perso = NULL;
	if (!(hud->perso = (t_perso*)ft_memalloc(sizeof(t_perso))))
		return (NULL);
	ft_bzero(hud->perso, sizeof(t_perso));
	return (0);
}

static int		update_perso(t_data *d, t_hud *hud)
{
	if (hud->current_perso_id == 0)
	{
		if (!(hud->perso->surface = SDL_LoadBMP(PERSO_PATH_0)))
			printf("Erreur de chargement de l'image : %s", SDL_GetError());
	}
	else if (hud->current_perso_id == 1)
	{
		if (!(hud->perso->surface = SDL_LoadBMP(PERSO_PATH_1)))
			printf("Erreur de chargement de l'image : %s", SDL_GetError());
	}
	// else return error ?
	return (0);
}

void			init_perso(t_data *d, t_hud *hud)
{
	ft_putendl("malloc perso...");
	malloc_perso(hud);
	ft_putstr("init perso ");
	ft_putnbr(hud->current_perso_id);
	ft_putendl("...");
	update_perso(d, hud);
	if (!(hud->perso->texture = SDL_CreateTextureFromSurface(d->rend, hud->perso->surface)))
		printf("Erreur de conversion de la surface : %s", SDL_GetError());
	SDL_FreeSurface(hud->perso->surface);
	hud->perso->hp_max = 100;
	hud->perso->hp = 100;
}

/* Affiche le perso à l'écran */
int				put_perso(t_data *d, t_hud *hud)
{
	SDL_Rect	pos;

	pos = set_sdl_rect(10, 20, 80, 80);
	SDL_RenderCopy(d->rend, hud->perso->texture, NULL, &pos);
	return (0);
}
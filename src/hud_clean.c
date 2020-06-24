#include "hud.h"

static void	free_texture(t_hud *hud)
{
	int		i;

	i = 0;
	while (i < WEAPON_NB)
	{
		if (hud->perso_weapon[i]->texture)
			SDL_DestroyTexture(hud->perso_weapon[i]->texture);
		i++;
	}
	if (hud->perso.texture)
		SDL_DestroyTexture(hud->perso.texture);
	if (hud->message_ammo_t)
		SDL_DestroyTexture(hud->message_ammo_t);
	if (hud->message_health_t)
		SDL_DestroyTexture(hud->message_health_t);
	if (hud->health_texture)
		SDL_DestroyTexture(hud->health_texture);
	if (hud->ammo_texture)
		SDL_DestroyTexture(hud->ammo_texture);
	if (hud->ammo_texture)
		SDL_DestroyTexture(hud->t_perso_w);
}

void		free_hud(t_hud *hud)
{
	free_texture(hud);
	ft_putendl("destroy texture done.");
}

int			error(t_hud *hud)
{
	ft_putendl("traiting error...");
	free_hud(hud);
	SDL_Quit();
	ft_putendl("quit!");
	exit(-1);
}
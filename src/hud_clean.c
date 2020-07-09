#include "proto_global.h"

//ok
static void	free_texture(t_hud *hud)
{
	int		i;

	i = 0;
	while (i < WEAPON_NB)
	{
		if (hud->perso_weapon[i]->texture)
			SDL_DestroyTexture(hud->perso_weapon[i]->texture);
		if (hud->perso_weapon[i])
			free(hud->perso_weapon[i]);
		i++;
	}
	free(hud->perso_weapon);
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
	if (hud->message_health_s)
		free(hud->message_health_s);
	if (hud->inv.healthpack_info_s)
		free (hud->inv.healthpack_info_s);
}

void		free_hud(t_hud *hud)
{
	free_texture(hud);
}

// int			exit_hud(t_hud *hud)
// {
// 	free_hud(hud);
// 	SDL_Quit();
// 	ft_putendl("bye!");
// 	exit(-1);
// }
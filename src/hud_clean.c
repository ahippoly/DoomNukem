#include <hud.h>

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
	if (hud->perso->texture)
		SDL_DestroyTexture(hud->perso->texture);
}

void		free_hud(t_hud *hud)
{
	free_texture(hud);
	ft_putendl("destroy texture done.");
}
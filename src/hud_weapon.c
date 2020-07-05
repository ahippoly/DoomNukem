#include "proto_global.h"

static int		malloc_tab_weapons(t_hud *hud)
{
	int			i;
	
	i = 0;
	hud->perso_weapon = NULL;
	if (!(hud->perso_weapon = (t_weapon**)ft_memalloc(sizeof(t_weapon *) * WEAPON_NB)))
		return (exit_hud(hud));
	while (i < WEAPON_NB)
	{
		if (!(hud->perso_weapon[i] = (t_weapon *)malloc(sizeof(t_weapon))))
			return (exit_hud(hud));
		ft_bzero(hud->perso_weapon[i], sizeof(t_weapon));
		i++;
	}
	hud->perso_weapon[WEAPON_NB] = NULL;
	return (0);
}

int			init_weapons(t_data *d, t_hud *hud)
{
	malloc_tab_weapons(hud);
	init_weapon_0(d, hud);
	init_weapon_1(d, hud);
	init_weapon_2(d, hud);
	init_weapon_3(d, hud);
	init_weapon_4(d, hud);
	init_weapon_5(hud);
	d->actual_weapon = hud->perso_weapon[WEAPON_DEFAULT];
	return (0);
}

/* Afficher les armes à l'écran */
int				put_weapon_icon(t_data *d, t_hud *hud, SDL_Rect pos)
{
	if (d->gun_ind > 0)
	{
		hud->current_weap_id = d->gun_ind - 1;
		if (SDL_RenderCopy(d->rend, hud->perso_weapon[hud->current_weap_id]->texture, NULL, &pos))
		{
			printf("Erreur render copy : %s", SDL_GetError());
			return (exit_hud(hud));
		}
	}
	return (0);
}

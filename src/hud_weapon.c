#include <hud.h>

static int		malloc_tab_weapons(t_hud *hud)
{
	int			i;
	
	i = 0;
	hud->perso_weapon = NULL;
	if (!(hud->perso_weapon = (t_weapon**)ft_memalloc(sizeof(t_weapon *) * WEAPON_NB)))
		return (NULL);
	while (i < WEAPON_NB)
	{
		if (!(hud->perso_weapon[i] = (t_weapon *)malloc(sizeof(t_weapon))))
			return (NULL);
		ft_bzero(hud->perso_weapon[i], sizeof(t_weapon));
		i++;
	}
	hud->perso_weapon[WEAPON_NB] = NULL;
	return (0);
}

void			init_weapons(t_data *d, t_hud *hud)
{
	ft_putendl("malloc weapons...");
	malloc_tab_weapons(hud);
	ft_putendl("init weapons...");
	init_weapon_0(d, hud);
	init_weapon_1(d, hud);
	init_weapon_2(d, hud);
	init_weapon_3(d, hud);
	init_weapon_4(d, hud);
}

/* Afficher les armes à l'écran */
int				put_weapon(t_data *d, t_hud *hud)
{
	SDL_Rect	pos;
	
	pos = set_sdl_rect(50, WIN_SIZE_Y - (WIN_SIZE_Y / 4), 80, 80);
	SDL_RenderCopy(d->rend, hud->perso_weapon[hud->current_weap_id]->texture, NULL, &pos);
	return (0);
}
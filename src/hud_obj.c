#include <hud.h>

//SG HERE
static void		**malloc_tab_weapons(t_hud *hud)
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
}

void			init_weapons(t_hud *hud, t_data *d)
{
	ft_putendl("malloc weapons...");
	malloc_tab_weapons(hud);
	ft_putendl("init weapons...");
	init_weapon_0(hud, d);
	init_weapon_1(hud, d);
	init_weapon_2(hud, d);
	init_weapon_3(hud, d);
	init_weapon_4(hud, d);
}
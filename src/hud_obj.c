#include <hud.h>

/*
int				put_obj(t_data *d, t_hud *hud, SDL_Rect size)
{
	if (!(hud->s_ammo = SDL_LoadBMP("/img/hud/handgun.bmp")))
		printf("Erreur de chargement de l'image : %s", SDL_GetError());
	if (!(hud->t_ammo = SDL_CreateTextureFromSurface(d->rend, hud->s_ammo)))
		printf("Erreur de conversion de la surface : %s", SDL_GetError());
}
*/

void			init_weapon(t_weapon *weapon)
{
	
}

t_weapon		**init_weapon()
{
	t_weapon	**weapon;
	
	weapon = NULL;
	if (!(weapon = (t_weapon**)ft_memalloc(sizeof(t_weapon*) * 3)))
		return (NULL);
	
	return (weapon);
}
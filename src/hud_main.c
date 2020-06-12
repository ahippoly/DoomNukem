#include "hud.h"

void			init_hud(t_data *d, t_hud *hud)
{
	ft_bzero(hud, sizeof(hud));
	hud->current_weap_id = 0; //initialisation de l'arme, a enlever si on commence à 0
	hud->current_perso_id = 1; // recuperer dynamiquement les perso 
	ft_putendl("initing weapons...");
	init_weapons(d, hud);
	hud->perso_weapon[hud->current_weap_id]->ammo_left = hud->perso_weapon[hud->current_weap_id]->capacity;
	ft_putendl("initing perso...");
	init_perso(d, hud);
}

/* print items transparent background*/
int				put_background(t_data *d)
{
	SDL_Rect	size;

	size = set_sdl_rect(50, WIN_SIZE_Y - (WIN_SIZE_Y / 4) - 10, 400, 100);
	SDL_SetRenderDrawColor(d->rend, 255, 255, 255, 50);
	return (0);
}

/* Récupérer les paramètre des munitions */
/*
int				put_ammunition(t_data *d, t_hud *hud)
{
	SDL_Rect	size;
	
	size = set_sdl_rect(50, WIN_SIZE_Y - (WIN_SIZE_Y / 4), 80, 80);
	if (!(hud->s_ammo = SDL_LoadBMP("/img/hud/ammunition1.bmp")))
		printf("Erreur de chargement de l'image : %s", SDL_GetError());
	if (!(hud->t_ammo = SDL_CreateTextureFromSurface(d->rend, hud->s_ammo)))
		printf("Erreur de conversion de la surface : %s", SDL_GetError());
    SDL_FreeSurface(hud->s_ammo);
	SDL_RenderCopy(d->rend, hud->t_ammo, NULL, &size);
	return (0);
}
*/

int 			main(void)
{
    t_map_data  map;
    t_data      d;
	t_hud		hud;
	SDL_Rect	size;
	int			tmp;
	int			i;

	map = read_map("maps/editor_map_0");
	init_data(&d);
	init_hud(&d, &hud);
	init_ttf(&hud);
	d.bullet = 0;
	size = set_sdl_rect(50, WIN_SIZE_Y - (WIN_SIZE_Y / 4) - 10, 400, 100);
	i = 0;
	while (!d.quit)
	{
		tmp = d.bullet;
		ft_bzero(d.p_screen, WIN_SIZE_X * WIN_SIZE_Y * 4);
		SDL_PumpEvents();
		handle_key_event(&d, &map);
		handle_poll_event(&d, &map);
		// put_lifebar(&d);
		// put_background(&d);
		// put_ammunition(&d, &hud);

		/* affichage du text a refactor */		
		if (i == 0)
		{
			set_text(&d, &hud, hud.perso_weapon[hud.current_weap_id]->ammo_left);
			render_text(&d, &hud, set_sdl_rect(500, 500, 50, 50));
		}
		else if (d.bullet > tmp)
		{
			if (hud.perso_weapon[hud.current_weap_id]->ammo_left > 0)
				hud.perso_weapon[hud.current_weap_id]->ammo_left = hud.perso_weapon[hud.current_weap_id]->capacity - d.bullet;
			else if (hud.perso_weapon[hud.current_weap_id]->ammo_left <= 0)
				hud.perso_weapon[hud.current_weap_id]->ammo_left = 0;
			set_text(&d, &hud, hud.perso_weapon[hud.current_weap_id]->ammo_left);
			SDL_RenderClear(d.rend);
			render_text(&d, &hud, set_sdl_rect(500, 500, 50, 50));
		}
		else
			render_text(&d, &hud, set_sdl_rect(500, 500, 50, 50));
		/* fin affichage du text */
		put_perso(&d, &hud);
		put_weapon(&d, &hud);

		SDL_SetRenderDrawBlendMode(d.rend, SDL_BLENDMODE_BLEND);
		SDL_RenderFillRect(d.rend, &size);

		SDL_UpdateTexture(d.screen, NULL, d.p_screen, WIN_SIZE_X * 4);
 		SDL_RenderPresent(d.rend);
		i++;
    }
	quit_ttf(&hud);
	free_hud(&hud);
	SDL_Quit();
	return (0);
}
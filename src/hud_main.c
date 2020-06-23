#include "hud.h"

int				init_hud(t_data *d, t_hud *hud)
{
	ft_bzero(hud, sizeof(hud));
	hud->current_weap_id = 1; // initialisation de l'arme, a enlever si on commence à 0
	if (hud->current_weap_id < 0 || hud->current_weap_id >= 5)
		hud->current_weap_id = 0;
	hud->current_perso_id = 7; // recuperer dynamiquement les perso 
	if (hud->current_perso_id != PERSO_F || hud->current_perso_id != PERSO_M)
		hud->current_perso_id = PERSO_F; // recuperer dynamiquement les perso 
	init_weapons(d, hud);
	hud->perso_weapon[hud->current_weap_id]->ammo_left = hud->perso_weapon[hud->current_weap_id]->capacity;
	init_perso(d, hud);
	init_health_icon(d, hud);
	init_ammo_icon(d, hud);
	init_health_pack(d, hud);
	init_key_icon(d, hud);
	hud->hp = 100;
	hud->inv.health_pack = 0;
	hud->inv.key = 0;
	return (0);
}

/* print items transparent background*/
int				put_background(t_data *d)
{

	SDL_SetRenderDrawColor(d->rend, 255, 255, 255, 50);
	return (0);
}

void			render_hud_icons(t_data *d, t_hud *hud)
{
	put_perso_icon(d, hud, set_sdl_rect(10, 700, 50, 50));
	put_health_icon(d, hud, set_sdl_rect(80, 720, 30, 30));
	put_ammo_icon(d, hud, set_sdl_rect(190, 720, 30, 30));
	put_weapon_icon(d, hud, set_sdl_rect(290, 720, 100, 30));
	put_healthpack_icon(d, hud, set_sdl_rect(700, 720, 30, 30));
	put_key_icon(d, hud, set_sdl_rect(700, 670, 30, 30));
}

void			render_hud_info(t_data *d, t_hud *hud)
{
	render_health_info(d, hud, set_sdl_rect(120, 715, 50, 50));
	render_ammo_info(d, hud, set_sdl_rect(230, 715, 50, 50));
	render_healthpack_info(d, hud, set_sdl_rect(740, 715, 50, 50));
	render_key_info(d, hud, set_sdl_rect(740, 665, 50, 50));
}

void			update_hud_info(t_hud *hud)
{
	set_ammo_info(hud, hud->perso_weapon[hud->current_weap_id]->ammo_left);
	set_health_info(hud, hud->hp);
	set_healthpack_info(hud, hud->inv.health_pack);
	set_key_info(hud, hud->inv.key);
}

// int 			main(int ac, char **av)
// {
//     t_map_data  map;
//     t_data      d;
// 	t_hud		hud;
// 	int			tmp;
// 	int			i;

// 	map = read_map("maps/editor_map_0");
// 	init_data(&d, ac, av);
// 	init_hud(&d, &hud);
// 	init_ttf(&hud);
// 	d.bullet = 0;
// 	i = 0;
// 		SDL_SetRenderDrawBlendMode(d.rend, SDL_BLENDMODE_BLEND);
// 	while (!d.quit)
// 	{
// 		tmp = d.bullet;
// 		ft_bzero(d.p_screen, WIN_SIZE_X * WIN_SIZE_Y * 4);
// 		SDL_PumpEvents();
// 		handle_key_event(&d, &map);
// 		handle_poll_event(&d, &map);

// 		if (d.bullet > tmp) // met à jour HP et AMMO lorsqu'un evenement (ici touche espace) est reçu (temporaire)
// 		{
// 			hud.perso_weapon[hud.current_weap_id]->ammo_left = hud.perso_weapon[hud.current_weap_id]->capacity - d.bullet;
// 			hud.hp -= d.bullet;
// 		}
// 		update_hud_info(&d, &hud);
// 		render_hud_info(&d, &hud);
// 		render_hud_icons(&d, &hud);
// 		// SDL_UpdateTexture(d.screen, NULL, d.p_screen, WIN_SIZE_X * 4);
//  		SDL_RenderPresent(d.rend);
//     }
// 	quit_ttf(&hud);
// 	free_hud(&hud);
// 	SDL_Quit();
// 	return (0);
// }

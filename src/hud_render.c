#include "proto_global.h"

void	render_hud_icons(t_data *d)
{
	put_perso_icon(d, &d->hud, set_sdl_rect(10, 700, 50, 50));
	put_health_icon(d, &d->hud, set_sdl_rect(80, 720, 30, 30));
	put_ammo_icon(d, &d->hud, set_sdl_rect(190, 720, 30, 30));
	put_weapon_icon(d, &d->hud, set_sdl_rect(290, 720, 100, 30));
	put_healthpack_icon(d, &d->hud, set_sdl_rect(700, 720, 30, 30));
	put_key_icon(d, &d->hud, set_sdl_rect(700, 670, 30, 30));
}

void	render_hud_info(t_data *d)
{
	render_health_info(d, &d->hud, set_sdl_rect(120, 715, 50, 50));
	render_ammo_info(d, &d->hud, set_sdl_rect(230, 715, 50, 50));
	render_healthpack_info(d, &d->hud, set_sdl_rect(740, 715, 50, 50));
	render_key_info(d, &d->hud, set_sdl_rect(740, 665, 50, 50));
}

void	update_hud_info(t_data *d)
{
	set_ammo_info(d, &d->hud, d->actual_weapon->ammo_left);
	set_health_info(d, &d->hud, d->hud.hp);
	set_healthpack_info(d, &d->hud, d->hud.inv.health_pack);
	set_key_info(d, &d->hud, d->hud.inv.key);
}

void	render_hud(t_data *d)
{
	update_hud_info(d);
	render_hud_icons(d);
	render_hud_info(d);
}	

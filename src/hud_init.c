#include "proto_global.h"

int				init_hud_data(t_data *d)
{
	d->hud.current_weap_id = d->gun_ind; // initialisation de l'arme, a enlever si on commence à 0
	d->hud.current_perso_id = 1; // recuperer dynamiquement les perso 
	if (d->hud.current_perso_id != PERSO_F || d->hud.current_perso_id != PERSO_M)
		d->hud.current_perso_id = PERSO_F; // recuperer dynamiquement les perso 
	init_weapons(d, &d->hud);
	// printf("weap id = %i\n", d->hud.current_weap_id);
	d->hud.perso_weapon[d->hud.current_weap_id]->ammo_left = d->hud.perso_weapon[d->hud.current_weap_id]->capacity;
	init_perso(d, &d->hud);
	init_health_icon(d, &d->hud);
	init_ammo_icon(d, &d->hud);
	init_health_pack(d, &d->hud);
	init_key_icon(d, &d->hud);
	d->hud.hp = 100;
	d->hud.inv.health_pack = 0;
	d->hud.inv.key = 0;
	return (0);
}
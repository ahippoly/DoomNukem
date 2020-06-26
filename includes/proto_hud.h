#ifndef PROTO_HUD_H
# define PROTO_HUD_H

#include "data.h"

/* hud_clean.c */

void				free_hud(t_hud *hud);
int					exit_hud(t_hud *hud);

/* hud_weapons.c */

int					init_weapons(t_data *d, t_hud *hud);
int					put_weapon_icon(t_data *d, t_hud *hud, SDL_Rect pos);
void				set_weapon_name(t_data *d, t_hud *hud, SDL_Rect pos);
void				render_weapon_name(t_data *d, t_hud *hud, SDL_Rect pos);

/* hud_weapons_init.c */

int					init_weapon_0(t_data *d, t_hud *hud);
int					init_weapon_1(t_data *d, t_hud *hud);
int					init_weapon_2(t_data *d, t_hud *hud);
int					init_weapon_3(t_data *d, t_hud *hud);
int					init_weapon_4(t_data *d, t_hud *hud);

/* hud_perso.c */

int					init_perso(t_data *d, t_hud *hud);
int					put_perso_icon(t_data *d, t_hud *hud, SDL_Rect pos);

/* hud_health.c */

int					init_health_icon(t_data *d, t_hud *hud);
int					put_health_icon(t_data *d, t_hud *hud, SDL_Rect pos);
int					set_health_info(t_data *d, t_hud *hud, int nb);
int					render_health_info(t_data *d, t_hud *hud, SDL_Rect pos);

/* hud_ammo.c */

int					init_ammo_icon(t_data *d, t_hud *hud);
int					put_ammo_icon(t_data *d, t_hud *hud, SDL_Rect pos);
int					set_ammo_info(t_data *d, t_hud *hud, int nb);
int					render_ammo_info(t_data *d, t_hud *hud, SDL_Rect pos);

/*  hud utils */

SDL_Surface			*copy_surface(t_data *d, SDL_Surface *src, t_hud *hud);

/* hud_inv.c */

int					init_health_pack(t_data *d, t_hud *hud);
int					put_healthpack_icon(t_data *d, t_hud *hud, SDL_Rect pos);
int					render_healthpack_info(t_data *d, t_hud *hud, SDL_Rect pos);
int					set_healthpack_info(t_data *d, t_hud *hud, int nb);

/* hud_inv1.c */

int					init_key_icon(t_data *d, t_hud *hud);
int					put_key_icon(t_data *d, t_hud *hud, SDL_Rect pos);
int					set_key_info(t_data *d, t_hud *hud, int nb);
int					render_key_info(t_data *d, t_hud *hud, SDL_Rect pos);

/* hud_render.c */

void				update_hud_info(t_data *d);
void				render_hud_info(t_data *d);
void				render_hud_icons(t_data *d);


#endif
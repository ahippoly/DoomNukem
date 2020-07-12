/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 23:05:27 by robin             #+#    #+#             */
/*   Updated: 2020/07/05 23:06:21 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUD_H
# define HUD_H

# include "render.h"

/*
** Colors
*/

# define HEALTH_BG 0x1DB100
# define HEALTH 0x76f013
# define HUD_TEXT 0xF1D130

# define TITLE_HUD 0x89fc00
# define TEXT_HUD 0xFFE529

# define BLACK 0
# define WHITE 0xFFFFFF

/*
** Weapons
*/

# define WEAPON_NB		6
# define WEAPON_PATH_0	"asset/img/hud/revolver.bmp"
# define WEAPON_PATH_1	"asset/img/hud/ssg.bmp"
# define WEAPON_PATH_2	"asset/img/hud/ar.bmp"
# define WEAPON_PATH_3	"asset/img/hud/lmg.bmp"
# define WEAPON_PATH_4	"asset/img/hud/death_dealer.bmp"

# define WEAPON_NAME_0	"REVOLVER"
# define WEAPON_NAME_1	"SSG"
# define WEAPON_NAME_2	"AR"
# define WEAPON_NAME_3	"LMG"
# define WEAPON_NAME_4	"DEATH_DEALER"
# define WEAPON_NAME_5	"FIST"

# define WEAPON_DEFAULT 0

# define WEAPON_FIST_ID 1
# define WEAPON_FIST_RANGE 1
# define WEAPON_FIST_DAMAGE 10
# define WEAPON_FIST_Z_FORCE 0.05
# define WEAPON_FIST_DELAY 100

# define WEAPON_SSG_ID 0
# define WEAPON_SSG_RANGE 5
# define WEAPON_SSG_DAMAGE 3
# define WEAPON_SSG_Z_FORCE 0.02
# define WEAPON_SSG_DELAY 100

/*
** perso
*/

# define PERSO_NAME_0 "Loni"
# define PERSO_NAME_1 "Ray"

# define PERSO_F 0
# define PERSO_M 1

# define PERSO_PATH_0 "asset/img/hud/perso_w.bmp"
# define PERSO_PATH_1 "asset/img/hud/perso_m.bmp"

/*
** other hud icons
*/

# define HEALTH_ICON_PATH "asset/img/hud/health.bmp"
# define AMMO_ICON_PATH "asset/img/hud/bullet.bmp"

/*
** inventory
*/

# define HEALTHPACK_PATH "asset/img/hud/doctor.bmp"
# define KEY_PATH "asset/img/hud/key.bmp"

typedef struct		s_weapon
{
	int				id;
	int				dammage;
	int				attack_delay;
	int				time;
	float			z_force;
	float			range;
	int				ammo_left;
	int				capacity;
	int				reload_delay;
	char			is_reloading;
	char			shoot_repeat;
	char			*name;
	SDL_Surface		*surface;
	SDL_Texture		*texture;
}					t_weapon;

typedef struct		s_perso
{
	int				hp_max;
	int				hp;
	SDL_Surface		*surface;
	SDL_Texture		*texture;
}					t_perso;

typedef struct		s_inv
{
	SDL_Texture		*healthpack_icon_t;
	SDL_Texture		*healthpack_info_t;
	SDL_Texture		*key_icon_t;
	SDL_Texture		*key_info_t;
	SDL_Surface		*healthpack_icon_s;
	SDL_Surface		*healthpack_info_s;
	SDL_Surface		*key_info_s;
	int				health_pack;
	int				key;
}					t_inv;

typedef struct		s_hud
{
	int				current_weap_id;
	int				current_perso_id;
	int				hp;
	SDL_Surface		*s_perso_w;
	SDL_Surface		*message_ammo_s;
	SDL_Surface		*message_health_s;
	SDL_Texture		*message_ammo_t;
	SDL_Texture		*health_texture;
	SDL_Texture		*ammo_texture;
	SDL_Texture		*message_health_t;
	SDL_Texture		*t_perso_w;
	t_weapon		**perso_weapon;
	t_perso			perso;
	SDL_Color		color;
	t_inv			inv;
}					t_hud;

#endif

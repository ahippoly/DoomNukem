#ifndef HUD_H
# define HUD_H

# include "global_header.h"
# include "render.h"
# include "img_file.h"
# include "editor.h"
# include "SDL_ttf.h"

/* Colors */

# define HEALTH_BG 0x1DB100
# define HEALTH 0x76f013
# define HUD_TEXT 0xF1D130

# define BLACK 0
# define WHITE 0xFFFFFF
# define DAYSKY 0x2FC4EE
# define NIGHTSKY 0x084B83
# define DAYFLOOR 0xC5B087
# define NIGHTFLOOR 0x081c15
# define DAY_HUD 0x253237
# define NIGHT_HUD 0x5500a8
# define TITLE_HUD 0x89fc00
# define TEXT_HUD 0xFFE529
# define BEYOND_MAP 0x42321b
# define FLOOR 0xC5B087
# define RAY 0x89fc00
# define BLUE 0xd00000
# define BLOC_COLOR 0x1B9E77

/* weapons */

# define WEAPON_NB		5
# define WEAPON_PATH_0	"img/hud/ssg.bmp"
# define WEAPON_PATH_1	"img/hud/ar.bmp"
# define WEAPON_PATH_2	"img/hud/dd.bmp"
# define WEAPON_PATH_3	"img/hud/revolver.bmp"
# define WEAPON_PATH_4	"img/hud/lmg.bmp"

# define WEAPON_NAME_0	"LMG"
# define WEAPON_NAME_1	"AR"
# define WEAPON_NAME_2	"DD"
# define WEAPON_NAME_3	"REVOLVER"
# define WEAPON_NAME_4	"SSG"

/* perso */

# define PERSO_NAME_0 "Loni"
# define PERSO_NAME_1 "Ray"

# define PERSO_F 0
# define PERSO_M 1

# define PERSO_PATH_0 "img/hud/perso_w.bmp"
# define PERSO_PATH_1 "img/hud/perso_m.bmp"

/* other hud icons */

# define HEALTH_ICON_PATH "img/hud/health.bmp"
# define AMMO_ICON_PATH "img/hud/bullet.bmp"

/* inventory */

# define HEALTHPACK_PATH "img/hud/doctor.bmp"
# define KEY_PATH "img/hud/key.bmp"

typedef struct		s_weapon
{
	int				id;
	int				dammage; // pts de dégat
	int				range; // portée d'une arme
	int				ammo_left; // munitions restantes
	char			*name;
	int				capacity; // capacité max de chargement
	SDL_Surface 	*surface;
	SDL_Texture 	*texture;
}					t_weapon;

typedef struct		s_perso
{
	int				hp_max; //health point max
	int				hp; //health point
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
	TTF_Font		*font_nb;
	TTF_Font		*font_text;
	SDL_Surface 	*s_perso_w;
	SDL_Surface		*message_ammo_s;
	SDL_Surface		*message_health_s;
	SDL_Texture		*message_ammo_t;
	SDL_Texture		*health_texture; //icon health
	SDL_Texture		*ammo_texture; //icon ammo
	SDL_Texture		*message_health_t;
	SDL_Texture 	*t_perso_w;
	t_weapon		**perso_weapon;
	t_perso			perso;
	SDL_Color		color;
	t_inv			inv;
}					t_hud;


/* hud_text.c */

int					init_ttf(t_hud *hud);
int					quit_ttf(t_hud *hud);

/* hud_clean.c */

void				free_hud(t_hud *hud);
void				free_hud_weapon(t_hud *hud);
int					error(t_hud *hud);

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


int				init_hud(t_data *d, t_hud *hud);
int				put_background(t_data *d);
void			render_hud_icons(t_data *d, t_hud *hud);
void			render_hud_info(t_data *d, t_hud *hud);
void			update_hud_info(t_data *d, t_hud *hud);

void check_props_collect(t_data *d, t_props *props, t_hud *hud);

#endif
#ifndef HUD_H
# define HUD_H

# include "render.h"
# include "img_file.h"
# include "global_header.h"
# include "editor.h"
# include "SDL_ttf.h"

/* Colors */

# define HEALTH_BG 0x1DB100
# define HEALTH 0x76f013

/* weapons */

# define WEAPON_NB		6
# define WEAPON_PATH_0	"/img/hud/handgun.bmp"
# define WEAPON_PATH_1	"/img/hud/goldengun.bmp"
# define WEAPON_PATH_2	"/img/hud/handgun.bmp"
# define WEAPON_PATH_3	"/img/hud/handgun.bmp"
# define WEAPON_PATH_4	"/img/hud/handgun.bmp"

# define WEAPON_NAME_0	"LMG"
# define WEAPON_NAME_1	"AR"
# define WEAPON_NAME_2	"DD"
# define WEAPON_NAME_3	"REVOLVER"
# define WEAPON_NAME_4	"SSG"

/* perso */

# define PERSO_NAME_0 "Loni"
# define PERSO_NAME_1 "Ray"

# define PERSO_PATH_0 "/img/hud/perso_w.bmp"
# define PERSO_PATH_1 "/img/hud/perso_m.bmp"


typedef struct	s_weapon
{
	int			id;
	char		*name;
	int			ammo_left; // munitions restantes
	int			capacity; // capacité max de chargement
	int			dammage; // pts de dégat
	int			range; // portée d'une arme
	SDL_Surface *surface;
	SDL_Texture *texture;
}				t_weapon;

typedef struct	s_perso
{
	int			hp_max; //health point max
	int			hp; //health point
	SDL_Surface	*surface;
	SDL_Texture	*texture;
}				t_perso;

typedef struct	s_hud
{
	int			current_weap_id;
	int			current_perso_id;
	t_weapon	**perso_weapon;
	t_perso		*perso;
	SDL_Surface *s_perso_w;
	SDL_Texture *t_perso_w;
	TTF_Font	*font;
	SDL_Color	color;
}				t_hud;


/* hud_text.c */

int				put_text(t_data *d, t_hud *hud);
int				init_ttf(t_hud *hud);
int				quit_ttf(t_hud *hud);
void			display_text(t_data *d, t_hud *hud, char *message, SDL_Rect message_pos);

/* hud_clean.c */

void			free_hud(t_hud *hud);
void			free_hud_weapon(t_hud *hud);

/* hud_weapons.c */

void			init_weapons(t_data *d, t_hud *hud);
int				put_weapon(t_data *d, t_hud *hud);

/* hud_weapons_init.c */

void			init_weapon_0(t_data *d, t_hud *hud);
void			init_weapon_1(t_data *d, t_hud *hud);
void			init_weapon_2(t_data *d, t_hud *hud);
void			init_weapon_3(t_data *d, t_hud *hud);
void			init_weapon_4(t_data *d, t_hud *hud);

/* hud_perso.c */

void			init_perso(t_data *d, t_hud *hud);
int				put_perso(t_data *d, t_hud *hud);

#endif
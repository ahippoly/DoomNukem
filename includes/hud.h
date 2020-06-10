#ifndef HUD_H
# define HUD_H

# include "render.h"
# include "img_file.h"
# include "global_header.h"
# include "editor.h"
# include "SDL_ttf.h"

# define HEALTH_BG 0x1DB100
# define HEALTH 0x76f013

// typedef struct	s_ammo
// {
// 	int			left;
// 	int			capacity;
// 	int			damage;
// }				t_ammo;

typedef struct	s_weapon
{
	char		*path;
	char		*name;
	int			ammo_left;
	int			capacity;
	int			dammage;

}				t_weapon;

typedef struct	s_perso
{
	char		*path;
	char		*name;
}				t_perso;

typedef struct	s_hud
{
	SDL_Surface *s_ammo;
	SDL_Surface *s_perso_w;
	SDL_Surface *ammo_text;
	SDL_Texture *t_ammo;
	SDL_Texture *t_perso_w;
	TTF_Font	*font;
	SDL_Color	color;
}				t_hud;


/* hud_text */
int				put_text(t_data *d, t_hud *hud);
int				init_ttf(t_hud *hud);
int				quit_ttf(t_hud *hud);
void			display_text(t_data *d, t_hud *hud, char *message, SDL_Rect message_pos);

#endif
#ifndef MENU_H
# define MENU_H

# include "render.h"

# define MENU_BG_PATH "asset/img/menu/jail_bg1.bmp"

typedef struct		s_menu
{
	char			**argv_tab; //tab pour enregistrer les arguments et les passer a execv
	SDL_Texture		*menu_bg_t;
	SDL_Texture		*btn;
	SDL_Texture		*text0_t;
	SDL_Texture		*text1_t;
	SDL_Texture		*text2_t;
}					t_menu;

#endif
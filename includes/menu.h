#ifndef MENU_H
# define MENU_H

# include "render.h"

# define MENU_BG_PATH "img/menu/jail_bg1.bmp"
# define GAMEOVER_PATH "img/menu/jail_gameover.bmp"

typedef struct		s_menu
{
	char			**argv_tab; //tab pour enregistrer les arguments et les passer a execv
	char			**argv_over_tab;
	SDL_Texture		*menu_bg_t;
	SDL_Texture		*gameover_t;
	SDL_Texture		*btn;
	SDL_Texture		*play_t;
	SDL_Texture		*editor_t;
	SDL_Texture		*quit_t;
	SDL_Texture		*over_continue_t;
	SDL_Texture		*over_quit_t;
}					t_menu;

#endif
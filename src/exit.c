#include "proto_global.h"

void exit_env(t_data *d)
{
	ft_putendl("exiting...");

	/* menu */
	free_menu(d);
	
	/* hud */
	free_hud(&d->hud);

	/* sprite */
	//clean_sprite_gun(d);

	/* editor */

	/* sound*/
	clean_sounds(d);

	/* doom */

	/* SDL */
	quit_ttf(d);
	SDL_Quit();
	exit(0);
}
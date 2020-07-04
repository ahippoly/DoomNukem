#include "proto_global.h"

void exit_game(t_data *d, char *msg)
{
	ft_putendl(msg);

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
	ft_putendl("bye !");
	exit(0);
}
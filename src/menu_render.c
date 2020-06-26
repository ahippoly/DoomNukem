#include "proto_global.h"

int				main(int ac, char **av)
{
    t_data		d;
	
	init_data(&d, ac, av);
	init_background(&d);
	SDL_SetRenderDrawBlendMode(d.rend, SDL_BLENDMODE_BLEND);
	while (!d.quit)
	{
		SDL_PumpEvents();
		handle_key_event(&d);
		handle_poll_event(&d);
		put_menu_bg(&d);
		render_btn(&d);
		catch_btn_event(&d, ac, av);
 		SDL_RenderPresent(d.rend);
	}
	exit_env(&d);
	return (0);
}
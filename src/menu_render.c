#include "render.h"

int				main(int ac, char **av)
{
    t_data		d;
	t_map_data	map;
	
	init_data(&d, ac, av);
	ft_putendl("Welcome in the MENU ...");
	init_background(&d);
	SDL_SetRenderDrawBlendMode(d.rend, SDL_BLENDMODE_BLEND);
	while (!d.quit)
	{	
		SDL_PumpEvents();
		handle_key_event(&d, &map);
		handle_poll_event(&d, &map);
		put_menu_bg(&d);
		render_btn(&d);
		catch_btn_event(&d, ac, av);
 		SDL_RenderPresent(d.rend);
	}
	return (0);
}

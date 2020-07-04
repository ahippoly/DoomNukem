#include "proto_global.h"

int	render_gameover(t_data *d, int ac, char **av)
{
	init_data(d, ac, av); // reinitialise la data à la fin du jeu tout en conservant les arguments
	SDL_SetRelativeMouseMode(SDL_FALSE);
	while (d->run_game == GAMEOVER)
	{
		SDL_PumpEvents();
		handle_key_event(d);
		handle_poll_event(d);
		put_gameover_bg(d);
		render_gameover_button(d, av);
		catch_over_btn_event(d, av);
    	SDL_RenderPresent(d->rend);
	}
	return (0);
}
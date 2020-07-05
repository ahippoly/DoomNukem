#include "proto_global.h"

int	render_menu(t_data *d)
{
	SDL_PumpEvents();
	handle_key_event(d);
	handle_poll_event(d);
	put_menu_bg(d);
	render_btn(d);
	catch_btn_event(d);
	SDL_RenderPresent(d->rend);
	return (0);
}
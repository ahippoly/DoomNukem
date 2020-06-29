#include "proto_global.h"

int	render_gameover(t_data *d)
{
	put_gameover_bg(d);
	render_gameover_button(d);
	catch_over_btn_event(d);
    // SDL_RenderPresent(d->rend);
}
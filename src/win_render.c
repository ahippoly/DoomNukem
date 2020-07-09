#include "proto_global.h"

int		render_win_button(t_data *d)
{
	int	btn_y;
	int	text_x;
	int	text_y;

	btn_y = WIN_SIZE_Y / 2;
	text_x = WIN_SIZE_X / 2 - 30;
	text_y = WIN_SIZE_Y / 2 + 10;

	render_bg_btn(d, set_sdl_rect(WIN_SIZE_X / 2 - 100, btn_y, 200, 50));
	render_text_btn(d, set_sdl_rect(text_x, text_y, 0, 0), d->menu.over_continue_t, "MENU");
	render_bg_btn(d, set_sdl_rect(WIN_SIZE_X / 2 - 100, btn_y + 100, 200, 50));
	render_text_btn(d, set_sdl_rect(text_x, text_y + 100, 0, 0), d->menu.over_quit_t, "QUIT");
	return (0);
}

int		catch_win_btn_event(t_data *d)
{
	if (is_mouse_on_target(d, set_sdl_rect(WIN_SIZE_X / 2 - 100, WIN_SIZE_Y / 2, 200, 50)) == 1) //try again
		d->run_game = MENU;
	else if (is_mouse_on_target(d, set_sdl_rect(WIN_SIZE_X / 2 - 100, WIN_SIZE_Y / 2 + 100, 200, 50)) == 1) //quit
		d->run_game = -1;
	return (0);
}

int	render_win(t_data *d)
{
	SDL_SetRelativeMouseMode(SDL_FALSE);
	SDL_PumpEvents();
	handle_key_event(d);
	handle_poll_event(d);
	put_bg(d, d->menu.win_t);
	render_win_button(d);
	catch_win_btn_event(d);
	SDL_RenderPresent(d->rend);
	return (0);
}
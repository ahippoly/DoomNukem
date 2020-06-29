#include "proto_global.h"

int		render_gameover_button(t_data *d)
{
	int	btn_y;
	int	text_x;
	int	text_y;

	btn_y = WIN_SIZE_Y / 2;
	text_x = WIN_SIZE_X / 2 - 30;
	text_y = WIN_SIZE_Y / 2 + 10;

	render_bg_btn(d, set_sdl_rect(WIN_SIZE_X / 2 - 100, btn_y, 200, 50));
	render_text_btn(d, set_sdl_rect(text_x, text_y, 0, 0), d->menu.over_continue_t, "CONTINUE");
	render_bg_btn(d, set_sdl_rect(WIN_SIZE_X / 2 - 100, btn_y + 100, 200, 50));
	render_text_btn(d, set_sdl_rect(text_x, text_y + 100, 0, 0), d->menu.over_quit_t, "QUIT");
	return (0);
}

int		catch_over_btn_event(t_data *d)
{
	if (is_mouse_on_target(d, set_sdl_rect(WIN_SIZE_X / 2 - 100, WIN_SIZE_Y / 2, 200, 50)) == 1) //continue
	{
		// recharge bien la map
		if (execv("./doom-nukem", d->menu.argv_tab) && access("./doom-nukem", W_OK))
			return (exit_menu(d));
	}
	if (is_mouse_on_target(d, set_sdl_rect(WIN_SIZE_X / 2 - 100, WIN_SIZE_Y / 2 + 100, 200, 50)) == 1) //quit
	{
		// il n'y a plus de map a charger
		if (execv("./menu", d->menu.argv_tab) && access("./menu", W_OK))
			return (exit_menu(d));
	}
	return (0);
}

/*
int		catch_over_btn_event(t_data *d)
{
	if (is_mouse_on_target(d, set_sdl_rect(WIN_SIZE_X / 2 - 100, WIN_SIZE_Y / 2, 200, 50)) == 1)
	{
		if (execv("./doom-nukem", d->menu.argv_tab) && access("./doom-nukem", W_OK))
			return (exit_menu(d));
	}
	if (is_mouse_on_target(d, set_sdl_rect(WIN_SIZE_X / 2 - 100, WIN_SIZE_Y / 2 + 100, 200, 50)) == 1)
	{
		if (execv("./menu", d->menu.argv_tab) && access("./menu", W_OK))
			return (exit_menu(d));
	}
}
*/
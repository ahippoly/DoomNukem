#include "proto_global.h"
#include <errno.h>

int		render_gameover_button(t_data *d, char **av)
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

int		catch_over_btn_event(t_data *d, char **av)
{
	if (is_mouse_on_target(d, set_sdl_rect(WIN_SIZE_X / 2 - 100, WIN_SIZE_Y / 2, 200, 50)) == 1) //continue
	{
		if  (access("./doom-nukem", X_OK))
		{
			printf("Oh dear, something went wrong with read()! %s\n", strerror(errno));
			exit_env(d);
		}
		else
			d->run_game = 1;
	}
	else if (is_mouse_on_target(d, set_sdl_rect(WIN_SIZE_X / 2 - 100, WIN_SIZE_Y / 2 + 100, 200, 50)) == 1) //quit
	{
		if (access("./menu", X_OK))
		{
			printf("Oh dear, something went wrong with read()! %s\n", strerror(errno));
			exit_env(d);
		}
		else 
			d->run_game = 2;
	}
	return (0);
}

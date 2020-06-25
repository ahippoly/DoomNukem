#include "menu.h"

int		is_mouse_on_target(t_data *d, SDL_Rect pos)
{
	if (d->e.motion.x > pos.x && d->e.motion.x < pos.x + pos.w
		&& d->e.motion.y > pos.y && d->e.motion.y < pos.y + pos.h)
	{
		if (d->e.type == SDL_MOUSEBUTTONDOWN)
			if (d->e.button.button == SDL_BUTTON_LEFT)
				return (1);
	}
	return (0);
}

int		catch_btn_event(t_data *d, int ac, char **av)
{
	if (is_mouse_on_target(d, set_sdl_rect(WIN_SIZE_X / 2, WIN_SIZE_Y / 3, 200, 50)) == 1)
	{
		if (execv("./doom-nukem", NULL) && access("./doom-nukem", W_OK))
			return (exit_menu(d));
	}
	else if (is_mouse_on_target(d, set_sdl_rect(WIN_SIZE_X / 2, WIN_SIZE_Y / 3 + 100, 200, 50)) == 1)
	{
		if (execv("./editor", NULL) && access("./editor", W_OK))
			return (exit_menu(d));
	}
	else if (is_mouse_on_target(d, set_sdl_rect(WIN_SIZE_X / 2, WIN_SIZE_Y / 3 + 200, 200, 50)) == 1)
		return (exit_menu(d));
	return (0);
}
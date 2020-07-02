#include "proto_global.h"
#include <errno.h>

int			is_mouse_on_target(t_data *d, SDL_Rect pos)
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

int			catch_btn_event(t_data *d, int ac, char **av)
{
	if (is_mouse_on_target(d, set_sdl_rect(WIN_SIZE_X / 2, WIN_SIZE_Y / 3, 200, 50)) == 1) //play
	{
		printf("i got bamboozled\n");
		if (access("doom-nukem", X_OK))
		{
			printf("Oh dear, something went wrong with read()! %s\n", strerror(errno));
			exit_env(d);
		}
		else
			d->run_game = GAME;
	}
	else if (is_mouse_on_target(d, set_sdl_rect(WIN_SIZE_X / 2, WIN_SIZE_Y / 3 + 100, 200, 50)) == 1) //editor
	{
		if (access("./editor", X_OK))
		{
			printf("Oh dear, something went wrong with read()! %s\n", strerror(errno));
			exit_env(d);
		}
		else
			d->run_game = EDITOR;
	}
	else if (is_mouse_on_target(d, set_sdl_rect(WIN_SIZE_X / 2, WIN_SIZE_Y / 3 + 200, 200, 50)) == 1) //exit
		exit_env(d);
	return (0);
}
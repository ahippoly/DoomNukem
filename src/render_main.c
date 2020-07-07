#include "proto_global.h"
#include <errno.h>

int					main(int ac, char **av)
{
    t_data			d;
    
    init_data(&d, ac, av);
	d.run_game = MENU;
    init_sound(&d);
    play_sound(&d, MUS2);
	SDL_SetRelativeMouseMode(SDL_FALSE);
	while (d.run_game > 0)
	{
		if (d.run_game == GAME)
			render_game(&d);
		else if (d.run_game == MENU)
			render_menu(&d);
		else if (d.run_game == GAMEOVER)
			render_gameover(&d);
		else if (d.run_game == EDITOR)
		{
			if (access("./editor", X_OK))
			{
				printf("Oh dear, something went wrong with read()! %s\n", strerror(errno));
				d.run_game = 0;
			}
			else
				execv("./editor", av);
		}
	}
	exit_game(&d, "");
}

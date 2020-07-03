#include "proto_global.h"
#include <errno.h>

int					main(int ac, char **av)
{
    t_data			d;
    
    init_data(&d, ac, av);
	d.run_game = MENU;
	while (d.run_game > 0)
	{
		if (d.run_game == GAME)
			render_game(&d, ac, av);
		else if (d.run_game == MENU)
			render_menu(&d, ac, av);
		else if (d.run_game == GAMEOVER)
			render_gameover(&d, ac, av);
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
	exit_env(&d);
}


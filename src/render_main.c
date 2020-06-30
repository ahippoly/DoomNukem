#include "proto_global.h"
#include <errno.h>

int					main(int ac, char **av)
{
    t_data			d;
    
    init_data(&d, ac, av);
    ft_putstr("Main worked\n");
	printf("map: %s\n", av[1]);
	printf("d.run_game: %d\n", d.run_game);
	d.run_game = 2;
    // init_sound(&d);
    // play_sound(&d, MUS1); //Play Music
	while (d.run_game > 0)
	{
		if (d.run_game == 1) // game
		{
			render_game(&d, ac, av);
		}
		else if (d.run_game == 2) // menu
			render_menu(&d, ac, av);
		else if (d.run_game == 3) // gameover
			render_gameover(&d, av);
		else if (d.run_game == 4) // editor
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


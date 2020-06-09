#include "../includes/wolf3d.h"

void	init_user(t_stat health, t_stat armor, t_user *user)
{
	user->fog = 3;
	user->paused = -1;
	user->bobbing.x = 0;
	user->bobbing.y = 0;
	user->health_bar = sdl_set_rect(10, WIN_W - 100, health->current + armor->current, 30)
}

#include "proto_global.h"

int	handle_keyboard_event(t_env *env)
{
    if (env->clavier[SDL_SCANCODE_ESCAPE] || env->clavier[SDL_SCANCODE_RETURN])
        env->quit = 1;
    if (env->clavier[SDL_SCANCODE_D])
        move_map_move_right(env);
    if (env->clavier[SDL_SCANCODE_A])
        move_map_move_left(env);
    if (env->clavier[SDL_SCANCODE_W])
        move_map_move_up(env);
    if (env->clavier[SDL_SCANCODE_S])
		move_map_move_down(env);
	return (0);
}
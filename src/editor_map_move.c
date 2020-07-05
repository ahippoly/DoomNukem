#include "proto_global.h"

//OKK

void move_map_move_left(t_env *env)
{
    if (env->map_move.x <= -MOVE_SPEED)
        env->map_move.x += MOVE_SPEED;
}

void move_map_move_right(t_env *env) 
{
    env->map_move.x -= MOVE_SPEED;
}

void move_map_move_up(t_env *env)
{
    if (env->map_move.y <= -MOVE_SPEED)
        env->map_move.y += MOVE_SPEED;
}

void move_map_move_down(t_env *env)
{
    env->map_move.y -= MOVE_SPEED;
}
#include "editor.h"
#include "global_header.h"

void check_hovered_buttons(t_env *env)
{
    env->selected_button = -1;
    if (env->mouse.x > env->edit.pos_size.x && env->mouse.x < env->edit.pos_size.x + env->edit.pos_size.w
        && env->mouse.y > env->edit.pos_size.y && env->mouse.y < env->edit.pos_size.y + env->edit.pos_size.h)
    {
        env->selected_button = BUTTON_EDIT;
        env->edit_selected = env->edit_white.pixels;
    }
    else
        env->edit_selected = env->edit.pixels;
    if (env->mouse.x > env->del.pos_size.x && env->mouse.x < env->del.pos_size.x + env->del.pos_size.w
        && env->mouse.y > env->del.pos_size.y && env->mouse.y < env->del.pos_size.y + env->del.pos_size.h)
    {
        env->selected_button = BUTTON_DEL;
        env->del_selected = env->del_white.pixels;
    }
    else
        env->del_selected = env->del.pixels;
}

void del_selected_wall(t_env *env)
{
    del_wall(env, env->selected_wall_id);
}
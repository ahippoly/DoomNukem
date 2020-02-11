#include "editor.h"
#include "global_header.h"

void check_hovered_input(t_env *env)
{
    int i;

    i = 0 ;
    while (i < NB_INPUT)
    {
        env->selected_input = -1;
        if(is_cursor_in_hitbox(env, env->input_lst[i].pos_size))
            env->selected_button = i;
    }
}
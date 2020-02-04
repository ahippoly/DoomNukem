#include "editor.h"
#include "global_header.h"

int is_cursor_in_button(t_env *env, t_txt_img txt)
{
    if (env->mouse.x > txt.pos_size.x && env->mouse.x < txt.pos_size.x + txt.pos_size.w
        && env->mouse.y > txt.pos_size.y && env->mouse.y < txt.pos_size.y + txt.pos_size.h)
        return (1);
    return(0);
}

void handle_hovered_button(t_env *env, t_button *button)
{
    if (is_cursor_in_button(env, button->normal))
    {
        env->selected_button = button->button_id;
        button->printed = &button->hovered;
    }
    else
        button->printed = &button->normal;
}

t_button create_button(t_txt_img normal, t_txt_img hovered, int button_id)
{
    t_button button;

    button.normal = normal;
    button.hovered = hovered;
    button.button_id = button_id;
    return(button);
}


void check_hovered_buttons(t_env *env)
{
    env->selected_button = -1;
    handle_hovered_button(env, &env->edit);
    handle_hovered_button(env, &env->del);
    handle_hovered_button(env, &env->text_select_left);
    handle_hovered_button(env, &env->text_select_right);
    handle_hovered_button(env, &env->create_room);
}

void select_previous_texture(t_env *env)
{
    if (env->selected_texture == 0)
        env->selected_texture = NB_TEXTURE - 1;
    else
        env->selected_texture--;    
}

void select_next_texture(t_env *env)
{
    if (env->selected_texture == NB_TEXTURE -1)
        env->selected_texture = 0;
    else
        env->selected_texture++;
}

void del_selected_wall(t_env *env)
{
    del_wall(env, env->selected_wall_id);
}
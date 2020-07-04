#include "proto_global.h"

int is_cursor_in_hitbox(t_env *env, SDL_Rect pos_size)
{
    if (env->mouse.x > pos_size.x && env->mouse.x < pos_size.x + pos_size.w
        && env->mouse.y > pos_size.y && env->mouse.y < pos_size.y + pos_size.h)
        return (1);
    return (0);
}

void handle_hovered_button(t_env *env, t_button *button)
{
    if (is_cursor_in_hitbox(env, button->normal.pos_size))
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
    int i;

    i = 0;
    env->selected_button = -1;
    while (i < NB_BUTTONS)
        handle_hovered_button(env, &env->buttons_lst[i++]);
}

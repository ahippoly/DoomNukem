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
    int i;

    i = 0;
    env->selected_button = -1;
    while (i < NB_BUTTONS)
        handle_hovered_button(env, &env->buttons_lst[i++]);
}

void change_selected_wall_texture(t_env *env, int texture_id)
{
    if (env->selected_wall_id != -1)
        env->wall_list[env->selected_wall_id].texture_id = texture_id;
}

void select_previous_texture(t_env *env)
{
    if (env->selected_texture == 0)
        env->selected_texture = NB_TEXTURE - 1;
    else
        env->selected_texture--;
    change_selected_wall_texture(env, env->selected_texture);
}

void change_selected_wall_transparency(t_env *env)
{
    if (env->selected_wall_id != -1)
        env->wall_list[env->selected_wall_id].transparency = env->actual_transparency;
}

void incr_transparency(t_env *env)
{
    if (env->actual_transparency < 100)
        env->actual_transparency++;
}

void decr_transparency(t_env *env)
{
    if (env->actual_transparency > 0)
        env->actual_transparency--;
}

void select_next_texture(t_env *env)
{
    if (env->selected_texture == NB_TEXTURE -1)
        env->selected_texture = 0;
    else
        env->selected_texture++;
    change_selected_wall_texture(env, env->selected_texture);
    
}

void del_selected_wall(t_env *env)
{
    del_wall(env, env->selected_wall_id);
}
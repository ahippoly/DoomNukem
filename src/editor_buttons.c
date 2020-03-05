#include "editor.h"
#include "global_header.h"

int is_cursor_in_hitbox(t_env *env, SDL_Rect pos_size)
{
    if (env->mouse.x > pos_size.x && env->mouse.x < pos_size.x + pos_size.w
        && env->mouse.y > pos_size.y && env->mouse.y < pos_size.y + pos_size.h)
        return (1);
    return(0);
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

void change_selected_wall_texture(t_env *env, int texture_id)
{
    if (env->selected_wall_id != -1)
        env->wall_list[env->selected_wall_id].texture_id = texture_id;
}

void select_previous_mob(t_env *env)
{
    if (env->selected_mob == ICON_MOB_RANGE_BEGIN)
        env->selected_mob = ICON_MOB_RANGE_END - 1;
    else
        env->selected_mob--;
}

void select_next_mob(t_env *env)
{
    if (env->selected_mob == ICON_MOB_RANGE_END - 1)
        env->selected_mob = ICON_MOB_RANGE_BEGIN;
    else
        env->selected_mob++;
}


void select_previous_texture(t_env *env)
{
    if (env->selected_texture == 0)
        env->selected_texture = NB_TEXTURE - 1;
    else
        env->selected_texture--;
    change_selected_wall_texture(env, env->selected_texture);
}

void select_next_texture(t_env *env)
{
    if (env->selected_texture == NB_TEXTURE - 1)
        env->selected_texture = 0;
    else
        env->selected_texture++;
    change_selected_wall_texture(env, env->selected_texture);
}

void set_player_spawn_mode(t_env *env)
{
    env->mouse_icon = create_icon(create_t_point(0, 0), create_t_size(30, 30), 0);
    env->player_spawn = create_t_point(0, 0);
    env->being_placed = &env->player_spawn;
    env->selected_mouse_mode = MOUSE_MODE_PLACING;
}

void mob_placing_mode(t_env *env)
{
    t_icon new;

    env->mouse_icon = create_icon(create_t_point(0, 0), create_t_size(30, 30), env->selected_mob);
    new = create_icon(create_t_point(-1, -1), create_t_size(30, 30), env->selected_mob);
    add_icon(env, new);
    env->being_placed = &env->icon_list[env->icon_count - 1].pos;
    env->selected_mouse_mode = MOUSE_MODE_PLACING;
}

void del_selected_wall(t_env *env)
{
    del_wall(env, env->selected_wall_id);
    env->selected_wall_id = -1;
}

void create_room_button(t_env *env)
{
    env->selected_mouse_mode = MOUSE_MODE_CREATE_ROOM;
}
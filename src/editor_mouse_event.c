#include "editor.h"
#include "global_header.h"

void create_room_mode(t_env *env)
{

    if (env->hovered_corner.x != -1)
    {
        printf("1start room point : x=%i, y=%i, hovered_corner : x=%i, y=%i\n", env->start_room_point.x, env->start_room_point.y, env->hovered_corner.x, env->hovered_corner.y);
        printf("selected corner : x=%i, y=%i\n", env->selected_corner.x, env->selected_corner.y);
        if (env->selected_corner.x == -1)
            env->selected_corner = env->hovered_corner;
        else
            if (!add_wall(env->selected_corner, env->hovered_corner, env))
                return;
        printf("2selected corner : x=%i, y=%i\n", env->selected_corner.x, env->selected_corner.y);
        
        if (env->start_room_point.x < 0)
        {
            env->start_room_point = env->selected_corner;
            env->first_wall_room_id = env->wall_count;
        }
        else if (env->hovered_corner.x == env->start_room_point.x
        && env->hovered_corner.y == env->start_room_point.y)
        {
            env->selected_mouse_mode = 0;
            env->hovered_corner.x = -1;
            env->start_room_point = create_point(-1, -1);
            env->room_count++;
        }
        printf("start room point : x=%i, y=%i, hovered_corner : x=%i, y=%i\n", env->start_room_point.x, env->start_room_point.y, env->hovered_corner.x, env->hovered_corner.y);
        env->selected_corner = env->hovered_corner;
    }
}

void neutral_mouse_mode(t_env *env)
{
    
    if (env->hovered_corner.x != -1)
    {
        if (env->selected_corner.x == -1)
            env->selected_corner = env->hovered_corner;
        else if (env->selected_corner.x != env->hovered_corner.x
            || env->selected_corner.y != env->hovered_corner.y)
        {
            add_wall(env->selected_corner, env->hovered_corner, env);
            env->selected_corner.x = -1;
        }
    }
    else
        env->selected_corner.x = -1;
    if (env->hovered_wall_id != -1)
    {
        env->selected_wall_id = env->hovered_wall_id;
        update_wall_param(env);
        get_wall_param(env);
    }
    else if (env->selected_button != -1)
        env->buttons_fct[env->selected_button](env);
    else if (env->hovered_input_id != -1)
    {
        env->selected_input = env->hovered_input_id;
        env->input_lst[env->selected_input].value = 0;
    }
    else
    {
        //update_wall_param(env);
        env->selected_wall_id = -1;
        env->selected_input = -1;
    }
    printf("selected wall = %i\n", env->selected_wall_id);
}

void on_screen_place_mode(t_env *env)
{
    if (env->being_placed != NULL)
        *env->being_placed = create_t_point(((double)env->mouse.x - GRID_POS_X - env->map_move.x) / TILE_SIZE, ((double)env->mouse.y - GRID_POS_Y - env->map_move.y) / TILE_SIZE);
    env->mouse_icon.id_ref = -1;
    env->selected_mouse_mode = MOUSE_MODE_NEUTRAL;
    env->being_placed = NULL;
}

void check_click(t_env *env)
{
    //printf("actuall mouse mode = %i\n", env->selected_mouse_mode);
    if (env->ev.type == SDL_MOUSEBUTTONUP && env->ev.button.button == SDL_BUTTON_LEFT)
        env->mouse_click_fct[env->selected_mouse_mode](env);
}

void handle_mouse_event(t_env *env)
{
    while (SDL_PollEvent(&env->ev))
    {
        if (env->ev.type == SDL_KEYUP)
        {
            handle_input_mode(env, env->ev.key.keysym.scancode);
            debug_print(env, env->ev.key.keysym.scancode);
        }
        check_click(env);
    }
}
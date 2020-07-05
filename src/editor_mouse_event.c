#include "proto_global.h"

//OK

void			process_hovered_corner(t_env *env) //enfant de create_room_mode
{
	int			room_ground;
	int			room_ceil;

    room_ground = env->input_lst[INPUT_ROOM_GROUND].value;
	room_ceil = env->input_lst[INPUT_ROOM_CEIL].value;
	env->selected_mouse_mode = 0;
	env->hovered_corner.x = -1;
	env->start_room_point = create_point(-1, -1);
	env->room_height[env->room_count].start = room_ground;
	env->room_height[env->room_count].end = room_ceil;
	env->room_text[env->room_count] = 0;
	env->room_count++;
}

void			create_room_mode(t_env *env)
{
	t_point		hov_corner;
	t_point		selec_corner;

	hov_corner = convert_sdlpoint2tpoint(env->hovered_corner);
	selec_corner = convert_sdlpoint2tpoint(env->selected_corner);
	if (env->hovered_corner.x != -1)
    {
		process_hovered_corner(env);
        if (env->selected_corner.x == -1)
            env->selected_corner = env->hovered_corner;
        else
            if (!add_wall(selec_corner, hov_corner, env))
                return ;
        if (env->start_room_point.x < 0)
        {
            env->start_room_point = env->selected_corner;
            env->first_wall_room_id = env->wall_count;
        }
        else if (env->hovered_corner.x == env->start_room_point.x
        && env->hovered_corner.y == env->start_room_point.y)
			process_hovered_corner(env);
        env->selected_corner = env->hovered_corner;
    }
}

void			mouse_hovered_corner(t_env *env) //enfant de neutral_mouse_mode
{
	t_point		hov_corner;
	t_point		selec_corner;

	hov_corner = convert_sdlpoint2tpoint(env->hovered_corner);
	selec_corner = convert_sdlpoint2tpoint(env->selected_corner);

	if (env->selected_corner.x == -1)
		env->selected_corner = env->hovered_corner;
	else if (env->selected_corner.x != env->hovered_corner.x
		|| env->selected_corner.y != env->hovered_corner.y)
	{
		add_wall(selec_corner, hov_corner, env);
		env->selected_corner.x = -1;
	}
}

void			neutral_mouse_mode(t_env *env)
{
    if (env->hovered_corner.x != -1)
		mouse_hovered_corner(env);
    else
        env->selected_corner.x = -1;
    if (env->selected_button != -1)
        env->buttons_fct[env->selected_button](env);
    else if (env->hovered_input_id != -1)
    {
        env->selected_input = env->hovered_input_id;
        env->input_lst[env->selected_input].value = 0;
    }
	else if (env->hovered_wall_id != -1)
    {
        env->selected_wall_id = env->hovered_wall_id;
        update_wall_param(env);
        get_wall_param(env);
    }
    else
    {
        //update_wall_param(env);
        env->selected_wall_id = -1;
        env->selected_input = -1;
    }
}

void on_screen_place_mode(t_env *env)
{
    if (env->being_placed != NULL)
        *env->being_placed = create_t_point(((float)env->mouse.x - GRID_POS_X - env->map_move.x) / TILE_SIZE, ((float)env->mouse.y - GRID_POS_Y - env->map_move.y) / TILE_SIZE);
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
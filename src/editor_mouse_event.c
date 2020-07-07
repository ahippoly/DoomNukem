#include "proto_global.h"

//OKK
static void		mouse_hovered_corner(t_env *env) //enfant de neutral_mouse_mode
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
        }
        check_click(env);
    }
}
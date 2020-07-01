#include "proto_global.h"
#include "proto_global.h"

void check_hovered_input(t_env *env)
{
    int i;

    i = 0 ;
    env->hovered_input_id = -1;
    while (i < NB_INPUT)
    {
        if (is_cursor_in_hitbox(env, env->input_lst[i].pos_size))
            env->hovered_input_id = i;
        i++;
    }
}

void print_inputs(t_env *env)
{
    int i;
    t_input input;

    i = 0;
    while (i < NB_INPUT)
    {
        input = env->input_lst[i];
        //printf("input pos_sie : x = %i, y = %i\n", input.pos_size.x, input.pos_size.y);
        if (env->selected_input == i)
            input_text_to_img(ft_itoa(input.value), 2, 0xFF88FF88, create_img(env->p_screen, set_sdl_rect(input.pos_size.x, input.pos_size.y, WIN_SIZE_X, WIN_SIZE_Y)));
        else if (env->hovered_input_id == i)
            input_text_to_img(ft_itoa(input.value), 2, 0xFF8888FF, create_img(env->p_screen, set_sdl_rect(input.pos_size.x, input.pos_size.y, WIN_SIZE_X, WIN_SIZE_Y)));
        else
            input_text_to_img(ft_itoa(input.value), 2, 0xFFDDDDDD, create_img(env->p_screen, set_sdl_rect(input.pos_size.x, input.pos_size.y, WIN_SIZE_X, WIN_SIZE_Y)));
        i++;
    }
}

t_input create_t_input(SDL_Rect pos_size, int default_value, int max)
{
    t_input input;

    input.pos_size = pos_size;
    input.value = default_value;
    input.max = max;
    input.is_in_input_mode = 0;
    return (input);
}

void handle_input_mode(t_env *env, SDL_Scancode key_released)
{
    t_input *input;
    int     added_num;

    if (env->selected_input != -1 && env->selected_mouse_mode != MOUSE_MODE_CREATE_ROOM)
    {
        added_num = -1;
        if (key_released == SDL_SCANCODE_0)
            added_num = 0;
        if (key_released == SDL_SCANCODE_1)
            added_num = 1;
        if (key_released == SDL_SCANCODE_2)
            added_num = 2;
        if (key_released == SDL_SCANCODE_3)
            added_num = 3;
        if (key_released == SDL_SCANCODE_4)
            added_num = 4;
        if (key_released == SDL_SCANCODE_5)
            added_num = 5;
        if (key_released == SDL_SCANCODE_6)
            added_num = 6;
        if (key_released == SDL_SCANCODE_7)
            added_num = 7;
        if (key_released == SDL_SCANCODE_8)
            added_num = 8;
        if (key_released == SDL_SCANCODE_9)
            added_num = 9;
        printf("added num = %i\n", added_num);
        if (added_num != -1)
        {
            input = &env->input_lst[env->selected_input];
            // printf("selected input = %i, input val = %i\n", env->selected_input, input->value);
            input->value = ft_min(input->value * 10 + added_num, input->max);
            // printf("input val = %i\n", input->value);
            update_wall_param(env);
        }
    }
}

void update_wall_param(t_env *env)
{
	int tmp;

    if (env->selected_input != -1 && env->selected_wall_id != -1)
    {
        if (env->selected_input == INPUT_TRANSPARENCY)
            env->wall_list[env->selected_wall_id].transparency = env->input_lst[INPUT_TRANSPARENCY].value;
        if (env->selected_input == INPUT_BEGIN_P1)
            env->wall_list[env->selected_wall_id].p1_height.start = env->input_lst[INPUT_BEGIN_P1].value;
        if (env->selected_input == INPUT_BEGIN_P2)
            env->wall_list[env->selected_wall_id].p2_height.start = env->input_lst[INPUT_BEGIN_P2].value;
        if (env->selected_input == INPUT_END_P1)
            env->wall_list[env->selected_wall_id].p1_height.end = env->input_lst[INPUT_END_P1].value;
        if (env->selected_input == INPUT_END_P2)
            env->wall_list[env->selected_wall_id].p2_height.end = env->input_lst[INPUT_END_P2].value;
		if (env->selected_input == INPUT_ROOM_GROUND)
            if ((tmp = env->wall_list[env->selected_wall_id].room_id_ref) > -1)
				env->room_height[tmp].start = env->input_lst[INPUT_ROOM_GROUND].value;
		if (env->selected_input == INPUT_ROOM_CEIL)
			if ((tmp = env->wall_list[env->selected_wall_id].room_id_ref) > -1)
				env->room_height[tmp].end = env->input_lst[INPUT_ROOM_CEIL].value;
    }
}

void get_wall_param(t_env *env)
{
	int tmp;

    env->selected_texture = env->wall_list[env->selected_wall_id].texture_id;
    env->input_lst[INPUT_TRANSPARENCY].value = env->wall_list[env->selected_wall_id].transparency;
    env->input_lst[INPUT_BEGIN_P1].value = env->wall_list[env->selected_wall_id].p1_height.start;
    env->input_lst[INPUT_BEGIN_P2].value = env->wall_list[env->selected_wall_id].p2_height.start;
    env->input_lst[INPUT_END_P1].value = env->wall_list[env->selected_wall_id].p1_height.end;
    env->input_lst[INPUT_END_P2].value = env->wall_list[env->selected_wall_id].p2_height.end;
    env->input_lst[INPUT_COLLIDE].value = env->wall_list[env->selected_wall_id].can_collide;

	if ((tmp = env->wall_list[env->selected_wall_id].room_id_ref) > -1)
	{
			env->input_lst[INPUT_ROOM_GROUND].value = env->room_height[tmp].start;
			env->input_lst[INPUT_ROOM_CEIL].value = env->room_height[tmp].end;
	}
}

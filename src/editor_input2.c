#include "proto_global.h"

//OKK

static int	handle_realeased_scancode(SDL_Scancode key_released)
{
	int added_num;
	
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
	return (added_num);
}

void		handle_input_mode(t_env *env, SDL_Scancode key_released)
{
    t_input *input;
    int     added_num;

    if (env->selected_input != -1 && env->selected_mouse_mode != MOUSE_MODE_CREATE_ROOM)
    {
		added_num = handle_realeased_scancode(key_released);
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
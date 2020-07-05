#include "proto_global.h"

static int		malloc_editor_button(t_env *env)
{
	if (!(env->buttons_lst = malloc_button(NB_BUTTONS)))
		exit_editor(env, "error: failes to malloc editor buttons");
	return (0);
}

static void		init_create_button(t_env *env)
{
	env->buttons_lst[BUTTON_DEL] = create_button(create_text_img("del", 2, 0xFF8888FF, create_point(0.85 * WIN_SIZE_X, 0.020 * WIN_SIZE_Y)), create_text_img("del", 2, 0xFFFFFFFF, create_point(0.85 * WIN_SIZE_X, 0.02 * WIN_SIZE_Y)), BUTTON_DEL);
    env->buttons_lst[BUTTON_TEXT_LEFT] = create_button(create_text_img("<", 2, 0xFFDDDDDD, create_point(0.762 * WIN_SIZE_X, 0.195 * WIN_SIZE_Y)), create_text_img("<", 2, 0xFF88FF88, create_point(0.762 * WIN_SIZE_X, 0.195 * WIN_SIZE_Y)), BUTTON_TEXT_LEFT);
    env->buttons_lst[BUTTON_TEXT_RIGHT] = create_button(create_text_img(">", 2, 0xFFDDDDDD, create_point(0.958 * WIN_SIZE_X, 0.195 * WIN_SIZE_Y)), create_text_img(">", 2, 0xFF88FF88, create_point(0.958 * WIN_SIZE_X, 0.195 * WIN_SIZE_Y)), BUTTON_TEXT_RIGHT);
    env->buttons_lst[BUTTON_CREATE_ROOM] = create_button(create_text_img("Create_room", 1, 0xFFFF88CC, create_point(0.730 * WIN_SIZE_X, 0.850 * WIN_SIZE_Y)), create_text_img("Create_room", 1, 0xFFFFFFFF, create_point(0.730 * WIN_SIZE_X, 0.850 * WIN_SIZE_Y)), BUTTON_CREATE_ROOM);
    env->buttons_lst[BUTTON_MAP_OUTPUT] = create_button(create_text_img("Map_output", 1, 0xFFFF88CC, create_point(0.730 * WIN_SIZE_X, 0.800 * WIN_SIZE_Y)), create_text_img("Map_output", 1, 0xFFFFFFFF, create_point(0.730 * WIN_SIZE_X, 0.800 * WIN_SIZE_Y)), BUTTON_MAP_OUTPUT);
    env->buttons_lst[BUTTON_SET_PLAYER_SPAWN] = create_button(create_text_img("set_player_spawn", 1, 0xFFFF88CC, create_point(0.730 * WIN_SIZE_X, 0.900 * WIN_SIZE_Y)), create_text_img("set_player_spawn", 1, 0xFFFFFFFF, create_point(0.730 * WIN_SIZE_X, 0.900 * WIN_SIZE_Y)), BUTTON_SET_PLAYER_SPAWN);
    env->buttons_lst[BUTTON_MOB_LEFT] = create_button(create_text_img("<", 2, 0xFFDDDDDD, create_point(0.762 * WIN_SIZE_X, 0.445 * WIN_SIZE_Y)), create_text_img("<", 2, 0xFF88FF88, create_point(0.762 * WIN_SIZE_X, 0.445 * WIN_SIZE_Y)), BUTTON_MOB_LEFT);
    env->buttons_lst[BUTTON_MOB_RIGHT] = create_button(create_text_img(">", 2, 0xFFDDDDDD, create_point(0.958 * WIN_SIZE_X, 0.445 * WIN_SIZE_Y)), create_text_img(">", 2, 0xFF88FF88, create_point(0.958 * WIN_SIZE_X, 0.445 * WIN_SIZE_Y)), BUTTON_MOB_RIGHT);
    env->buttons_lst[BUTTON_MOB_PLACING] = create_button(create_text_img("Place", 1, 0xFFDDDDDD, create_point(0.822 * WIN_SIZE_X, 0.555 * WIN_SIZE_Y)), create_text_img("Place", 1, 0xFF88FF88, create_point(0.822 * WIN_SIZE_X, 0.555 * WIN_SIZE_Y)), BUTTON_MOB_PLACING);
    env->buttons_lst[BUTTON_FLOOR_TEXT] = create_button(create_text_img("Set_floor_text", 1, 0xFFFF88CC, create_point(0.730 * WIN_SIZE_X, 0.950 * WIN_SIZE_Y)), create_text_img("Set_floor_text", 1, 0xFFDDDDDD, create_point(0.730 * WIN_SIZE_X, 0.950 * WIN_SIZE_Y)), BUTTON_FLOOR_TEXT);
}

static void		init_select_button(t_env *env)
{
    env->buttons_fct[BUTTON_DEL] = del_selected_wall;
    env->buttons_fct[BUTTON_TEXT_LEFT] = select_previous_texture;
    env->buttons_fct[BUTTON_TEXT_RIGHT] = select_next_texture;
    env->buttons_fct[BUTTON_CREATE_ROOM] = create_room_button;
    env->buttons_fct[BUTTON_MAP_OUTPUT] = map_output;
    env->buttons_fct[BUTTON_SET_PLAYER_SPAWN] = set_player_spawn_mode;
    env->buttons_fct[BUTTON_MOB_LEFT] = select_previous_mob;
    env->buttons_fct[BUTTON_MOB_RIGHT] = select_next_mob;
    env->buttons_fct[BUTTON_MOB_PLACING] = mob_placing_mode;
    env->buttons_fct[BUTTON_FLOOR_TEXT] = set_room_text;
}

/* appel les fonctions plus hautes pour initialiser les bouttons*/
void			init_buttons(t_env *env)
{
	malloc_editor_button(env);
	init_create_button(env);
	init_select_button(env);
}
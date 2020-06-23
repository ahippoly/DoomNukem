#include "global_header.h"
#include "editor.h"

void init_input(t_env *env)
{
    env->input_lst[INPUT_TRANSPARENCY] = create_t_input(set_sdl_rect(0.835 * WIN_SIZE_X, 0.650 * WIN_SIZE_Y, 0.060 * WIN_SIZE_X, 0.040 * WIN_SIZE_Y), 0, 100);
    env->input_lst[INPUT_BEGIN_P1] = create_t_input(set_sdl_rect(0.200 * WIN_SIZE_X, 0.720 * WIN_SIZE_Y, 0.060 * WIN_SIZE_X, 0.040 * WIN_SIZE_Y), 20, 190);
    env->input_lst[INPUT_BEGIN_P2] = create_t_input(set_sdl_rect(0.305 * WIN_SIZE_X, 0.720 * WIN_SIZE_Y, 0.060 * WIN_SIZE_X, 0.040 * WIN_SIZE_Y), 20, 190);
    env->input_lst[INPUT_END_P1] = create_t_input(set_sdl_rect(0.200 * WIN_SIZE_X, 0.780 * WIN_SIZE_Y, 0.060 * WIN_SIZE_X, 0.040 * WIN_SIZE_Y), 30, 200);
    env->input_lst[INPUT_END_P2] = create_t_input(set_sdl_rect(0.305 * WIN_SIZE_X, 0.780 * WIN_SIZE_Y, 0.060 * WIN_SIZE_X, 0.040 * WIN_SIZE_Y), 30, 200);
    env->input_lst[INPUT_ROOM_GROUND] = create_t_input(set_sdl_rect(0.200 * WIN_SIZE_X, 0.890 * WIN_SIZE_Y, 0.060 * WIN_SIZE_X, 0.040 * WIN_SIZE_Y), 20, 190);
    env->input_lst[INPUT_ROOM_CEIL] = create_t_input(set_sdl_rect(0.305 * WIN_SIZE_X, 0.890 * WIN_SIZE_Y, 0.060 * WIN_SIZE_X, 0.040 * WIN_SIZE_Y), 30, 200);
}

void init_img(t_env *env)
{
    env->icon_count = 0;
    env->selected_mob = 0 + ICON_MOB_RANGE_BEGIN;
    env->icon_list = (t_icon*)p_malloc(sizeof(t_icon) * ICON_ARRAY_SIZE);
    env->being_placed = NULL;
    env->icon_list_size = ICON_ARRAY_SIZE;
    env->img_list[0] = bmp_to_texture(IMG_PATH_0, env->rend);
    env->img_list[1] = bmp_to_texture(IMG_PATH_1, env->rend);
    env->img_list[2] = bmp_to_texture(IMG_PATH_2, env->rend);
    env->img_list[3] = bmp_to_texture(IMG_PATH_3, env->rend);
}

void init_env2(t_env *env)
{
    env->p1_height = create_t_range(0, 10);
    env->p2_height = create_t_range(0, 10);
    env->map_move = create_point(0, 0);
    env->hovered_wall_id = -1;
    env->selected_wall_id = -1;
    env->selected_input = -1;
    env->room_list = NULL;
    if (!(env->wall_list = (t_wall*)malloc(sizeof(t_wall) * NB_WALL_MAX)))
        exit_with_msg("Failed to malloc");
    env->quit = 0;
}

void init_env(t_env *env)
{
    init_sdl_ressources(env);
    init_texture(env);
    init_buttons(env);
    init_txt_img(env);
    init_mouse_mode(env);
    init_img(env);
    env->map_size = create_t_size(MAP_SIZE_X, MAP_SIZE_Y);
    init_input(env);
    env->map_wall_ref = init_wall_ref(env->map_size);
    env->p_screen = alloc_image(WIN_SIZE_X, WIN_SIZE_Y);
    env->p_grid = alloc_image(GRID_SIZE_X, GRID_SIZE_Y);
    env->grid_pos = set_sdl_rect(GRID_POS_X, GRID_POS_Y, GRID_SIZE_X, GRID_SIZE_Y);
    env->wall_count = 0;
    env->room_count = 0;
    env->icon_count = 0;
    env->player_spawn = create_t_point(0, 0);
    env->total_wall_created = 0;
    env->selected_corner.x = -1;
    env->mouse_icon.id_ref = -1;
    init_env2(env);
}
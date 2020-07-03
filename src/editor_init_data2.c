#include "proto_global.h"
#include "proto_global.h"

void init_input(t_env *env)
{
    env->input_lst[INPUT_TRANSPARENCY] = create_t_input(set_sdl_rect(0.835 * WIN_SIZE_X, 0.650 * WIN_SIZE_Y, 0.060 * WIN_SIZE_X, 0.040 * WIN_SIZE_Y), 0, 100);
    env->input_lst[INPUT_BEGIN_P1] = create_t_input(set_sdl_rect(0.200 * WIN_SIZE_X, 0.720 * WIN_SIZE_Y, 0.060 * WIN_SIZE_X, 0.040 * WIN_SIZE_Y), 20, 190);
    env->input_lst[INPUT_BEGIN_P2] = create_t_input(set_sdl_rect(0.305 * WIN_SIZE_X, 0.720 * WIN_SIZE_Y, 0.060 * WIN_SIZE_X, 0.040 * WIN_SIZE_Y), 20, 190);
    env->input_lst[INPUT_END_P1] = create_t_input(set_sdl_rect(0.200 * WIN_SIZE_X, 0.780 * WIN_SIZE_Y, 0.060 * WIN_SIZE_X, 0.040 * WIN_SIZE_Y), 30, 200);
    env->input_lst[INPUT_END_P2] = create_t_input(set_sdl_rect(0.305 * WIN_SIZE_X, 0.780 * WIN_SIZE_Y, 0.060 * WIN_SIZE_X, 0.040 * WIN_SIZE_Y), 30, 200);
    env->input_lst[INPUT_ROOM_GROUND] = create_t_input(set_sdl_rect(0.200 * WIN_SIZE_X, 0.890 * WIN_SIZE_Y, 0.060 * WIN_SIZE_X, 0.040 * WIN_SIZE_Y), 20, 190);
    env->input_lst[INPUT_ROOM_CEIL] = create_t_input(set_sdl_rect(0.305 * WIN_SIZE_X, 0.890 * WIN_SIZE_Y, 0.060 * WIN_SIZE_X, 0.040 * WIN_SIZE_Y), 30, 200);
    env->input_lst[INPUT_COLLIDE] = create_t_input(set_sdl_rect(0.530 * WIN_SIZE_X, 0.900 * WIN_SIZE_Y, 0.060 * WIN_SIZE_X, 0.040 * WIN_SIZE_Y), 1, 1);
}

void init_img(t_env *env)
{
	env->img_list = malloc_texture_tab(NB_IMG); //MALLOC ALEX
    env->icon_count = 0;
    env->selected_mob = 0 + ICON_MOB_RANGE_BEGIN;
	if (!(env->icon_list = (t_icon*)p_malloc(sizeof(t_icon) * ICON_ARRAY_SIZE))) //MALLOC
		exit_editor(env);
    env->being_placed = NULL;
    env->icon_list_size = ICON_ARRAY_SIZE;
    env->img_list[IMG_PLAYER] = bmp_to_texture(IMG_PATH_0, env->rend);
    env->img_list[IMG_AFRIT] = SDL_CreateTexture(env->rend, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, env->sprites[SPRITE_ID_AFRIT].dst_w, env->sprites[SPRITE_ID_AFRIT].dst_h);
	SDL_SetTextureBlendMode(env->img_list[IMG_AFRIT], SDL_BLENDMODE_BLEND);
    env->img_list[IMG_ORC] = SDL_CreateTexture(env->rend, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, env->sprites[SPRITE_ID_PYRO].dst_w, env->sprites[SPRITE_ID_PYRO].dst_h);
	SDL_SetTextureBlendMode(env->img_list[IMG_ORC], SDL_BLENDMODE_BLEND);
    env->img_list[IMG_KEY] = bmp_to_texture(IMG_PATH_3, env->rend);
    env->img_list[IMG_HEAL_PACK] = bmp_to_texture(IMG_PATH_4, env->rend);
    env->img_list[IMG_SHIP] = bmp_to_texture(IMG_PATH_5, env->rend);
    env->img_list[IMG_JETPACK] = bmp_to_texture(IMG_PATH_6, env->rend);
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
	env->map_name = NULL;
    if (!(env->wall_list = (t_wall*)malloc(sizeof(t_wall) * NB_WALL_MAX)))
        exit_with_msg("Failed to malloc");
    env->quit = 0;
}

void	init_env(t_env *env)
{
	if (!(env->room_height = malloc_range(NB_WALL_MAX)))
		exit_editor(env); //MALLOC ALEX
	if (!(env->room_text = malloc_int_tab(NB_WALL_MAX)))
		exit_editor(env); //MALLOC ALEX
    init_sdl_ressources(env);
    init_texture(env);
    init_buttons(env);
    init_txt_img(env);
    init_mouse_mode(env);
	init_sprites_img_env(env);
	env->sprites[SPRITE_ID_AFRIT] = sprite_init_afrit2(env->sprite_img[SPRITE_ID_AFRIT]);
	env->sprites[SPRITE_ID_PYRO] = sprite_init_pyro2(env->sprite_img[SPRITE_ID_PYRO]);
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
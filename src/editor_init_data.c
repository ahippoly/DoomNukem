#include "proto_global.h"

void init_sdl_ressources(t_env *env)
{
    env->win = NULL;
    if(0 != SDL_Init(SDL_INIT_VIDEO))
        exit_with_msg("Failed to Init SDL");
    if (!(env->win = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              WIN_SIZE_X, WIN_SIZE_Y, SDL_WINDOW_SHOWN)))
        exit_with_msg("Failed to create Window");
    if (!(env->rend = SDL_CreateRenderer(env->win, -1, SDL_RENDERER_ACCELERATED)))
        exit_with_msg("Failed to create Renderer");
    env->screen = SDL_CreateTexture(env->rend, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, WIN_SIZE_X, WIN_SIZE_Y);
    env->editor_grid = SDL_CreateTexture(env->rend, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, GRID_SIZE_X, GRID_SIZE_Y);
    //env->stones = SDL_CreateTexture(env->rend, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, 512, 512);
}

int		malloc_texture_list(t_env *env)
{
	if (!(env->text_list = malloc_texture_tab(NB_TEXTURE)))
		return (-1);
	return (0);
}

void		fill_text_list(t_env *env)
{
    int		i;
    t_img	*tmp;
	char	*path;

    env->selected_texture = 0;
	i = 0;
	path = ft_strnew(36);
	while (i < NB_TEXTURE)
	{
		ft_strcpy(path, "asset/img/textures/TEXT_PATH_");
		ft_strcat(path, ft_itoa(i));
		ft_strcat(path, ".bmp");
		env->text_list[i] = bmp_to_texture(path, env->rend);
		ft_bzero(path, sizeof(char *));
		i++;
	}
	free(path);
}

void	init_texture(t_env *env)
{
	malloc_texture_list(env);
	fill_text_list(env);
}

void init_buttons(t_env *env)
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

void init_mouse_mode(t_env *env)
{
    env->selected_mouse_mode = 0;
    env->start_room_point = create_point(-1 , -1);
    env->mouse_click_fct[MOUSE_MODE_NEUTRAL] = neutral_mouse_mode;
    env->mouse_click_fct[MOUSE_MODE_CREATE_ROOM] = create_room_mode;
    env->mouse_click_fct[MOUSE_MODE_PLACING] = on_screen_place_mode;
}

void init_txt_img(t_env *env)
{
    env->txt_lst[TXT_MAP_EDITOR] = create_text_img("map_editor", 2, 0xFFDDDDDD, create_point(0.005 * WIN_SIZE_X, 0.012 * WIN_SIZE_Y));
    env->txt_lst[TXT_TEXT_SELECT] = create_text_img("Texture", 1, 0xFFDDDDDD, create_point(0.798 * WIN_SIZE_X, 0.100 * WIN_SIZE_Y));
    env->txt_lst[TXT_HEIGHT] = create_text_img("Height", 1, 0xFFDDDDDD, create_point(0.235 * WIN_SIZE_X, 0.640 * WIN_SIZE_Y));
    env->txt_lst[TXT_P1] = create_text_img("P1", 1, 0xFFDDDDDD, create_point(0.210 * WIN_SIZE_X, 0.680 * WIN_SIZE_Y));
    env->txt_lst[TXT_P2] = create_text_img("P2", 1, 0xFFDDDDDD, create_point(0.315 * WIN_SIZE_X, 0.680 * WIN_SIZE_Y));
    env->txt_lst[TXT_BEGIN] = create_text_img("Begin", 1, 0xFFDDDDDD, create_point(0.120 * WIN_SIZE_X, 0.730 * WIN_SIZE_Y));
    env->txt_lst[TXT_END] = create_text_img("end", 1, 0xFFDDDDDD, create_point(0.120 * WIN_SIZE_X, 0.790 * WIN_SIZE_Y));
    env->txt_lst[TXT_TRANSPARENCY] = create_text_img("Transparency", 1, 0xFF00FF00, create_point(0.795 * WIN_SIZE_X, 0.620 * WIN_SIZE_Y));
    env->txt_lst[TXT_WALL_COUNT] = create_text_img("Wall_count", 1, 0xFF0000FF, create_point(0.500 * WIN_SIZE_X, 0.770 * WIN_SIZE_Y));
    env->txt_lst[TXT_MOB] = create_text_img("Mob", 1, 0xFFFF0000, create_point(0.845 * WIN_SIZE_X, 0.350 * WIN_SIZE_Y));
    env->txt_lst[TXT_ROOM_COUNT] = create_text_img("Room_count", 1, 0xFFDDDDDD, create_point(0.500 * WIN_SIZE_X, 0.670 * WIN_SIZE_Y));
    env->txt_lst[TXT_ROOM_HEIGHT] = create_text_img("Room", 1, 0xFFDDDDDD, create_point(0.120 * WIN_SIZE_X, 0.900 * WIN_SIZE_Y));
    env->txt_lst[TXT_ROOM_BOT] = create_text_img("Bot", 1, 0xFFDDDDDD, create_point(0.207 * WIN_SIZE_X, 0.855 * WIN_SIZE_Y));
    env->txt_lst[TXT_ROOM_TOP] = create_text_img("Top", 1, 0xFFDDDDDD, create_point(0.315 * WIN_SIZE_X, 0.855 * WIN_SIZE_Y));
    env->txt_lst[TXT_COLLIDE] = create_text_img("Can_collide", 1, 0xFFDDDDDD, create_point(0.500 * WIN_SIZE_X, 0.870 * WIN_SIZE_Y));
    env->txt_lst[TXT_WALL_ID] = create_text_img("Id", 1, 0xFFDDDDDD, create_point(0.700 * WIN_SIZE_X, 0.670 * WIN_SIZE_Y));

}
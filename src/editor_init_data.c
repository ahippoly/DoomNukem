#include "proto_global.h"

// OKK
static int	load_text_list(t_env *env)
{
    int		i;
	char	*path;

    env->selected_texture = 0;
	i = 0;
	if (!(path = ft_strnew(38)))
		exit_editor(env, "error : failed to load texture list with strnew");
	ft_bzero(path, sizeof(char) * 38);
	while (i < NB_TEXTURE)
	{
		ft_strcpy(path, "asset/img/textures/TEXT_PATH_");
		ft_strcat(path, ft_itoa(i));
		ft_strcat(path, ".bmp");
		if (access(path, R_OK) < 0)
			exit_editor(env, "error : failed to read file");
		if (!(env->text_list[i] = bmp_to_texture(path, env->rend)))
			exit_editor(env, "error : failed to create texture from bmp file");
		ft_bzero(path, sizeof(char) * 38);
		i++;
	}
	free(path);
	return (0);
}

void		init_texture(t_env *env)
{
	if (!(env->text_list = malloc_texture_tab(NB_TEXTURE)))
		exit_editor(env, "error: failed to malloc");
	load_text_list(env);
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
	if (!(env->txt_lst = malloc_txtimg(NB_TXT)))
		exit_editor(env, "error: failed to malloc texture list");
    env->txt_lst[TXT_MAP_EDITOR] = create_text_img("map_editor", 2, 0xFFDDDDDD, create_point(0.005 * WIN_SIZE_X, 0.012 * WIN_SIZE_Y));
    env->txt_lst[TXT_TEXT_SELECT] = create_text_img("Texture", 1, 0xFFDDDDDD, create_point(0.798 * WIN_SIZE_X, 0.100 * WIN_SIZE_Y));
    env->txt_lst[TXT_HEIGHT] = create_text_img("Height", 1, 0xFFDDDDDD, create_point(0.235 * WIN_SIZE_X, 0.640 * WIN_SIZE_Y));
    env->txt_lst[TXT_P1] = create_text_img("P1", 1, 0xFFDDDDDD, create_point(0.210 * WIN_SIZE_X, 0.680 * WIN_SIZE_Y));
    env->txt_lst[TXT_P2] = create_text_img("P2", 1, 0xFFDDDDDD, create_point(0.315 * WIN_SIZE_X, 0.680 * WIN_SIZE_Y));
    env->txt_lst[TXT_BEGIN] = create_text_img("Begin", 1, 0xFFDDDDDD, create_point(0.120 * WIN_SIZE_X, 0.730 * WIN_SIZE_Y));
    env->txt_lst[TXT_END] = create_text_img("end", 1, 0xFFDDDDDD, create_point(0.120 * WIN_SIZE_X, 0.790 * WIN_SIZE_Y));
    env->txt_lst[TXT_TRANSPARENCY] = create_text_img("Transparency", 1, 0xFF00FF00, create_point(0.795 * WIN_SIZE_X, 0.620 * WIN_SIZE_Y));
    env->txt_lst[TXT_WALL_COUNT] = create_text_img("Wall_count", 1, RED, create_point(0.500 * WIN_SIZE_X, 0.770 * WIN_SIZE_Y));
    env->txt_lst[TXT_MOB] = create_text_img("Mob", 1, 0xFFFF0000, create_point(0.845 * WIN_SIZE_X, 0.350 * WIN_SIZE_Y));
    env->txt_lst[TXT_ROOM_COUNT] = create_text_img("Room_count", 1, 0xFFDDDDDD, create_point(0.500 * WIN_SIZE_X, 0.670 * WIN_SIZE_Y));
    env->txt_lst[TXT_ROOM_HEIGHT] = create_text_img("Room", 1, 0xFFDDDDDD, create_point(0.120 * WIN_SIZE_X, 0.900 * WIN_SIZE_Y));
    env->txt_lst[TXT_ROOM_BOT] = create_text_img("Bot", 1, 0xFFDDDDDD, create_point(0.207 * WIN_SIZE_X, 0.855 * WIN_SIZE_Y));
    env->txt_lst[TXT_ROOM_TOP] = create_text_img("Top", 1, 0xFFDDDDDD, create_point(0.315 * WIN_SIZE_X, 0.855 * WIN_SIZE_Y));
    env->txt_lst[TXT_COLLIDE] = create_text_img("Can_collide", 1, 0xFFDDDDDD, create_point(0.500 * WIN_SIZE_X, 0.870 * WIN_SIZE_Y));
    env->txt_lst[TXT_WALL_ID] = create_text_img("Id", 1, 0xFFDDDDDD, create_point(0.700 * WIN_SIZE_X, 0.670 * WIN_SIZE_Y));
}
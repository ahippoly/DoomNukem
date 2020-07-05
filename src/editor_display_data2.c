#include "proto_global.h"

//OKK

void txt_img2screen(t_env *env, t_txt_img img)
{
    if ((SDL_UpdateTexture(env->screen, &img.pos_size, img.pixels, img.pos_size.w * 4)) < 0)
		exit_editor(env, "error : failed to update texture");
}

void display_buttons(t_env *env)
{
    int i;

    i = 0;
    while (i < NB_BUTTONS)
        txt_img2screen(env, *env->buttons_lst[i++].printed);
}

void display_txt_img(t_env *env)
{
    int i;

    i = 0;
    while (i < NB_TXT)
        txt_img2screen(env, env->txt_lst[i++]);
}

void update_sprite_texture(t_env *env)
{
	if ((SDL_UpdateTexture(env->img_list[IMG_AFRIT], NULL, env->sprites[SPRITE_ID_AFRIT].dst, env->sprites[SPRITE_ID_AFRIT].dst_w * 4)) < 0)
		exit_editor(env, "error : failed to update texture");
	if ((SDL_UpdateTexture(env->img_list[IMG_ORC], NULL, env->sprites[SPRITE_ID_PYRO].dst, env->sprites[SPRITE_ID_PYRO].dst_w * 4)) < 0)
		exit_editor(env, "error : failed to update texture");
}
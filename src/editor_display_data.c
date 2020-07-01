#include "proto_global.h"
#include "proto_global.h"

void txt_img2screen(t_env *env, t_txt_img img)
{
    SDL_UpdateTexture(env->screen, &img.pos_size, img.pixels, img.pos_size.w * 4);
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
	SDL_UpdateTexture(env->img_list[IMG_AFRIT], NULL, env->sprites[SPRITE_ID_AFRIT].dst, env->sprites[SPRITE_ID_AFRIT].dst_w * 4);
	SDL_UpdateTexture(env->img_list[IMG_ORC], NULL, env->sprites[SPRITE_ID_PYRO].dst, env->sprites[SPRITE_ID_PYRO].dst_w * 4);
}

void print_env2screen(t_env *env)
{
    SDL_Rect tmp;
    // SDL_UpdateTexture(env->screen, NULL, env->p_screen, WIN_SIZE_X * 4);
    // SDL_RenderCopy(env->rend, env->screen, NULL, NULL);
    // SDL_UpdateTexture(env->editor_grid, NULL, env->p_grid, GRID_SIZE_X * 4);
    // SDL_RenderCopy(env->rend, env->editor_grid, NULL, &env->grid_pos);
    // SDL_RenderPresent(env->rend);
    print_inputs(env);
    input_text_to_img(ft_itoa(env->wall_count), 2, 0xFFFFFFFF, create_img(env->p_screen, set_sdl_rect(0.530 * WIN_SIZE_X, 0.800 * WIN_SIZE_Y, WIN_SIZE_X, WIN_SIZE_Y)));
    input_text_to_img(ft_itoa(env->room_count), 2, 0xFFFFFFFF, create_img(env->p_screen, set_sdl_rect(0.530 * WIN_SIZE_X, 0.700 * WIN_SIZE_Y, WIN_SIZE_X, WIN_SIZE_Y)));
    input_text_to_img(ft_itoa(env->selected_wall_id), 2, 0xFFFFFFFF, create_img(env->p_screen, set_sdl_rect(0.700 * WIN_SIZE_X, 0.700 * WIN_SIZE_Y, WIN_SIZE_X, WIN_SIZE_Y)));
    //input_text_to_img("test", 1, 0xFF00FF00, create_img(env->buttons_lst[1].normal.pixels, set_sdl_rect(0,0,env->buttons_lst[1].normal.pos_size.w, env->buttons_lst[1].normal.pos_size.h)));
    SDL_UpdateTexture(env->screen, NULL, env->p_screen, WIN_SIZE_X * 4);
    SDL_UpdateTexture(env->editor_grid, NULL, env->p_grid, GRID_SIZE_X * 4);
    display_txt_img(env);
    display_buttons(env);
    SDL_RenderCopy(env->rend, env->screen, NULL, NULL);
    print_icon_list(env);
    print_player_spawn(env);
    print_mouse_icon(env);
    SDL_RenderCopy(env->rend, env->editor_grid, NULL, &env->grid_pos);

    //SDL_UpdateTexture(env->text_list[env->selected_texture], NULL, env->img_list[env->selected_texture].pixels, env->img_list[0].pos_size.w * 4);
    tmp = set_sdl_rect(TEXT_POS_X, TEXT_POS_Y, TEXT_SIZE_X, TEXT_SIZE_Y);
    SDL_RenderCopy(env->rend, env->text_list[env->selected_texture], NULL, &tmp);
    //tmp = set_sdl_rect(ICON_MOB_POS_X, ICON_MOB_POS_Y, ICON_MOB_SIZE_X, ICON_MOB_SIZE_Y);
	update_sprite_texture(env);
    tmp = set_sdl_rect(ICON_MOB_POS_X, ICON_MOB_POS_Y, ICON_MOB_SIZE_X, ICON_MOB_SIZE_Y);
    SDL_RenderCopy(env->rend, env->img_list[env->selected_mob], NULL, &tmp);
    SDL_RenderPresent(env->rend);
}
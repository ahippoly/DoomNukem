#include "proto_global.h"
#include "proto_global.h"

void reset_textures(t_env *env)
{
    ft_bzero(env->p_screen, WIN_SIZE_X * WIN_SIZE_Y * 4);
    ft_bzero(env->p_grid, GRID_SIZE_X * GRID_SIZE_Y * 4);
}

void handle_keyboard_event(t_env *env)
{
    if(env->clavier[SDL_SCANCODE_ESCAPE] || env->clavier[SDL_SCANCODE_RETURN])
        env->quit = 1;
    if(env->clavier[SDL_SCANCODE_D])
        move_map_move_right(env);
    if(env->clavier[SDL_SCANCODE_A])
        move_map_move_left(env);
    if(env->clavier[SDL_SCANCODE_W])
        move_map_move_up(env);
    if(env->clavier[SDL_SCANCODE_S])
        move_map_move_down(env);
}

int main(int argc, char **argv)
{
    t_env       env;
    
	ft_putendl("load map...");
	ft_bzero(&env, sizeof(t_env));
    init_env(&env);
	load_map(&env, argc, argv);
    while(!env.quit)
    {
        reset_textures(&env);
        env.clavier = SDL_GetKeyboardState(NULL);
        env.mouse_button = SDL_GetMouseState(&env.mouse.x, &env.mouse.y);
        handle_keyboard_event(&env);
        env.hovered_corner = check_tiles_hitbox(env.mouse, env.p_grid, &env);
		process_anim(&env.sprites[SPRITE_ID_AFRIT], SDL_GetTicks());
		process_anim(&env.sprites[SPRITE_ID_PYRO], SDL_GetTicks());
        create_grid(env.p_grid, 1, &env);
        check_hovered_buttons(&env);
        check_hovered_input(&env);
        handle_mouse_event(&env);
        print_walls_in_map(&env);
        check_mouse_in_walls(&env);
        print_selected_wall(&env);
        display_selected_point(&env);
        print_env2screen(&env);
    }
	// free(env.map_name); dans exit_env
    // clear_map_ref(&env); dans exit_env
	exit_editor(&env);
}
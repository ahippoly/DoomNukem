/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 22:55:31 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/12 19:35:54 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

static void	reset_textures(t_env *env)
{
	ft_bzero(env->p_screen, WIN_SIZE_X * WIN_SIZE_Y * 4);
	ft_bzero(env->p_grid, GRID_SIZE_X * GRID_SIZE_Y * 4);
}

int			main(int argc, char **argv)
{
	t_env	env;

	ft_bzero(&env, sizeof(t_env));
	init_env(&env);
	load_map(&env, argc, argv);
	printf("null\n");
	while (!env.quit)
	{
		reset_textures(&env);
		env.clavier = SDL_GetKeyboardState(NULL);
		env.mouse_button = SDL_GetMouseState(&env.mouse.x, &env.mouse.y);
		handle_keyboard_event(&env);
		env.hovered_corner = check_tiles_hitbox(env.mouse, env.p_grid, &env);
		process_anim(&env.sprites[SPRITE_ID_AFRIT], SDL_GetTicks());
		process_anim(&env.sprites[SPRITE_ID_PYRO], SDL_GetTicks());
		create_grid(env.p_grid, &env);
		check_hovered_buttons(&env);
		check_hovered_input(&env);
		handle_mouse_event(&env);
		print_walls_in_map(&env);
		check_mouse_in_walls(&env);
		print_selected_wall(&env);
		display_selected_point(&env);
		print_env2screen(&env);
	}
	exit_editor(&env, "bye editor!");
}

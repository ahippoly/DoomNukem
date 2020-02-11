/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 21:12:49 by saneveu           #+#    #+#             */
/*   Updated: 2020/02/07 21:14:36 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			put_texture(t_enval *env)
{
	SDL_LockSurface(env->sdl.screen);
	env->sdl.text = SDL_CreateTextureFromSurface(env->sdl.rend, env->sdl.screen);
	SDL_RenderCopy(env->sdl.rend, env->sdl.text, NULL, NULL);
	SDL_UnlockSurface(env->sdl.screen);
    SDL_RenderPresent(env->sdl.rend);
	SDL_DestroyTexture(env->sdl.text);
	SDL_SetRenderDrawColor(env->sdl.rend, 0, 0, 0, 0);
	SDL_RenderClear(env->sdl.rend);
}

void			display(t_enval *env)
{
	ray_draw(env);
	//nmi action
	//nmi affichage
	//(nmi remove)
	//weapon display -> apons' priority
	put_texture(env);
}
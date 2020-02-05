/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:35:19 by apons             #+#    #+#             */
/*   Updated: 2020/02/05 13:20:19 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gameplay.h"

void	game_loop(t_game *game)
{
	if (!game->pc.health.current)
		display_game_over();
	else
		ft_putendl("This is a work in progress");
}
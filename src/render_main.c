/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <alebui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 05:17:58 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/09 14:38:38 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"
#include <errno.h>

int					main(int ac, char **av)
{
	t_data			d;

	init_data(&d, ac, av);
	init_sound(&d);
	play_sound(&d, MUS2);
	while (d.run_game > 0)
	{
		if (d.run_game == GAME)
			render_game(&d);
		else if (d.run_game == MENU)
			render_menu(&d);
		else if (d.run_game == GAMEOVER)
			render_gameover(&d);
		else if (d.run_game == EDITOR)
		{
			if (access("./editor", X_OK))
				d.run_game = 0;
			else
				execv("./editor", av);
		}
		else if (d.run_game == WIN)
			render_win(&d);
	}
	exit_game(&d, "");
}

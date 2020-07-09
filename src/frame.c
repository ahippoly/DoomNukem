/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <alebui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 11:14:58 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/09 15:38:03 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void			calc_n_disp_framerate(t_data *d)
{
	static int	last_time;
	static int	framerate;
	static int	last_framerate;
	int			time;
	char		*str;

	time = SDL_GetTicks();
	if (time > last_time + 1000)
	{
		last_framerate = framerate;
		create_mini_map(d, &d->map);
		framerate = 0;
		last_time = time;
	}
	framerate += 1;
	str = ft_itoa(last_framerate);
	if ((input_text_to_img(str, 2, 0xFFFFFFFF, create_img(d->p_screen,
				set_sdl_rect(5, 5, WIN_SIZE_X, WIN_SIZE_Y)))) < 0)
		exit_game(d, "error : failed to transform input text to image");
	free(str);
}

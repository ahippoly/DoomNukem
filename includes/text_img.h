/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_img.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 00:11:50 by robin             #+#    #+#             */
/*   Updated: 2020/07/06 00:12:34 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXT_IMG_H
# define TEXT_IMG_H

# include "SDL.h"

# define CHAR_NB 41
# define SIZE_X 10
# define SIZE_Y 10
# define PIXEL '#'
# define CHART_FILE "src/img_char_charts2"

typedef struct		s_txt_img
{
	unsigned int	*pixels;
	SDL_Rect		pos_size;
	int				color;
}					t_txt_img;

typedef struct		s_button
{
	t_txt_img		*printed;
	t_txt_img		normal;
	t_txt_img		hovered;
	int				button_id;
}					t_button;

t_txt_img			create_text_img(char *str, int size, int color,
						SDL_Point pos);

#endif

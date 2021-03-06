/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_file.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 23:07:42 by robin             #+#    #+#             */
/*   Updated: 2020/07/07 16:12:57 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_FILE_H
# define IMG_FILE_H

# include "SDL.h"

# define BMP_HEADER_READ 32
# define BMP_TYPE_BGRA 0
# define BMP_TYPE_ABGR 1
# define BMP_TYPE_RGBA 2
# define BMP_TYPE_ARGB -1

typedef struct		s_img
{
	unsigned int	*pixels;
	SDL_Rect		pos_size;
	int				w;
	int				h;
}					t_img;

typedef struct		s_text
{
	t_img			img;
	SDL_Texture		*txt;
}					t_text;

t_img				create_img(unsigned int *pixels, SDL_Rect pos_size);
SDL_Texture			*bmp_to_texture(char *file, SDL_Renderer *rend);

#endif

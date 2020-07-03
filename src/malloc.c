#include "proto_global.h"

SDL_Texture		**malloc_texture_tab(int size)
{
	SDL_Texture	**tab;

	if (!(tab = (SDL_Texture**)ft_memalloc(sizeof(SDL_Texture *) * (size + 1))))
		return (NULL);
	return (tab);
}

t_range			*malloc_range(int size)
{
	t_range		*range;

	if (!(range = (t_range*)ft_memalloc(sizeof(t_range) * (size + 1))))
		return (NULL);
	return (range);
}

int				*malloc_int_tab(int size)
{
	int			*tab;

	if (!(tab = (int *)ft_memalloc(sizeof(int) * (size + 1))))
		return (NULL);
	return (tab);
}

t_icon			*malloc_icon(int size)
{
	t_icon		*ptr;

	if (!(ptr = (t_icon *)ft_memalloc(sizeof(t_icon) * (size + 1))))
		return (NULL);
	return (ptr);
}

/*
t_wall			*malloc_wall(int size)
{
	t_icon		*ptr;

	if (!(ptr = (t_wall *)ft_memalloc(sizeof(t_wall) * (size + 1))))
		return (NULL);
	return (ptr);
}
*/

t_img			*malloc_img(int size)
{
	t_img		*img;

	if (!(img = (t_img *)ft_memalloc(sizeof(t_img) * (size + 1))))
		return (NULL);
	return (img);
}

t_ssprite		*malloc_ssprite(int size)
{
	t_ssprite	*sprite;

	if (!(sprite = (t_ssprite *)ft_memalloc(sizeof(t_ssprite) * (size + 1))))
		return (NULL);
	return (sprite);
}

/* buttons_lst[NB_BUTTONS] */
t_button		*malloc_button(int size)
{
	t_button	*button;

	if (!(button = (t_button*)ft_memalloc(sizeof(t_button) * (size + 1))))
		return (NULL);
	return (button);
}

/* txt_lst[NB_TXT] */
t_txt_img		*malloc_txtimg(int size)
{
	t_txt_img	*txt;

	if (!(txt = (t_txt_img *)ft_memalloc(sizeof(t_txt_img) * (size + 1))))
		return (NULL);
	return (txt);
}

/* input_lst[NB_INPUT] */
t_input			*malloc_input(int size)
{
	t_input		*input;

	if (!(input = (t_input *)ft_memalloc(sizeof(t_input) * (size + 1))))
		return (NULL);
	return (input);
}
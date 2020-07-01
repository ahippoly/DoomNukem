#include "proto_global.h"

/* fichier malloc editor.h */

SDL_Texture		**malloc_texture_tab(int size)
{
	SDL_Texture	**tab;

	if (!(tab = (SDL_Texture**)ft_memalloc(sizeof(SDL_Texture *) * (nb + 1))))
		return (NULL);
	return (tab);
}

t_range			*malloc_range(int size)
{
	t_range		*range;

	if (!(range = (t_range*)ft_memalloc(sizeof(t_range) * (nb + 1))))
		return (NULL);
	return (range);
}

t_button		*malloc_button(int size)
{
	t_button	*button;

	if (!(button = (t_button*)ft_memalloc(sizeof(t_button) * (nb + 1))))
		return (NULL);
	return (button);
}

t_txt_img		*malloc_txtimg(int size)
{
	t_txt_img	*txt;

	if (!(txt = (t_txt_img *)ft_memalloc(sizeof(t_txt_img) * (nb + 1))))
		return (NULL);
	return (txt);
}

t_input			*malloc_input(int size)
{
	t_input		*input;

	if (!(input = (t_input *)ft_memalloc(sizeof(t_input) * (nb + 1))))
		return (NULL);
	return (input);
}
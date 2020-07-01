#include "proto_global.h"

/* Fichier de malloc sprite */

/* malloc SDL_Point pos[NB_FRAME] | ssprite.h */
SDL_Point		*malloc_sdl_point(int size)
{
	SDL_Point	*pos;
	
	if (!(pos = (SDL_Point *)ft_memalloc(sizeof(SDL_Point) * (nb + 1))))
		return (NULL);
	return (pos);
}

/* malloc t_size size[NB_FRAME] | ssprite.h */
t_size			*malloc_size(int size)
{
	t_size		*size;

	if (!(size = (t_size *)ft_memalloc(sizeof(t_size) * (nb + 1))))
		return (NULL);
	return (size);
}

/* malloc t_anim anim[NB_ANIM] | ssprite.h */
t_anim			*malloc_anim(int size)
{
	t_size		*anim;

	if (!(anim = (t_anim *)ft_memalloc(sizeof(t_anim) * (nb + 1))))
		return (NULL);
	return (anim);
}

int				**malloc_int_tab(int size)
{
	int			**tab;

	if (!(tab = (int **)ft_memalloc(sizeof(int *) * nb)))
		return (NULL);
	return (tab);
}
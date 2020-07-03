#include "proto_global.h"

/* text_list[NB_TEXTURE] */
SDL_Texture		**malloc_texture_tab(int size)
{
	SDL_Texture	**tab;

	if (!(tab = (SDL_Texture**)ft_memalloc(sizeof(SDL_Texture *) * (size + 1))))
		return (NULL);
	return (tab);
}

/*
int				exit_env()
{

}
*/
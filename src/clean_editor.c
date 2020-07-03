#include "proto_global.h"

/* text_list[NB_TEXTURE] */
SDL_Texture		**malloc_texture_tab(int size)
{
	SDL_Texture	**tab;

	if (!(tab = (SDL_Texture**)ft_memalloc(sizeof(SDL_Texture *) * (size + 1))))
		return (NULL);
	return (tab);
}

int				destroy_texture_tab(SDL_Texture **tab, int size)
{
	int			i;

	i = 0;
	while (tab[i])
	{
		SDL_DestroyTexture(tab[i]);
		i++;
	}
	SDL_DestroyTexture(tab);
	return (0);
}

void			clear_map_ref(t_env *env)
{
    int			i;
    int			j;
    t_wall_ref *wall_ref;
    t_wall_ref *tmp;

    i = 0;
    if (env->map_wall_ref == NULL)
        return ;
    while (i < env->map_size.h)
    {
        j = 0;
        while (j < env->map_size.w)
        {
            wall_ref = env->map_wall_ref[i][j];
            while (wall_ref != NULL)
            {
                tmp = wall_ref;
                wall_ref = wall_ref->next;
                free(tmp);
            }
            j++;
        }
        free(env->map_wall_ref[i]);
        i++;
    }
    free(env->map_wall_ref);
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

int				exit_editor(t_env *e)
{
	ft_putendl("exiting editor...");
	if (e->map_name != NULL)
		free(e->map_name);
	if (e->room_height)
		free(e->room_height);
	if (e->room_text)
		free(e->room_text);
	if (e->icon_list)
		free(e->icon_list);
	destroy_texture_tab(e->text_list, NB_TEXTURE); //**text_list;
	destroy_texture_tab(e->img_list, NB_IMG); //**img_list;
	clear_map_ref(e);
	exit(0);
}
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
	while ((SDL_Texture *)tab[i])
	{
		SDL_DestroyTexture((SDL_Texture *)tab[i]);
		i++;
	}
	free(tab);
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

int				exit_editor(t_env *e)
{
	ft_putendl("exiting editor...");
	free(e->map_name);
	destroy_texture_tab(e->text_list, NB_TEXTURE);
	clear_map_ref(e);
	exit(0);
}
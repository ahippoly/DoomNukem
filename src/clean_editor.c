#include "proto_global.h"

/* text_list[NB_TEXTURE] */
int				destroy_texture_tab(SDL_Texture **tab, int size)
{
	int			i;

	i = 0;
	while (tab[i])
	{
		SDL_DestroyTexture(tab[i]);
		i++;
	}
	SDL_DestroyTexture(*tab);
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

int				exit_editor(t_env *e, char *msg)
{
	ft_putendl(msg);
	if (e->map_name)
		free(e->map_name);
	if (e->room_height)
		free(e->room_height);
	if (e->room_text)
		free(e->room_text);
	if (e->icon_list)
		free(e->icon_list);
	if (e->wall_list)
		free(e->wall_list);
	if (e->room_list)
		free(e->room_list);
	if (e->text_list)
		destroy_texture_tab(e->text_list, NB_TEXTURE); //**text_list;
	if (e->img_list)
		destroy_texture_tab(e->img_list, NB_IMG); //**img_list;
	if (e->p_screen)
		free(e->p_screen);
	if (e->p_grid)
		free(e->p_grid);
	if (e->sprite_img)
		free(e->sprite_img);
	if (e->buttons_lst)
		free(e->buttons_lst);
	if (e->txt_lst)
		free(e->txt_lst);
	if (e->input_lst)
		free(e->input_lst);
	clear_map_ref(e);
	if (e->win)
		SDL_DestroyWindow(e->win);
	if (e->screen)
		SDL_DestroyTexture(e->screen);
	if (e->rend)
		SDL_DestroyRenderer(e->rend);
	if (e->editor_grid)
		SDL_DestroyTexture(e->editor_grid);
	exit(0);
}
#include "proto_global.h"

int		free_floor(t_data *d)
{
	int	i;

	i = 0;
	while (d->fl[i])
	{
		if (d->fl[i])
			free(d->fl[i]);
		i++;
	}
	free(d->fl);
	return (0);
}

/* j'appelle les fonctions qui free des tableau de pointeur */
void	free_obj_tab(t_obj **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i]->pixels)
			free(tab[i]->pixels);
		if (tab[i]);
			free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_data_tab(t_data *d)
{
	free_floor(d);
	//free_obj_tab(d->repulsed, NB_MAX_MOBS + NB_MAX_PROPS);
}

void	free_data_ptr(t_data *d)
{
	if (d->map.icon_list)
		free(d->map.icon_list);
	if (d->p_screen)
		free(d->p_screen);
	if (d->p_mini_map_bg)
		free(d->p_mini_map_bg);
	if (d->p_player_pos)
		free(d->p_player_pos);
	if (d->p_hud)
		free(d->p_hud);
	if (d->props)
		free(d->props);
	if (d->mobs)
		free(d->mobs);
	if (d->obj_list)
		free(d->obj_list);
	// if (d->sprite)
	// 	free(d->sprite);
	// if (d->repulsed)
	// 	free(d->repulsed);
	if (d->texture)
		free(d->texture);
	if (d->img)
		free(d->img);
	if (d->sprite_img)
		free(d->sprite_img);
	if (d->p_menu)
		free(d->p_menu);
	if (d->grabbed_wall)
		free(d->grabbed_wall);
	free_data_tab(d);
}

void			free_sdl_ptr_data(t_data *d)
{
	if (d->win)
		SDL_DestroyWindow(d->win);
	if (d->screen)
		SDL_DestroyTexture(d->screen);
	if (d->rend)
		SDL_DestroyRenderer(d->rend);
	if (d->mini_map)
		SDL_DestroyTexture(d->mini_map);
	if (d->hud_texture)
		SDL_DestroyTexture(d->hud_texture);
	if (d->gameover_texture)
		SDL_DestroyTexture(d->gameover_texture);
}

void exit_game(t_data *d, char *msg)
{
	ft_putendl(msg);
	free_menu(d);
	free_gameover(d);
	free_hud(&d->hud);
	//clean_sprite_gun(d);
	free_data_ptr(d);
	clean_sounds(d);
	free_sdl_ptr_data(d);
	quit_ttf(d);
	SDL_Quit();
	ft_putendl("bye !");
	exit(0);
}
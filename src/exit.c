#include "proto_global.h"

int		free_floor(t_data *d)
{
	int	i;

	i = 0;
	while (i < (NB_WALL_MAX / 2))
	{
		free(d->fl[i]);
		i++;
	}
	free(d->fl);
	return (0);
}

void	free_obj_tab(t_obj **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_data_tab(t_data *d)
{
	free_floor(d);
	free_obj_tab(d->repulsed, NB_MAX_MOBS + NB_MAX_PROPS);
}

void	free_data_ptr(t_data *d)
{
	if (d->props)
		free(d->props);
	if (d->mobs)
		free(d->mobs);
	if (d->obj_list)
		free(d->obj_list);
	// if (d->sprite)
	// 	free(d->sprite);
	if (d->repulsed)
		free(d->repulsed);
	if (d->texture)
		free(d->texture);
	if (d->img)
		free(d->img);
	if (d->sprite_img)
		free(d->sprite_img);
}

void exit_game(t_data *d, char *msg)
{
	ft_putendl(msg);
	free_menu(d);	
	free_hud(&d->hud);
	//clean_sprite_gun(d);
	free_data_ptr(d);
	clean_sounds(d);
	/* SDL */
	quit_ttf(d);
	SDL_Quit();
	ft_putendl("bye !");
	exit(0);
}
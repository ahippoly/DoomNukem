#include "proto_global.h"

int			free_menu(t_data *d)
{
	if (!d)
		return (0);
	if (d->menu_texture)
		SDL_DestroyTexture(d->menu_texture);
	if (d->menu.menu_bg_t)
		SDL_DestroyTexture(d->menu.menu_bg_t);
	if (d->menu.btn)
		SDL_DestroyTexture(d->menu.btn);
	if (d->menu.text0_t)
		SDL_DestroyTexture(d->menu.text0_t);
	if (d->menu.text1_t)
		SDL_DestroyTexture(d->menu.text1_t);
	if (d->menu.text2_t)
		SDL_DestroyTexture(d->menu.text2_t);
	return (0);
}

static int	free_argv_tab(t_data *d)
{
	int		i;

	while (i < 3)
	{
		if (d->menu.argv_tab[i])
		{
			free(d->menu.argv_tab[i]);
			d->menu.argv_tab[i] = NULL;
		}
		i++;
	}
	free(d->menu.argv_tab);
	d->menu.argv_tab = NULL;
	return (0);
}

int			exit_menu(t_data *d)
{
	ft_putendl("Free menu...");
	free_menu(d);
	free_argv_tab(d);
	quit_ttf(d);
	SDL_Quit();
	ft_putendl("bye !");
	exit(-1);
}
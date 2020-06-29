#include "proto_global.h"

static int	free_texture_menu(t_data *d)
{
	if (!d)
		return (0);
	if (d->menu_texture)
		SDL_DestroyTexture(d->menu_texture);
	if (d->menu.menu_bg_t)
		SDL_DestroyTexture(d->menu.menu_bg_t);
	if (d->menu.btn)
		SDL_DestroyTexture(d->menu.btn);
	if (d->menu.play_t)
		SDL_DestroyTexture(d->menu.play_t);
	if (d->menu.editor_t)
		SDL_DestroyTexture(d->menu.editor_t);
	if (d->menu.quit_t)
		SDL_DestroyTexture(d->menu.quit_t);
	return (0);
}

static int	free_gameover(t_data *d)
{
	if (!d)
		return (0);
	if (d->menu.gameover_t)
		SDL_DestroyTexture(d->menu.gameover_t);
	if (d->menu.over_continue_t)
		SDL_DestroyTexture(d->menu.over_continue_t);
	if (d->menu.over_quit_t)
		SDL_DestroyTexture(d->menu.over_quit_t);
	return (0);
}

static int	free_argv_tab(t_data *d)
{
	int		i;

	i = 0;
	if (d->menu.argv_tab)
	{
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
	}
	d->menu.argv_tab = NULL;
	return (0);
}

int			free_menu(t_data *d)
{
	free_texture_menu(d);
	free_argv_tab(d);
	return (0);
}

int			exit_menu(t_data *d)
{
	free_menu(d);
	free_gameover(d);
	quit_ttf(d);
	SDL_Quit();
	ft_putendl("bye !");
	exit(-1);
}
#include "proto_global.h"

int			is_mouse_on_target(t_data *d, SDL_Rect pos)
{
	if (d->e.motion.x > pos.x && d->e.motion.x < pos.x + pos.w
		&& d->e.motion.y > pos.y && d->e.motion.y < pos.y + pos.h)
	{
		if (d->e.type == SDL_MOUSEBUTTONDOWN)
			if (d->e.button.button == SDL_BUTTON_LEFT)
				return (1);
	}
	return (0);
}

char		**malloc_tab(t_data *d, int n)
{
	char	**tab;

	if ((!(tab = (char **)ft_memalloc(sizeof(char *) * n))))
		exit_menu(d);
	return (tab);
}

int			catch_btn_event(t_data *d, int ac, char **av)
{
	char	**argv_tab; // permet de passer la liste des arguments a execv

	d->menu.argv_tab = malloc_tab(d, 3);
	d->menu.argv_tab[0] = NULL;
	d->menu.argv_tab[1] = ft_strdup(av[1]); // map passée en parametre
	d->menu.argv_tab[2] = NULL;
	if (is_mouse_on_target(d, set_sdl_rect(WIN_SIZE_X / 2, WIN_SIZE_Y / 3, 200, 50)) == 1)
	{
		d->menu.argv_tab[0] = ft_strdup("./doom-nukem");
		if (execv("./doom-nukem", d->menu.argv_tab) && access("./doom-nukem", W_OK))
			return (exit_menu(d));
	}
	else if (is_mouse_on_target(d, set_sdl_rect(WIN_SIZE_X / 2, WIN_SIZE_Y / 3 + 100, 200, 50)) == 1)
	{
		d->menu.argv_tab[0] = ft_strdup("./editor");
		if (execv("./editor", d->menu.argv_tab) && access("./editor", W_OK))
			return (exit_menu(d));
	}
	else if (is_mouse_on_target(d, set_sdl_rect(WIN_SIZE_X / 2, WIN_SIZE_Y / 3 + 200, 200, 50)) == 1)
		return (exit_menu(d));
	return (0);
}
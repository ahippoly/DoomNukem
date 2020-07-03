#include "proto_global.h"

int		free_env(t_env *e)
{
	if (e->rend)
		free(e->rend);
	if (e->win)
		free(e->win);
	if (e->screen)
		free(e->screen);
	if (e->editor_grid)
		free(e->editor_grid);
	if (e->text_list) // a verifier
	{
		while (e->(*text_list))
		{
			free(e->(*text_list));
			e->(*text_list)++;
		}
		free(e->text_list);
	}
	if (e->img_list) 
	{
		while (e->(*img_list))
		{
			free(e->(*img_list));
			e->(*img_list)++;
		}
		free(e->img_list);
	}
	if (e->p_screen)
		free(e->p_scren);
	if (e->p_grid)
		free(e->p_grid);
	
}

int		exit_env(t_env *e)
{
	ft_bzero(e->input, sizeof(t_input));
	ft_bzero(e, sizeof(t_env)); //déclaré en dure dans editor_main donc pas besoin de free a la fin du main
}
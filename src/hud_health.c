#include <hud.h>

/* Récupérer les paramètre les PV */
int				put_lifebar(t_data *d)
{
	SDL_Rect	hp_outline; //health point

	hp_outline = set_sdl_rect(100, 70, 300, 30);
	/* Contour de la jauge en transparence */
	SDL_SetRenderDrawColor(d->rend, 255, 255, 255, 128);
	// SDL_SetRenderDrawBlendMode(d->rend, SDL_BLENDMODE_BLEND);
	SDL_RenderDrawRect(d->rend, &hp_outline);
 	SDL_RenderPresent(d->rend);
	/* remplissage de l'arrière plan de la jauge */
    draw_rectangle(d->p_screen, set_sdl_rect(100, 70, 300, 30), set_size(WIN_SIZE_X, WIN_SIZE_Y), HEALTH_BG);
	/* Remplissage de la jauge de vie */
	draw_rectangle(d->p_screen, set_sdl_rect(100, 70, 200, 30), set_size(WIN_SIZE_X, WIN_SIZE_Y), HEALTH);
	SDL_RenderCopy(d->rend, d->screen, NULL, NULL);
	return (0);
}
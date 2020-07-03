#include "proto_global.h"

int	render_menu(t_data *d, int ac, char **av)
{
	// t_img test = ft_load_bmp2(IMG_PATH_4);


	while (d->run_game == MENU)
	{
		SDL_PumpEvents();
		handle_key_event(d);
		handle_poll_event(d);
		put_menu_bg(d);
		render_btn(d);
		catch_btn_event(d, ac, av);
		// print_text_screen(d->p_screen, &test, (SDL_Rect){100, 100, 300, 300});
		// SDL_UpdateTexture(d->screen, NULL, d->p_screen, WIN_SIZE_X * 4);
		// SDL_RenderCopy(d->rend, d->screen, NULL, NULL);
 		SDL_RenderPresent(d->rend);
	}
	return (0);
}
#include "proto_global.h"

int	render_game(t_data *d, int ac, char **av)
{
	// init_sound(d);
    // play_sound(d, MUS1);
	// ft_load_bmp2(IMG_PATH_0);
	// ft_load_bmp2(IMG_PATH_1);
	//t_img test = read_img_surface(SPRITE_PATH_PYRO, SDL_PIXELFORMAT_ARGB32);
	while (d->run_game == GAME)
	{
		d->time_last_frame = d->time;
		d->time = SDL_GetTicks();
		d->diff_time = (float)(d->time - d->time_last_frame) / 1000;
		SDL_PumpEvents();
		handle_poll_event(d);
		handle_key_event(d);
		gravity(d);
		create_obj_raybox(d);
		process_mobs_gameplay(d);
		process_gun(d->actual_weapon, d->time, d);
		check_props_collect(d, d->props, &d->hud);
		raycast_thread_init(d);
		print_skybox(d, d->skybox, d->rot_calc.rot, d->p_screen);
		// print_text_screen(d->p_screen, &d->sprite_img[0], (SDL_Rect){100, 100, 200, 200});
		sprite_anim_gun(d);
		update_player_pos_mini_map(d, &d->map);
		print_player_look_vector(d, &d->map, d->rot);
		calc_n_disp_framerate(d);
		print_data2screen(d, &d->map, &d->hud);
	}
	return (0);
}
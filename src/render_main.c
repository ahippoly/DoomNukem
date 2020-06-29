#include "proto_global.h"

void 			print_data2screen(t_data *d, t_map_data *map, t_hud *hud)
{
    SDL_Rect 	tmp;

    tmp = set_sdl_rect(MINI_MAP_POS_X, MINI_MAP_POS_Y, MINI_MAP_SIZE_X, MINI_MAP_SIZE_Y);
    //SDL_RenderClear(d->rend);
    SDL_UpdateTexture(d->screen, NULL, d->p_screen, WIN_SIZE_X * 4);
    print_mini_map(d, map);
    SDL_RenderCopy(d->rend, d->screen, NULL, NULL);
    SDL_RenderCopy(d->rend, d->sprite[d->gun_ind].text, &d->src_gun, &d->dst_gun);
	update_hud_info(d);
	render_hud_info(d);
	render_hud_icons(d);
    SDL_RenderCopy(d->rend, d->mini_map, NULL, &tmp);
    SDL_RenderPresent(d->rend);
}

void			calc_n_disp_framerate(t_data *d, unsigned int *pix)
{
    static int  last_time;
    static int  framerate;
    static int  last_framerate;
    int			time;

    time = SDL_GetTicks();
	//SDL_Delay(50);
    if (time > last_time + 1000)
    {
        last_framerate = framerate;
		//printf("diff time = %i\n", time - last_time);
		// printf("framerate = %i\n", last_framerate);
		// printf("diff_time = %f\n", d->diff_time);
        framerate = 0;
        last_time = time;
    }
    framerate += 1;
    input_text_to_img(ft_itoa(last_framerate), 2, 0xFFFFFFFF, create_img(pix, set_sdl_rect(5, 5, WIN_SIZE_X, WIN_SIZE_Y)));
}

int					main(int ac, char **av)
{
    t_data			d;
    
    init_data(&d, ac, av);
    ft_putstr("Main worked");
    printf("player pos = %f, %f, wall count = %i\n", d.player_pos.x, d.player_pos.y, d.map.wall_count);

    init_sound(&d);
    play_sound(&d, MUS1); //Play Music

	// test.pixels = alloc_image(d.sprite[AFRIT].frame_size.w, d.sprite[AFRIT].frame_size.h);
	// test.w = d.sprite[AFRIT].frame_size.w;
	// test.h = d.sprite[AFRIT].frame_size.h;
	// copy_frame(test.pixels, (SDL_Rect){0,0, test.w, test.h}, d.sprite[AFRIT].pixels, (SDL_Rect){0, 0, d.sprite[AFRIT].total_size.w, d.sprite[AFRIT].total_size.h});
	// t_ssprite new_afr;

	// new_afr = sprite_init_afrit2(d.sprite_img[SPRITE_ID_AFRIT]);
	// test.pixels = new_afr.dst;
	// test.w = new_afr.dst_w;
	// test.h = new_afr.dst_h;
	// load_anim(&new_afr, d.time, ANIM_MOB_DEATH);
	// new_afr.idle_anim = ANIM_MOB_MELEE;
    while (!d.quit)
    {
        d.time_last_frame = d.time;
        d.time = SDL_GetTicks();
		d.diff_time = (float)(d.time - d.time_last_frame) / 1000;
        //ft_bzero(d.p_screen, sizeof(int) * WIN_SIZE_X * WIN_SIZE_Y);
        SDL_PumpEvents();
        handle_poll_event(&d);
        handle_key_event(&d);
		// handle_key_event_sprite(&d, &map);
		//handle_mouse_event_gun(&d, &d.map);
        gravity(&d);
		create_obj_raybox(&d);
		process_mobs_gameplay(&d);
		process_gun(d.actual_weapon, d.time, &d);
		check_props_collect(&d, d.props, &d.hud);

		//draw_all_floor_slice(&d);

        //draw_floor(&d, d.texture[1]);
        //raycast_all_screen(&d, &d.map);
		raycast_thread_init(&d);
		// test = (t_img){d.sprite[10].pixels_dst, (SDL_Rect){0,0,0,0}, d.sprite[AFRIT].frame_size.w, d.sprite[AFRIT].frame_size.h};
		// process_anim(&new_afr, d.time);
		// print_text_screen(d.p_screen, &test, (SDL_Rect){100, 100, 200, 200});
		// print_text_screen(d.p_screen, d.texture[1], (SDL_Rect){200,200, 200, 200});
		//print_prop(&d, &d.props[0]);
		//print_walls(&d);
		sprite_anim_gun(&d);
        update_player_pos_mini_map(&d, &d.map);
        print_player_look_vector(&d, &d.map, d.rot);
        calc_n_disp_framerate(&d, d.p_screen);
        print_data2screen(&d, &d.map, &d.hud);
    }
	exit_env(&d);
}


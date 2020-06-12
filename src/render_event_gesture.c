#include "global_header.h"
#include "render.h"
#include "editor.h"
#include "img_file.h"


void handle_key_event(t_data *d, t_map_data *map)
{
    d->clavier = SDL_GetKeyboardState(NULL);
    if (d->clavier[SDL_SCANCODE_E])
        d->rot += ROT_STEP;
    if (d->clavier[SDL_SCANCODE_Q])
        d->rot -= ROT_STEP;
    if (d->clavier[SDL_SCANCODE_D])
        move_with_collide(d, &d->player_pos, d->rot + M_PI_2, MOVE_STEP * d->speed_modifier);
        //move_attempt(&d->player_pos, MOVE_STEP * d->speed_modifier, d->rot + 1);
    if (d->clavier[SDL_SCANCODE_A])
        move_with_collide(d, &d->player_pos, d->rot - M_PI_2, MOVE_STEP * d->speed_modifier);
    if (d->clavier[SDL_SCANCODE_W])
        move_with_collide(d, &d->player_pos, d->rot, MOVE_STEP * d->speed_modifier);
    if (d->clavier[SDL_SCANCODE_S])
        move_with_collide(d, &d->player_pos, d->rot + M_PI, MOVE_STEP * d->speed_modifier);
    if (d->clavier[SDL_SCANCODE_R])
        d->z_offset += 0.05;
    if (d->clavier[SDL_SCANCODE_F])
        d->z_offset -= 0.05;
    if (d->clavier[SDL_SCANCODE_ESCAPE])
        d->quit = 1;

	//debug
		if (d->clavier[SDL_SCANCODE_C])
			raycast_thread_init(d);
	//printf("player rot = %f\n", fabs(fmod(d->rot, 4)));
	
}

void handle_poll_event(t_data *d, t_map_data *map)
{
    while (SDL_PollEvent(&d->e))
    {
        if (d->e.type == SDL_WINDOWEVENT)
        {
            if (d->e.window.event == SDL_WINDOWEVENT_CLOSE)
                d->quit = 1;
        }
        if (d->e.type == SDL_MOUSEMOTION)
        {
            //printf("mouse x,y = %i,%i, mouse rel = %i,%i\n", d->e.motion.x, d->e.motion.y, d->e.motion.xrel, d->e.motion.yrel);
            d->rot += MOUSE_SENS * d->e.motion.xrel * M_PI_2;
            d->screen_height = HALF_WIN_SIZE_Y + (HALF_WIN_SIZE_Y - d->e.motion.y) * Y_VIEW_RANGE;
        }
        if (d->e.type == SDL_KEYDOWN)
        {
            if (d->e.key.keysym.scancode == SDL_SCANCODE_LSHIFT)
            {
                printf("running\n");
                d->speed_modifier += 1;
            }
            if (d->e.key.keysym.scancode == SDL_SCANCODE_LCTRL)
            {
                printf("crouch\n");
                d->z_offset -= PLAYER_HEIGHT / 2;
            }
            if (d->clavier[SDL_SCANCODE_SPACE])
                d->z_force = 0.07;
			//debug
			if (d->clavier[SDL_SCANCODE_G])
               	d->map.wall_list[0].p1_z_start += 0.05;
			if (d->clavier[SDL_SCANCODE_H])
               	d->map.wall_list[0].p1_z_size += 0.05;
			if (d->clavier[SDL_SCANCODE_J])
               	d->map.wall_list[0].p2_z_start += 0.05;
			if (d->clavier[SDL_SCANCODE_K])
               	d->map.wall_list[0].p2_z_size += 0.05;
        }
        if (d->e.type == SDL_KEYUP)
        {
            if (d->e.key.keysym.scancode == SDL_SCANCODE_LSHIFT)
            {
                printf("no longer running\n");
                d->speed_modifier -= 1;
            }
            if (d->e.key.keysym.scancode == SDL_SCANCODE_LCTRL)
            {
                printf("no longer crouch\n");
                d->z_offset += PLAYER_HEIGHT / 2;
            }
            if (d->e.key.keysym.scancode == SDL_SCANCODE_Z)
            {
                draw_vertical_line(d, 500, check_intersect_with_all_wall(d, map, d->rot, d->rot));
                printf("scale_z to wall test = %f\n", check_intersect_with_all_wall(d, map, d->rot, d->rot).scale_z);
                printf("d->rot = %f\n", d->rot);
            }
                
            if (d->e.key.keysym.scancode == SDL_SCANCODE_X)
            {
                printf("dist = %f\n", check_perp_wall(map->wall_list[0], d->player_pos).dist);
            }
        }
    }
}
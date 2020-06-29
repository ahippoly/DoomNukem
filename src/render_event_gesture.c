#include "proto_global.h"
#include "proto_global.h"
#include "proto_global.h"
#include "proto_global.h"
#include "proto_global.h"
#include "proto_global.h"



void event_gun_mouse(t_data *d)
{
	if  (d->e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (d->e.button.button == SDL_BUTTON_LEFT)
		{
			shoot_attempt(d, d->actual_weapon);
		}
		else if (d->e.button.button == SDL_BUTTON_RIGHT)
		{
			aim_gun(d);
		}
	}
	else if (d->e.type == SDL_MOUSEBUTTONUP)
	{
		if (d->e.button.button == SDL_BUTTON_LEFT)
		{
			d->shoot_repeat = 0;
			d->sprite[d->gun_ind].anim_end = -1;
			if (d->gun_ind > 2 && d->gun_ind < 6)
			play_sound(d, d->gun_ind + 10);
		}
		else if (d->e.button.button == SDL_BUTTON_RIGHT)
		{
			d->sprite[d->gun_ind].on = -1;
		}
	}
}

void event_change_weapon(t_data *d)
{
	if (d->clavier[SDL_SCANCODE_R])
    {
		reload_weapon(d, d->actual_weapon);
    }
	if (d->clavier[SDL_SCANCODE_1])
    {
            d->gun_ind = 0;
            d->sprite[d->gun_ind].on = -1;
            d->sprite[d->gun_ind].aim_on = 0;
			d->actual_weapon = d->hud.perso_weapon[0];
    }
    if (d->clavier[SDL_SCANCODE_2])
    {
            d->gun_ind = 1;
            d->sprite[d->gun_ind].on = -1;
            d->sprite[d->gun_ind].aim_on = 0;
			d->actual_weapon = d->hud.perso_weapon[1];
			// d->hud.current_weap_id = 1;
    }
    if (d->clavier[SDL_SCANCODE_3])
    {
            d->gun_ind = 2;
            d->sprite[d->gun_ind].on = -1;
            d->sprite[d->gun_ind].aim_on = 0;
			d->actual_weapon = d->hud.perso_weapon[2];
			// d->hud.current_weap_id = 2;
    }
    if (d->clavier[SDL_SCANCODE_4])
    {
            d->gun_ind = 3;
            d->sprite[d->gun_ind].on = -1;
            d->sprite[d->gun_ind].aim_on = 0;
			d->actual_weapon = d->hud.perso_weapon[3];
			// d->hud.current_weap_id = 3;
    }
    if (d->clavier[SDL_SCANCODE_5])
    {
            d->gun_ind = 4;
            d->sprite[d->gun_ind].on = -1;
            d->sprite[d->gun_ind].aim_on = 0;
			d->actual_weapon = d->hud.perso_weapon[4];
			// d->hud.current_weap_id = 4;
    }
    if (d->clavier[SDL_SCANCODE_6])
    {
            d->gun_ind = 5;
            d->sprite[d->gun_ind].on = -1;
            d->sprite[d->gun_ind].aim_on = 0;
			d->actual_weapon = d->hud.perso_weapon[5];
			// d->hud.current_weap_id = 5;
    }
    if (d->clavier[SDL_SCANCODE_8]) //Test mob animation
    {
            d->sprite[d->mob_ind].time = SDL_GetTicks();
            d->sprite[d->mob_ind].on = 0;
            d->sprite[d->mob_ind].index = IDLE;
    }
    if (d->clavier[SDL_SCANCODE_9]) //Test mob animation
    {
            d->sprite[d->mob_ind].time = SDL_GetTicks();
            d->sprite[d->mob_ind].on = 0;
            d->sprite[d->mob_ind].index = DEATH;
    }
    if (d->clavier[SDL_SCANCODE_0]) //Test mob animation
    {
            d->sprite[d->mob_ind].time = SDL_GetTicks();
            d->sprite[d->mob_ind].on = 0;
            d->sprite[d->mob_ind].index = ATTACK;
    }
}

void handle_key_event(t_data *d)
{
    d->clavier = SDL_GetKeyboardState(NULL);
    if (d->clavier[SDL_SCANCODE_E])
		d->rot += ROT_STEP;
    if (d->clavier[SDL_SCANCODE_Q])
		d->rot -= ROT_STEP;
	d->rot_calc = calc_sin_cos_rot(d->rot);
    if (d->clavier[SDL_SCANCODE_D])
        move_with_collide_player(d, &d->player_pos, (t_rot){d->rot + M_PI_2, cos(d->rot + M_PI_2), sin(d->rot + M_PI_2)}, MOVE_STEP * d->speed_modifier);
        //move_attempt(&d->player_pos, MOVE_STEP * d->speed_modifier, d->rot_calc + 1);
    if (d->clavier[SDL_SCANCODE_A])
        move_with_collide_player(d, &d->player_pos, (t_rot){d->rot - M_PI_2, cos(d->rot - M_PI_2), sin(d->rot - M_PI_2)}, MOVE_STEP * d->speed_modifier);
    if (d->clavier[SDL_SCANCODE_W])
        move_with_collide_player(d, &d->player_pos, d->rot_calc, MOVE_STEP * d->speed_modifier);
    if (d->clavier[SDL_SCANCODE_S])
        move_with_collide_player(d, &d->player_pos, (t_rot){d->rot + M_PI, cos(d->rot + M_PI), sin(d->rot + M_PI)}, MOVE_STEP * d->speed_modifier);
    if (d->clavier[SDL_SCANCODE_I])
        d->z_offset += 0.05;
    if (d->clavier[SDL_SCANCODE_O])
        d->z_offset -= 0.05;
	
	event_change_weapon(d);
    if (d->clavier[SDL_SCANCODE_ESCAPE])
        d->quit = 1;
	//debug
		if (d->clavier[SDL_SCANCODE_C])
			raycast_thread_init(d);
	//printf("player rot = %f\n", fabs(fmod(d->rot, 4)));
}

void inc_fov(t_data *d, float inc)
{
	d->fov_rad += inc * M_PI_2;
	d->fov += inc;
	printf("fov = %f\n", d->fov);
}

void *test(void *param)
{
	printf("Hey, im tested\n");
	return (NULL);
}

void handle_poll_event(t_data *d)
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
			move_z_grabbed_wall(d, - (float)d->e.motion.yrel * MOVE_WALL_Z_SPEED / WIN_SIZE_Y);
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
                d->speed_modifier -= 0.5;
                d->z_offset -= PLAYER_HEIGHT / 2;
            }
            if (d->e.key.keysym.scancode == SDL_SCANCODE_SPACE)
                d->z_force = JUMP_FORCE;
			//debug
			if (d->e.key.keysym.scancode == SDL_SCANCODE_G)
               	rot_grabbed_wall(d, 0.05 * M_PI_2, 0);
			if (d->e.key.keysym.scancode == SDL_SCANCODE_H)
               	rot_grabbed_wall(d, -0.05 * M_PI_2, 0);
			if (d->e.key.keysym.scancode == SDL_SCANCODE_J)
               	inc_fov(d, 0.05);
			if (d->e.key.keysym.scancode == SDL_SCANCODE_K)
               	inc_fov(d, -0.05);
			if (d->e.key.keysym.scancode == SDL_SCANCODE_V)
				print_floor(d);

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
				d->speed_modifier += 0.5;
                d->z_offset += PLAYER_HEIGHT / 2;
            }
            if (d->e.key.keysym.scancode == SDL_SCANCODE_Z)
            {
				// set_sprite_callback(&d->mobs[0].sprite, test, NULL);
				load_anim(&d->mobs[0].sprite, d->time, ANIM_MOB_MELEE);
				//d->mobs[0].sprite.idle_anim = ANIM_MOB_DEATH;
				// printf("checking room\n");
				// if (check_obj_room(d, d->player_pos) > -1)
				// 	printf("Is in room\n");
				//print_wall(d, d->map.wall_list[0]);

				d->hud.hp -= 10;
				// move_with_collide(d, &sorted[0].obj_ref->pos, get_angle(d->player_pos, sorted[0].obj_ref->pos), 10);
				// t_ray  ray = check_perp_obj(&d->obj_list[0], d->player_pos);
				// t_ray ray = check_inter_with_obj(&d->obj_list[2], d->rot_calc, d->player_pos, d->rot_calc);
				// print_ray(ray);

				// printf("obj deleted, nb_obj = %i\n", d->nb_obj);
				// del_obj(d->obj_list, &d->nb_obj, &d->obj_list[1]);



				// init_floors(d);
				// raycast_screen(d, (t_range){400, 401}, d->rot, 0);
                // draw_vertical_line(d, 500, check_intersect_with_all_wall_rend(d, d->player_pos, d->rot, d->rot));
                // printf("scale_z to wall test = %f\n", check_intersect_with_all_wall_rend(d, d->player_pos, d->rot, d->rot).scale_z);
                // printf("d->rot = %f\n", d->rot);
            }
                
            if (d->e.key.keysym.scancode == SDL_SCANCODE_X)
            {
				if (d->grabbed_wall == NULL)
                	if (grab_wall(d, d->player_pos, d->rot_calc))
						printf("grabbed wall\n");
					else
						printf("attempt grab fail\n");
				else
				{
					d->grabbed_wall = NULL;
					printf("no longer grab wall\n");
				}
            }
			
        }
		event_gun_mouse(d);
    }
}
#include "global_header.h"
#include "render.h"
#include "editor.h"
#include "img_file.h"

void move_attempt(t_point *pos, double speed, double look_rot)
{
    double cos_rot;
    double sin_rot;

    cos_rot = cos(look_rot);
    sin_rot = sin(look_rot);
    pos->y += speed * sin_rot;
    pos->x += speed * cos_rot;
}

double mod_pi(double rot)
{
	if (rot < 0)
		rot = PI_X_2 + rot;
	return(fmod(rot, PI_X_2));
}

int is_angle_in_range(double rot, double min, double max)
{
	printf("rot = %f, min = %f, max = %f\n", rot, min, max);
	if (min > max && (rot > min || rot < max))
		return (1);
	else if (rot > min && rot < max)
		return (1);
	return (0);
}

void move_with_collide(t_data *d, t_point *pos, double rot, double speed)
{
    t_calced_walls res;
	double min_rot;
	double max_rot;
	double tmp;
	double cos_rot;
	double sin_rot;

    res = check_perp_all_wall(d, &d->map, d->player_pos);

    t_point move_dir;

    move_dir.x = cos(rot - M_PI_4 * 0 + M_PI_4 * 0) * speed;
    move_dir.y = sin(rot + M_PI_4 * 0 + M_PI_4 * 0) * speed;
	
    printf("rot = %f\n", rot / M_PI_2);
	if (res.dist < WALL_SIZE && check_inter_with_wall(d->map.wall_list[res.wall_id], rot, *pos, rot).dist != 9999)
	{
		printf("recalc needed, wall rot = %f\n", res.wall_rot / M_PI_2);
		// cos_rot = cos(res.wall_rot);
		// sin_rot = sin(res.wall_rot);
        // printf("move_dir: %f,%f, sin:%f, cos:%f\n", move_dir.x,move_dir.y, sin_rot, cos_rot);
		// // pos->x += move_dir.x * cos_rot - move_dir.y * cos_rot;
		// // pos->y += move_dir.x * sin_rot - move_dir.y * sin_rot;
        // pos->x += (move_dir.x - move_dir.y) * cos_rot + move_dir.x * cos_rot;
		// pos->y += (move_dir.x - move_dir.y) * sin_rot + move_dir.y * sin_rot;
	}
	else
	{
		move_attempt(pos, speed, rot);
	}

	
}

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
    if (d->clavier[SDL_SCANCODE_SPACE])
        d->player_height += HEIGHT_STEP;
    if (d->clavier[SDL_SCANCODE_LCTRL])
        d->player_height -= HEIGHT_STEP;
    if (d->clavier[SDL_SCANCODE_R])
        d->screen_height += SCREEN_HEIGHT_STEP;
    if (d->clavier[SDL_SCANCODE_F])
        d->screen_height -= SCREEN_HEIGHT_STEP;
    if (d->clavier[SDL_SCANCODE_ESCAPE])
        d->quit = 1;
	//printf("player rot = %f\n", fabs(fmod(d->rot, 4)));
	
}

void handle_poll_event(t_data *d, t_map_data *map)
{
    while (SDL_PollEvent(&d->e))
    {
        if (d->e.type == SDL_KEYDOWN)
        {
            if (d->e.key.keysym.scancode == SDL_SCANCODE_LSHIFT)
            {
                printf("running\n");
                d->speed_modifier += 1;
            }
        }
        if (d->e.type == SDL_KEYUP)
        {
            if (d->e.key.keysym.scancode == SDL_SCANCODE_LSHIFT)
            {
                printf("no longer running\n");
                d->speed_modifier -= 1;
            }
            if (d->e.key.keysym.scancode == SDL_SCANCODE_Z)
            {
                draw_vertical_line(d, 500, check_intersect_with_all_wall(d, map, d->rot, d->rot));
                printf("dist to wall test = %f\n", check_intersect_with_all_wall(d, map, d->rot, d->rot).dist);
                printf("d->rot = %f\n", d->rot);
            }
                
            if (d->e.key.keysym.scancode == SDL_SCANCODE_X)
            {
                printf("dist = %f\n", check_perp_wall(map->wall_list[0], d->player_pos).dist);
            }
        }
    }
}
#include "global_header.h"
#include "render.h"
#include "editor.h"
#include "img_file.h"

void move_attempt(t_point *pos, double inc_x, double inc_y, double look_rot)
{
    double cos_rot;
    double sin_rot;

    cos_rot = cos(look_rot * M_PI_2);
    sin_rot = sin(look_rot * M_PI_2);
    pos->y += - inc_y * sin_rot - inc_x * cos_rot;
    pos->x += - inc_y * cos_rot + inc_x * sin_rot;
}

void handle_key_event(t_data *d, t_map_data *map)
{
    d->clavier = SDL_GetKeyboardState(NULL);
    if (d->clavier[SDL_SCANCODE_E])
        d->rot += ROT_STEP;
    if (d->clavier[SDL_SCANCODE_Q])
        d->rot -= ROT_STEP;
    if (d->clavier[SDL_SCANCODE_D])
        move_attempt(&d->player_pos, - MOVE_STEP, 0, d->rot);
    if (d->clavier[SDL_SCANCODE_A])
        move_attempt(&d->player_pos, MOVE_STEP, 0, d->rot);
    if (d->clavier[SDL_SCANCODE_W])
        move_attempt(&d->player_pos, 0, - MOVE_STEP, d->rot);
    if (d->clavier[SDL_SCANCODE_S])
        move_attempt(&d->player_pos, 0, MOVE_STEP, d->rot);
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
}

void handle_poll_event(t_data *d, t_map_data *map)
{
    while (SDL_PollEvent(&d->e))
    {
        if (d->e.type == SDL_KEYDOWN)
        {
            if (d->e.key.keysym.scancode == SDL_SCANCODE_Z)
            {
                draw_vertical_line(d, 500, check_intersect_with_all_wall(d, map, d->rot, d->rot), d->texture[0]);
                printf("dist to wall test = %f\n", check_intersect_with_all_wall(d, map, d->rot, d->rot).dist);
                printf("d->rot = %f\n", d->rot);
            }
                
            if (d->e.key.keysym.scancode == SDL_SCANCODE_X)
            {
                printf("d->rot = %f\n", d->rot);
                //sort_walls_by_dist(d, map, d->rot);
                draw_floor(d, d->texture[1]);
            }
        }
    }
}
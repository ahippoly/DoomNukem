#include "global_header.h"
#include "render.h"
#include "editor.h"
#include "img_file.h"
#include "sprite.h"

void free_render_env(t_data *d)
{
    free(d->sorted_walls);
}

SDL_Rect    get_sprite_pos(SDL_Rect srcdim, t_data *d, SDL_Point pos)
{
    srcdim.x = d->sprite[d->sprite_ind].frame_size.w * pos.x;
    srcdim.y = d->sprite[d->sprite_ind].frame_size.h * pos.y;
    srcdim.w = d->sprite[d->sprite_ind].frame_size.w - d->sprite[d->sprite_ind].anim[d->sprite[d->sprite_ind].index].offset.x;
    srcdim.h = d->sprite[d->sprite_ind].frame_size.h - d->sprite[d->sprite_ind].anim[d->sprite[d->sprite_ind].index].offset.y;
    return (srcdim);
}

void    idle_anim(t_data *d)
{
    SDL_Rect srcdim;
    SDL_Point pos;

    if (d->sprite[d->sprite_ind].aim_on == 0)  //Arme au repos
    {
    pos.x = d->sprite[d->sprite_ind].anim[IDLE].pos->x;
    pos.y = d->sprite[d->sprite_ind].anim[IDLE].pos->y;
    }
    else if (d->sprite[d->sprite_ind].aim_on == 1) //Arme avec visée
    {
            pos.x = d->sprite[d->sprite_ind].anim[AIM].pos->x;
            pos.y = d->sprite[d->sprite_ind].anim[AIM].pos->y;
            d->sprite[d->sprite_ind].index = AIM;
    }
    srcdim = get_sprite_pos(srcdim, d, pos);
    SDL_RenderClear(d->rend);
    SDL_RenderCopy(d->rend, d->sprite[d->sprite_ind].text, &srcdim, NULL);
    SDL_RenderPresent(d->rend);
}

void    sprite_anim(t_data *d)
{
    SDL_Rect srcdim;
    SDL_Point pos;
    Uint32 currTime;
    int diff;

    diff = 0;
    if (d->sprite[d->sprite_ind].on >= 0)
    {
        currTime = SDL_GetTicks();
        diff = (currTime - d->sprite[d->sprite_ind].time) / 100;
    }
    pos.x = (d->sprite[d->sprite_ind].anim[d->sprite[d->sprite_ind].index].pos->x + diff) % d->sprite[d->sprite_ind].nb_frame.x;
    pos.y = d->sprite[d->sprite_ind].anim[d->sprite[d->sprite_ind].index].pos->y + (d->sprite[d->sprite_ind].anim[d->sprite[d->sprite_ind].index].pos->x + diff) / d->sprite[d->sprite_ind].nb_frame.x;
    if (diff < d->sprite[d->sprite_ind].anim[d->sprite[d->sprite_ind].index].nb_frame && d->sprite[d->sprite_ind].on == 0)
    {
        srcdim = get_sprite_pos(srcdim, d, pos);
        SDL_RenderClear(d->rend);
        SDL_RenderCopy(d->rend, d->sprite[d->sprite_ind].text, &srcdim, NULL);
        SDL_RenderPresent(d->rend);
    }
    else if ((d->sprite[d->sprite_ind].index == FIRE || d->sprite[d->sprite_ind].index == AIMFIRE) && (d->sprite[d->sprite_ind].on == 0) && d->sprite[d->sprite_ind].anim_end == 0)
        d->sprite[d->sprite_ind].time = SDL_GetTicks();
    else
    {
        d->sprite[d->sprite_ind].index = IDLE;
        d->sprite[d->sprite_ind].on = -1;
        idle_anim(d);
    }
}

SDL_Texture     *load_sprite_bmp(char *str, t_data *d)
{
    SDL_Surface *surface;
    SDL_Texture *texture;

    surface = NULL;
    texture = NULL;
    if (!(surface = SDL_LoadBMP(str)))
      printf("Erreur de chargement de l'image : %s",SDL_GetError());
    if (!(texture = SDL_CreateTextureFromSurface(d->rend, surface)))
      printf("Erreur de conversion de la surface : %s",SDL_GetError());
    SDL_FreeSurface(surface);
    return (texture);
}

void handle_key_event_sprite(t_data *d, t_map_data *map)
{
    d->clavier = SDL_GetKeyboardState(NULL);
    if (d->clavier[SDL_SCANCODE_R])
    {
            d->sprite[d->sprite_ind].time = SDL_GetTicks();
            d->sprite[d->sprite_ind].index = RELOAD;
            d->sprite[d->sprite_ind].on = 0;
            d->sprite[d->sprite_ind].aim_on = 0;
            d->sprite[d->sprite_ind].anim_end = 0;
    }
      if (d->clavier[SDL_SCANCODE_1])
    {
            d->sprite_ind = 0;
            d->sprite[d->sprite_ind].on = -1;
            d->sprite[d->sprite_ind].aim_on = 0;
    }
          if (d->clavier[SDL_SCANCODE_2])
    {
            d->sprite_ind = 1;
            d->sprite[d->sprite_ind].on = -1;
            d->sprite[d->sprite_ind].aim_on = 0;
    }
              if (d->clavier[SDL_SCANCODE_3])
    {
            d->sprite_ind = 2;
            d->sprite[d->sprite_ind].on = -1;
            d->sprite[d->sprite_ind].aim_on = 0;
    }
                if (d->clavier[SDL_SCANCODE_4])
    {
            d->sprite_ind = 3;
            d->sprite[d->sprite_ind].on = -1;
            d->sprite[d->sprite_ind].aim_on = 0;
    }
                   if (d->clavier[SDL_SCANCODE_5])
    {
            d->sprite_ind = 4;
            d->sprite[d->sprite_ind].on = -1;
            d->sprite[d->sprite_ind].aim_on = 0;
    }
                      if (d->clavier[SDL_SCANCODE_6])
    {
            d->sprite_ind = 5;
            d->sprite[d->sprite_ind].on = -1;
            d->sprite[d->sprite_ind].aim_on = 0;
    }
    if (d->clavier[SDL_SCANCODE_ESCAPE])
        d->quit = 1;
}

void handle_mouse_event_gun(t_data *d, t_map_data *map)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        if  (event.type == SDL_MOUSEBUTTONDOWN)
            {
            if (event.button.button == SDL_BUTTON_LEFT)
                {
                d->sprite[d->sprite_ind].time = SDL_GetTicks();
                if (d->sprite[d->sprite_ind].aim_on == 0)
                    d->sprite[d->sprite_ind].index = FIRE;
                else if (d->sprite_ind == 3 || d->sprite_ind == 4)
                    d->sprite[d->sprite_ind].index = AIMFIRE;
                d->sprite[d->sprite_ind].on = 0;
                d->sprite[d->sprite_ind].anim_end = 0;
                }
            else if (event.button.button == SDL_BUTTON_RIGHT)
                {
                d->sprite[d->sprite_ind].time = SDL_GetTicks();
                d->sprite[d->sprite_ind].index = AIM;
                d->sprite[d->sprite_ind].on = 0;
                if (d->sprite[d->sprite_ind].aim_on == 0)
                    d->sprite[d->sprite_ind].aim_on = 1;
                else
                    d->sprite[d->sprite_ind].aim_on = 0;
                }
            }
            else if (event.type == SDL_MOUSEBUTTONUP)
           {
            if (event.button.button == SDL_BUTTON_LEFT)
                {
                d->sprite[d->sprite_ind].anim_end = -1;
                }
            else if (event.button.button == SDL_BUTTON_RIGHT)
                {
                d->sprite[d->sprite_ind].on = -1;
                }
            }
    }  
}

int main(void)
{
    t_map_data  map;
    t_data      d;

    init_sdl_ressources_rend(&d);
    map = read_map("maps/editor_map_0");
    init_data(&d, &map);
    load_sprite_gun(&d);
    load_sprite_mob(&d);
    ft_putstr("Main worked");

    d.sprite_ind = 0;   //Le sprite a afficher
    d.sprite[d.sprite_ind].index = 0;   //L'animation du sprite a afficher
    while (!d.quit)
    {
        ft_bzero(d.p_screen, sizeof(int) * WIN_SIZE_X * WIN_SIZE_Y);
        SDL_PumpEvents();
        handle_key_event_sprite(&d, &map);
        handle_mouse_event_gun(&d, &map);
        handle_poll_event(&d, &map);
        sprite_anim(&d);
    }
    free_render_env(&d);
}
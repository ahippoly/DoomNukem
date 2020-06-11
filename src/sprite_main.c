#include "global_header.h"
#include "render.h"
#include "editor.h"
#include "img_file.h"
#include "sprite.h"

void free_render_env(t_data *d)
{
    free(d->sorted_walls);
}



SDL_Rect    get_sprite_pos(SDL_Rect srcdim, t_sprite *sprite, SDL_Point pos)
{
    srcdim.x = sprite->frame_size.w * pos.x;
    srcdim.y = sprite->frame_size.h * pos.y;
    srcdim.w = sprite->frame_size.w;
    srcdim.h = sprite->frame_size.h;
    return (srcdim);
}

// void    sprite_anim(t_data *d)
// {
//     SDL_Rect srcdim;
//     SDL_Point pos;
//     int i;

//     i = 0;
//     pos.x = d->sprite[d->sprite_ind].anim[d->sprite[d->sprite_ind].index].pos->x;
//     pos.y = d->sprite[d->sprite_ind].anim[d->sprite[d->sprite_ind].index].pos->y;
//     while (pos.y < d->sprite[d->sprite_ind].nb_frame.y && i < d->sprite[d->sprite_ind].anim[d->sprite[d->sprite_ind].index].nb_frame)
//     {
//         while (pos.x < d->sprite[d->sprite_ind].nb_frame.x && i < d->sprite[d->sprite_ind].anim[d->sprite[d->sprite_ind].index].nb_frame)
//         {
//               // printf("x = %d\n", pos.x);
//             srcdim = get_sprite_pos(srcdim, &d->sprite[d->sprite_ind], pos);
//             SDL_RenderClear(d->rend);
//             SDL_RenderCopy(d->rend, d->sprite[d->sprite_ind].text, &srcdim, NULL);
//             SDL_RenderPresent(d->rend);
//            // wait_time(0.1);
//             pos.x++;
//             i++;
//         }
//         pos.x = 0;
//         pos.y++;
//     }
// }

void    idle_anim(t_data *d)
{
    SDL_Rect srcdim;
    SDL_Point pos;

    pos.x = d->sprite[d->sprite_ind].anim[1].pos->x;
    pos.y = d->sprite[d->sprite_ind].anim[1].pos->y;

    srcdim = get_sprite_pos(srcdim, &d->sprite[d->sprite_ind], pos);
    SDL_RenderClear(d->rend);
    SDL_RenderCopy(d->rend, d->sprite[d->sprite_ind].text, &srcdim, NULL);
    SDL_RenderPresent(d->rend);
}

void    sprite_anim(t_data *d, Uint32 time)
{
    SDL_Rect srcdim;
    SDL_Point pos;

    pos.x = (d->sprite[d->sprite_ind].anim[d->sprite[d->sprite_ind].index].pos->x + time) % d->sprite[d->sprite_ind].nb_frame.x;
    pos.y = d->sprite[d->sprite_ind].anim[d->sprite[d->sprite_ind].index].pos->y + (d->sprite[d->sprite_ind].anim[d->sprite[d->sprite_ind].index].pos->x + time) / d->sprite[d->sprite_ind].nb_frame.x;
    printf("time = %d\n", time);
    if (time < d->sprite[d->sprite_ind].anim[d->sprite[d->sprite_ind].index].nb_frame)
        {
        srcdim = get_sprite_pos(srcdim, &d->sprite[d->sprite_ind], pos);
        SDL_RenderClear(d->rend);
        SDL_RenderCopy(d->rend, d->sprite[d->sprite_ind].text, &srcdim, NULL);
        SDL_RenderPresent(d->rend);
        }
    else
         idle_anim(d);
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

void    load_sprite_gun(t_data *d)
{
    SDL_Texture *texture;
    t_sprite commando;

    texture = NULL;
    texture = load_sprite_bmp("Sprites/Guns/AssaultRifle.bmp", d);
    d->sprite[0] = init_sprite_AR(texture);
    texture = NULL;
    texture = load_sprite_bmp("Sprites/Guns/DeathDealer.bmp", d);
    d->sprite[1] = init_sprite_DD(texture);
    texture = NULL;
    texture = load_sprite_bmp("Sprites/Guns/lmg.bmp", d);
    d->sprite[2] = init_sprite_LMG(texture);
    texture = NULL;
    texture = load_sprite_bmp("Sprites/Guns/Revolver.bmp", d);
    d->sprite[3] = init_sprite_Revolver(texture);
    texture = NULL;
    texture = load_sprite_bmp("Sprites/Guns/SuperShotgun.bmp", d);
    d->sprite[4] = init_sprite_SSG(texture);
    texture = NULL;
    texture = load_sprite_bmp("Sprites/Guns/Melee.bmp", d);
    d->sprite[5] = init_sprite_Melee(texture);
}

void    load_sprite_mob(t_data *d)
{
    SDL_Texture *texture;
    t_sprite commando;

    texture = NULL;
    texture = load_sprite_bmp("Sprites/Mobs/ZombieScientist.bmp", d);
    d->sprite[10] = init_sprite_Zombie(texture);
    texture = NULL;
    texture = load_sprite_bmp("Sprites/Mobs/ZombieScientist.bmp", d);
    d->sprite[10] = init_sprite_Zombie(texture);
}

int main(void)
{
    t_map_data  map;
    t_data      d;
    Uint32      currTime;
    Uint32      lastTime;

    init_sdl_ressources_rend(&d);
    map = read_map("maps/editor_map_0");
    init_data(&d, &map);
    load_sprite_gun(&d);
    load_sprite_mob(&d);
    ft_putstr("Main worked");

    d.sprite_ind = 4;   //Le sprite a afficher
    d.sprite[d.sprite_ind].index = 4;   //L'animation du sprite a afficher
    lastTime = SDL_GetTicks();
    while (!d.quit)
    {
        ft_bzero(d.p_screen, sizeof(int) * WIN_SIZE_X * WIN_SIZE_Y);
        SDL_PumpEvents();
        handle_key_event(&d, &map);
        handle_poll_event(&d, &map);
        currTime = SDL_GetTicks();
        sprite_anim(&d, (currTime - lastTime) / 100);
    }
    printf("sprite %d\n", d.sprite[0].anim[0].nb_frame);
    free_render_env(&d);
}
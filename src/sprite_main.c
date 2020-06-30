#include "proto_global.h"

// SDL_Texture     *load_sprite_bmp(char *str, t_data *d)
// {
//     SDL_Surface *surface;
//     SDL_Texture *texture;

//     surface = NULL;
//     texture = NULL;
//     if (!(surface = SDL_LoadBMP(str)))
//       printf("Erreur de chargement de l'image : %s\n",SDL_GetError());
//     if (!(texture = SDL_CreateTextureFromSurface(d->rend, surface)))
//       printf("Erreur de conversion de la surface : %s\n",SDL_GetError());
//     SDL_FreeSurface(surface);
//     return (texture);
// }


// void handle_mouse_event_gun(t_data *d, t_map_data *map)
// {
//     SDL_Event event;

//     while (SDL_PollEvent(&event))
//     {
//         if  (event.type == SDL_MOUSEBUTTONDOWN)
//             {
//             if (event.button.button == SDL_BUTTON_LEFT)
//                 {
//                 d->sprite[d->gun_ind].time = SDL_GetTicks();
//                 if (d->sprite[d->gun_ind].aim_on == 0)
//                     d->sprite[d->gun_ind].index = FIRE;
//                 else if (d->gun_ind == 3 || d->gun_ind == 4)
//                     d->sprite[d->gun_ind].index = AIMFIRE;
//                 d->sprite[d->gun_ind].on = 0;
//                 d->sprite[d->gun_ind].anim_end = 0;
//                 play_sound(d, d->gun_ind);
//                 }
//             else if (event.button.button == SDL_BUTTON_RIGHT)
//                 {
//                 if (d->gun_ind == 3 || d->gun_ind == 4)
//                 {
//                 d->sprite[d->gun_ind].time = SDL_GetTicks();
//                 d->sprite[d->gun_ind].index = AIM;
//                 d->sprite[d->gun_ind].on = 0;
//                 if (d->sprite[d->gun_ind].aim_on == 0)
//                     d->sprite[d->gun_ind].aim_on = 1;
//                 else
//                     d->sprite[d->gun_ind].aim_on = 0;
//                 }
//                 }
//             }
//             else if (event.type == SDL_MOUSEBUTTONUP)
//            {
//             if (event.button.button == SDL_BUTTON_LEFT)
//                 {
//                 d->sprite[d->gun_ind].anim_end = -1;
//                 if (d->gun_ind > 2 && d->gun_ind < 6)
//                 play_sound(d, d->gun_ind + 10);
//                 }
//             else if (event.button.button == SDL_BUTTON_RIGHT)
//                 {
//                 d->sprite[d->gun_ind].on = -1;
//                 }
//             }
//     }  
// }



// int main(int ac, char **av)
// {
//     t_map_data  map;
//     t_data      d;

//     map = read_map("maps/editor_map_0");
//     init_data(&d, ac, av);
//     init_sprite(&d);
//     init_sound(&d);
//     play_sound(&d, MUS1); //Play Music
//     while (!d.quit)
//     {
//         SDL_RenderClear(d.rend);
//         //ft_bzero(d.p_screen, sizeof(int) * WIN_SIZE_X * WIN_SIZE_Y);
//         //calc_n_disp_framerate(&d);
//         SDL_PumpEvents();
//         handle_key_event_sprite(&d, &map);
//         handle_mouse_event_gun(&d, &map);
//         // handle_poll_event(&d, &map);
//         mob_anim(&d);
//         sprite_anim_gun(&d);
//         SDL_RenderPresent(d.rend);
//     }
// 	SDL_CloseAudio();
// }
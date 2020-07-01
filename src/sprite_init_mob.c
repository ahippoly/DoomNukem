// #include "proto_global.h"



// void print_sprite(t_sprite *sprite)
// {
// 	printf("size : %i,%i, on : %i, totalsize : %i,%i, frame_size : %i,%i\n", sprite->size.x, sprite->size.y, sprite->on, sprite->total_size.w, sprite->total_size.h, sprite->frame_size.w, sprite->frame_size.h);
// }

// static void      init_anim_pyro(t_sprite *Pyro)
// {
//     Pyro->anim[IDLE].pos->x = 7;
//     Pyro->anim[IDLE].pos->y = 1;
//     Pyro->anim[IDLE].nb_frame = 4;
//     Pyro->anim[IDLE].offset.x = 0;
//     Pyro->anim[IDLE].offset.y = 0;
//     Pyro->anim[IDLE].speed = 350;
//     Pyro->anim[ATTACK].pos->x = 0;
//     Pyro->anim[ATTACK].pos->y = 0;
//     Pyro->anim[ATTACK].nb_frame = 8;
//     Pyro->anim[ATTACK].offset.x = 0;
//     Pyro->anim[ATTACK].offset.y = 0;
//     Pyro->anim[ATTACK].speed = 150;
//     Pyro->anim[DEATH].pos->x = 8;
//     Pyro->anim[DEATH].pos->y = 0; 
//     Pyro->anim[DEATH].nb_frame = 9;
//     Pyro->anim[DEATH].offset.x = 0;
//     Pyro->anim[DEATH].offset.y = 0;
//     Pyro->anim[DEATH].speed = 150;
// }

// t_sprite    sprite_init_pyro(void)
// {
//     t_sprite Pyro;

//     Pyro.on = 0;
//     Pyro.index = IDLE;
//     Pyro.total_size.w = 1160;
//     Pyro.total_size.h = 360;
//     Pyro.nb_frame.x = 10;    
//     Pyro.nb_frame.y = 4;  
//     Pyro.frame_size.w = Pyro.total_size.w / Pyro.nb_frame.x;
//     Pyro.frame_size.h = Pyro.total_size.h / Pyro.nb_frame.y;
//     Pyro.time = 0;

//     Pyro.displayed_part.x = 0;
//     Pyro.displayed_part.y = 0;
    
//     //Pyro.text = text;
//     init_anim_pyro(&Pyro);
//     return (Pyro);
// }

// static void      init_anim_afrit(t_sprite *Afrit)
// {
//     Afrit->anim[IDLE].pos->x = 2;
//     Afrit->anim[IDLE].pos->y = 1;
//     Afrit->anim[IDLE].nb_frame = 4;
//     Afrit->anim[IDLE].offset.x = 0;
//     Afrit->anim[IDLE].offset.y = 0;
//     Afrit->anim[IDLE].speed = 350;
//     Afrit->anim[ATTACK].pos->x = 0;
//     Afrit->anim[ATTACK].pos->y = 0;
//     Afrit->anim[ATTACK].nb_frame = 8;
//     Afrit->anim[ATTACK].offset.x = 0;
//     Afrit->anim[ATTACK].offset.y = 0;
//     Afrit->anim[ATTACK].speed = 150;
//     Afrit->anim[DEATH].pos->x = 7;
//     Afrit->anim[DEATH].pos->y = 0; 
//     Afrit->anim[DEATH].nb_frame = 10;
//     Afrit->anim[DEATH].offset.x = 0;
//     Afrit->anim[DEATH].offset.y = 0;
//     Afrit->anim[DEATH].speed = 150;
//     Afrit->anim[PROJECTILE].pos->x = 6;
//     Afrit->anim[PROJECTILE].pos->y = 1; 
//     Afrit->anim[PROJECTILE].nb_frame = 9;
//     Afrit->anim[PROJECTILE].offset.x = 0;
//     Afrit->anim[PROJECTILE].offset.y = 0;
//     Afrit->anim[PROJECTILE].speed = 150;
// }

// t_sprite    sprite_init_afrit(void)
// {
//     t_sprite Afrit;

//     Afrit.on = 0;
//     Afrit.index = IDLE;
//     Afrit.total_size.w = 1920;
//     Afrit.total_size.h = 320;
//     Afrit.nb_frame.x = 15;  
//     Afrit.nb_frame.y = 2;  
//     Afrit.frame_size.w = Afrit.total_size.w / Afrit.nb_frame.x;
//     Afrit.frame_size.h = Afrit.total_size.h / Afrit.nb_frame.y;
//     Afrit.time = 0;

//     Afrit.displayed_part.x = 0;
//     Afrit.displayed_part.y = 0;

//     //Afrit.text = text;
//     init_anim_afrit(&Afrit);
//     return (Afrit);
// }

// static void    load_Pyro(t_data *d)
// {
//     int i;

//     i = 0;
//     while (i < NB_MAX_MOBS / 2)
//     {
//         d->mobs[i].attack_dist = 2;
//         d->mobs[i].dmg_per_hit = 20;
//         //d->mobs[i].sprite = d->sprite[i + MOB_INDEX];
//         d->mobs[i].life = 100;
//         i++;
//     }
// }

// static void    load_Afrit(t_data *d)
// {
//     int i;

//     i = NB_MAX_MOBS / 2;
//     while (i < NB_MAX_MOBS)
//     {
//         d->mobs[i].attack_dist = 1;
//         d->mobs[i].dmg_per_hit = 15;
//         //d->mobs[i].sprite = d->sprite[i + MOB_INDEX];
//         d->mobs[i].life = 200;
//         i++;
//     }
// }

// void     fill_pixels(char *str, t_data *d, int mob)
// {
//     SDL_Surface *surface;
//     SDL_Surface *converted;
// 	SDL_PixelFormat *format;

//     surface = NULL;
//     if (!(surface = SDL_LoadBMP(str)))
//       printf("Erreur de chargement de l'image : %s\n",SDL_GetError());
//     format = SDL_AllocFormat(SDL_PIXELFORMAT_ARGB32);
//     converted = SDL_ConvertSurface(surface, format, 0);
	
//     d->sprite[mob].pixels = converted->pixels;



	
//     //SDL_FreeSurface(surface);
// }

// void    duplicate_mob(t_data *d, t_img *img, t_img *img2)
// {
//     int i;

//     i = MOB_INDEX;
//     while (i < NB_MAX_MOBS / 2 + MOB_INDEX)
//     {
//         d->sprite[i] = sprite_init_pyro();
//         d->sprite[i].pixels = img->pixels;
//         i++;
//     }
//     while (i < NB_MAX_MOBS + MOB_INDEX)
//     {
//         d->sprite[i] = sprite_init_afrit();
//         d->sprite[i].pixels = img2->pixels;
//         i++;
//     }
// }

// int    load_sprite_mob(t_data *d)
// {
//     t_img   *img[2];
    
//     if (!(img[0] = ft_memalloc(sizeof(t_img))))
//         return (EXIT_FAILURE);
//     bmp_reader("Sprites/Mobs/pyro.bmp", img[0]);
//     d->sprite[PYRO] = sprite_init_pyro();

//     if (!(img[1] = ft_memalloc(sizeof(t_img))))
//         return (EXIT_FAILURE);
//     bmp_reader("Sprites/Mobs/afrit.bmp", img[1]);
//     d->sprite[AFRIT] = sprite_init_afrit();

//     //duplicate_mob(d, img, img2);
//     //load_Pyro(d);
//     //load_Afrit(d);
//     return (0);
// }
#include "proto_global.h"

// void    clean_sprite_gun(t_data *d)
// {
//     int i;

//     i = 0;
//     while (i < 6)
//     {
//         //if (d->sprite->img[i])
//             // free(&d->sprite->img[i]);
//         ft_bzero(&d->sprite->img[i], sizeof(t_img));
//         i++;
//     }
// }

int    malloc_sprite_gun(t_img *img[6])
{
    int i;

    i = 0;
    while (i < 6)
    {
    if (!(img[i] = ft_memalloc(sizeof(t_img))))
        return (EXIT_FAILURE);
    i++;
    }
    return (0);
}

void    init_sprite(t_data *d)
{
    int i;
	t_sprite *sprite;

    i = 10;
    load_sprite_gun(d);
    //load_sprite_mob(d);
    
    d->gun_ind = 0;   //Le sprite a afficher
    d->sprite[d->gun_ind].index = 0;   //L'animation du sprite a afficher
    d->mob_ind = 15;
}

int    load_sprite_gun(t_data *d)
{
    SDL_Texture *texture;
    

    texture = load_sprite_bmp(MELEE_PATH, d);
    d->sprite[MELEE] = sprite_init_melee(texture);
    
    texture = load_sprite_bmp(REVOLVER_PATH, d);
    d->sprite[REVOLVER] = sprite_init_revolver(texture);
    
    texture = load_sprite_bmp(SSG_PATH, d);
    d->sprite[SSG] = sprite_init_ssg(texture);
    
    texture = load_sprite_bmp(ASSAULT_RIFLE_PATH, d);
    d->sprite[ASSAULT_RIFLE] = sprite_init_ar(texture);
    
    texture = load_sprite_bmp(LMG_PATH, d);
    d->sprite[LMG] = sprite_init_lmg(texture);
    
    texture = load_sprite_bmp(DEATH_DEALER_PATH, d);
    d->sprite[DEATH_DEALER] = sprite_init_dd(texture);



    return (EXIT_SUCCESS);
}
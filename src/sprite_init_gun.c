#include "proto_global.h"

void    clean_sprite_gun(t_data *d)
{
    int i;

    i = 0;
    while (i < 6)
    {
        //if (d->sprite->img[i])
            // free(&d->sprite->img[i]);
        ft_bzero(&d->sprite->img[i], sizeof(t_img));
        i++;
    }
}

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

int    load_sprite_gun(t_data *d)
{
    t_img *img[6];
    
    if (malloc_sprite_gun(img) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    bmp_reader("Sprites/Guns/Melee.bmp", img[0]);
    d->sprite[0] = sprite_init_melee(img[0]);

    bmp_reader("Sprites/Guns/Revolver.bmp", img[1]);
    d->sprite[1] = sprite_init_revolver(img[1]);

    bmp_reader("Sprites/Guns/SuperShotgun.bmp", img[2]);
    d->sprite[2] = sprite_init_ssg(img[2]);

    bmp_reader("Sprites/Guns/AssaultRifle.bmp", img[3]);
    d->sprite[3] = sprite_init_ar(img[3]);

    bmp_reader("Sprites/Guns/lmg.bmp", img[4]);
    d->sprite[4] = sprite_init_lmg(img[4]);
    
    bmp_reader("Sprites/Guns/DeathDealer.bmp", img[5]);
    d->sprite[5] = sprite_init_dd(img[5]);
    return (0);
}
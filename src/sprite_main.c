#include "proto_global.h"

void    free_sprites(t_data *d)
{
    int i;

    i = 0;
    while (i < MAX_WEAPONS)
    {
        SDL_DestroyTexture(d->sprite[i].text);
        d->sprite[i].text = NULL;
        i++;
    }
}

SDL_Texture     *load_sprite_bmp(char *str, t_data *d)
{
    SDL_Surface *surface;
    SDL_Texture *texture;

    surface = NULL;
    texture = NULL;
    if (!(surface = SDL_LoadBMP(str)))
        exit_with_msg("Erreur de chargement de l'image : %s\n");
    if (!(texture = SDL_CreateTextureFromSurface(d->rend, surface)))
        exit_with_msg("Erreur de conversion de la surface : %s\n");
    SDL_FreeSurface(surface);
    return (texture);
}
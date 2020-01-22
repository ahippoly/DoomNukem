#include "SDL.h"

SDL_Point add_sdl_point(SDL_Point p, int add)
{
    p.x += add;
    p.y += add;
    return (p);
}

SDL_Point mult_sdl_point(SDL_Point p, double mul)
{
    p.x = mul * p.x;
    p.y = mul * p.y;
    return(p);
}

SDL_Point create_point(int x, int y)
{
    SDL_Point p;

    p.x = x;
    p.y = y;
    return(p);
}
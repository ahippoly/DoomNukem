#include "proto_global.h"
#include "proto_global.h"

SDL_Point add_sdl_point(SDL_Point p, SDL_Point add, int is_sub)
{
    if (is_sub == 1)
    {
        p.x -= add.x;
        p.y -= add.y;
    }
    else
    {
        p.x += add.x;
        p.y += add.y;
    }
    return (p);
}

SDL_Point mult_sdl_point(SDL_Point p, float mul)
{
    p.x = mul * p.x;
    p.y = mul * p.y;
    return (p);
}

void swap_point(SDL_Point *p1, SDL_Point *p2)
{
    SDL_Point tmp;

    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void sort_point_by_x(SDL_Point *p1, SDL_Point *p2)
{
    if (p1->x > p2->x)
        swap_point(p1, p2);
}

void swap_t_point(t_point *p1, t_point *p2)
{
    t_point tmp;

    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void sort_t_point_by_x(t_point *p1, t_point *p2)
{
    if (p1->x > p2->x)
        swap_t_point(p1, p2);
}

SDL_Point create_point(int x, int y)
{
    SDL_Point p;

    p.x = x;
    p.y = y;
    return (p);
}
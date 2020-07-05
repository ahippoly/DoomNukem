#include "proto_global.h"

//OKK
t_wall_ref ***init_wall_ref(t_size map_size)
{
    t_wall_ref ***wall_ref;
    int i;
    int j;

    i = 0;
    wall_ref = (t_wall_ref***)p_malloc(sizeof(t_wall_ref**) * map_size.h);
    while (i < map_size.h)
    {
        wall_ref[i] = (t_wall_ref**)p_malloc(sizeof(t_wall_ref*) * map_size.w);
        j = 0;
        while (j < map_size.w)
            wall_ref[i][j++] = NULL;
        i++;
    }
    return (wall_ref);
}

t_wall_ref *alloc_wall(int wall_id)
{
    t_wall_ref *ref;

    ref = (t_wall_ref*)p_malloc(sizeof(t_wall_ref));
    ref->wall_id = wall_id;
    ref->next = NULL;
    return (ref);
}

t_wall_ref *add_wall_reference(t_wall_ref *chain, int new_wall_id)
{
    t_wall_ref *new;

    new = alloc_wall(new_wall_id);
    new->next = chain;
    return (new);
}
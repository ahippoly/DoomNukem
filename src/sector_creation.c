#include "editor.h"
#include "global_header.h"


void init_wall_ref(t_env *env)
{
    int i;
    int j;

    env->map_size.w = MAP_SIZE_X;
    env->map_size.h = MAP_SIZE_Y;
    i = 0;
    env->map_wall_ref = (t_wall_ref***)p_malloc(sizeof(t_wall_ref**) * env->map_size.h);
    while (i < env->map_size.h)
    {
        env->map_wall_ref[i] = (t_wall_ref**)p_malloc(sizeof(t_wall_ref*) * env->map_size.w);
        j = 0;
        while (j < env->map_size.w)
            env->map_wall_ref[i][j++] = NULL;
        i++;
    }
}

t_wall_ref *alloc_wall(int wall_id)
{
    t_wall_ref *ref;

    ref = (t_wall_ref*)p_malloc(sizeof(t_wall_ref));
    ref->wall_id = wall_id;
    ref->next = NULL;
    return(ref);
}

t_wall_ref *add_wall_reference(t_wall_ref *chain, int new_wall_id)
{
    t_wall_ref *new;

    new = alloc_wall(new_wall_id);
    new->next = chain;
    return (new);
}

void reference_wall(SDL_Point pos, int wall_id, t_env *env)
{
    t_wall_ref *ref;
    t_wall_ref *new_ref;
    t_wall_ref *first;
    // faut mettre le first maillon de la liste chainee
    
    ref = env->map_wall_ref[pos.y][pos.x];
    new_ref = alloc_wall(wall_id);
    new_ref->next = env->map_wall_ref[pos.y][pos.x];
    env->map_wall_ref[pos.y][pos.x] = new_ref;
}

void add_wall_ref_point(t_wall wall, t_env *env)
{
    reference_wall(wall.p1, wall.id, env);
    reference_wall(wall.p2, wall.id, env);
    // c est le truc du dessus
    // la faut faire pour les 2 points du wall
}

void clear_map_ref(t_env *env)
{
    int i;
    int j;
    t_wall_ref *wall_ref;
    t_wall_ref *tmp;

    i = 0;
    while (i < env->map_size.h)
    {
        j = 0;
        while (j < env->map_size.w)
        {
            wall_ref = env->map_wall_ref[i][j];
            while (wall_ref != NULL)
            {
                tmp = wall_ref;
                wall_ref = wall_ref->next;
                free(tmp);
            }
            j++;
        }
        free(env->map_wall_ref[i]);
        i++;
    }
    free(env->map_wall_ref);
}

void print_wall_ref(t_env *env)
{
    int i;
    int j;
    int one_at_least;
    t_wall_ref *ref;

    i = 0;
    while (i < env->map_size.h)
    {
        j = 0;
        while (j < env->map_size.w)
        {
            ref = env->map_wall_ref[i][j];
            one_at_least = 0;
            while (ref)
            {
                one_at_least = 1;
                printf("%i,", ref->wall_id);
                ref = ref->next;
            }
            if (one_at_least == 0)
            {
                printf("-1,");
            }
            printf(" ");
            j++;
        }
        i++;
        printf("\n"); 
    }
    printf("\n");
}

int find_chained_wall(t_wall actual, SDL_Point first, int is_p2_outside, t_env *env)
{
    t_wall_ref *ref;
    t_wall next_wall;
    SDL_Point outside;

    if (is_p2_outside == 1)
        outside = actual.p2;
    else
        outside = actual.p1;
    printf("checked point : x = %i, y = %i, id = %i\n", outside.x, outside.y, actual.id);
    if (outside.x == first.x && outside.y == first.y)
        return(1);
    ref = env->map_wall_ref[outside.y][outside.x];
    while (ref)
    {
        printf("search while, wall id = %i\n", ref->wall_id);
        if (ref->wall_id == actual.id)
        {
            ref = ref->next;
            continue;
        }
        next_wall = env->wall_list[ref->wall_id];
        if (next_wall.p1.x == outside.x && next_wall.p1.y == outside.y)
            is_p2_outside = 1;
        else
            is_p2_outside = 0;
        if (find_chained_wall(next_wall, first, is_p2_outside, env))
            return (1);
        ref = ref->next;
    }
    return (0);
}

void find_sector(t_env *env, t_wall wall)
{
    int i;
    t_wall_ref *ref;
    t_wall      linked_wall;
    int         is_p1_common;
    ref = env->map_wall_ref[wall.p2.y][wall.p2.x];
    while (ref)
    {
        printf("First while\n");
        if (ref->wall_id == wall.id)
        {
            ref = ref->next;
            continue;
        }
        linked_wall = env->wall_list[ref->wall_id];
        if (wall.p1.x == linked_wall.p1.x && wall.p1.y == linked_wall.p1.y)
            is_p1_common = 1;
        else
            is_p1_common = 0;
        if (find_chained_wall(linked_wall, wall.p1, is_p1_common, env))
            printf("sector found\n");
        ref = ref->next;
    }
}



void create_room(t_env *env, int begin, int end)
{
    t_room *new;
    int i;

    if (!(new = (t_room*)malloc(sizeof(t_room))))
        exit_with_msg("Failed to malloc");
    new->nb_wall = end - begin;
    if (!(new->wall_ref = (int*)malloc(sizeof(int) * new->nb_wall)))
        exit_with_msg("Failed to malloc");
    i = 0;
    while (i < new->nb_wall)
    {
        new->wall_ref[i] = begin + i;
        i++;
    }
    new->room_id = env->room_count++;
    new->next = env->room_list;
    env->room_list = new;
}

void print_rooms_content(t_env *env)
{
    int     i;
    t_room *room;

    room = env->room_list;
    printf("ROOM_CONTENTS :\n");
    while (room)
    {
        i = 0;
        while (i < room->nb_wall)
            printf("room id %i have wall id %i\n", room->room_id, room->wall_ref[i++]);
        room = room->next;
    }
}
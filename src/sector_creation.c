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
    // faut mettre le first maillon de la liste chainee
    
    ref = env->map_wall_ref[pos.y][pos.x];
    new_ref = alloc_wall(wall_id);
    new_ref->next = env->map_wall_ref[pos.y][pos.x];
    env->map_wall_ref[pos.y][pos.x] = new_ref;
}

void add_wall_ref_point(t_wall wall, t_env *env)
{
    if (wall.id != -1)
    {
        reference_wall(wall.p1, wall.id, env);
        reference_wall(wall.p2, wall.id, env);
    }
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
    if (env->map_wall_ref == NULL)
        return;
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

void recreate_full_map_ref(t_env *env)
{
    int i;

    clear_map_ref(env);
    init_wall_ref(env);
    i = 0;
    while (i < env->wall_count)
        add_wall_ref_point(env->wall_list[i++], env);
}

void print_wall_ref(t_env *env, int fd)
{
    int i;
    int j;
    int one_at_least;
    t_wall_ref *ref;

    recreate_full_map_ref(env);
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
                ft_putstr_fd(ft_itoa(ref->wall_id), fd);
                ref = ref->next;
                if (ref)
                    ft_putstr_fd(",", fd);
            }
            if (one_at_least == 0)
            {
                ft_putstr_fd("-1", fd);
            }
            ft_putstr_fd(" ", fd);
            j++;
        }
        i++;
        ft_putstr_fd("\n", fd); 
    }
    ft_putstr_fd("\n", fd);
}

void clear_room_list(t_env *env)
{
    t_room *next;

    while (env->room_list)
    {
        next = env->room_list->next;
        free(env->room_list);
        env->room_list = next;
    }
    env->room_count = 0;
}

void create_room(t_env *env, int begin, int end)
{
    t_room *new;
    int i;

    if (!(new = (t_room*)malloc(sizeof(t_room))))
        exit_with_msg("Failed to malloc");
    new->nb_wall = end - begin;
    new->wall_ref.start = begin;
    new->wall_ref.end = end;
    new->room_id = env->room_count++;
    new->next = env->room_list;
    env->room_list = new;
    //printf("create room id start = %i, id end = %i\n", new->wall_ref.start, new->wall_ref.end);

}

void recreate_room_list(t_env *env)
{
    int i;
    int new_room_nb;
    int begin;
    int current_room_id;
    t_room *new_room;

    new_room_nb = 0;
    i = 0;
    clear_room_list(env);
    while (i < env->wall_count)
    {
        if (env->wall_list[i].id != -1 && env->wall_list[i].room_id_ref != -1)
        {
            begin = i;
            current_room_id = env->wall_list[begin].room_id_ref;
            while (i < env->wall_count && current_room_id == env->wall_list[i].room_id_ref)
                i++;
            create_room(env, begin, i);
        }
        i++;

    }
}

void print_rooms_content(t_env *env)
{
    int     i;
    t_room *room;

    recreate_room_list(env);
    room = env->room_list;
    printf("ROOM_CONTENTS :\n");
    while (room)
    {
        printf("room id %i have wall id from %i to %i\n", room->room_id, room->wall_ref.start, room->wall_ref.end);
        room = room->next;
    }
}
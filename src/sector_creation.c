#include "editor.h"
#include "global_header.h"

void reference_wall(SDL_Point pos, int wall_id, t_env *env)
{
    t_wall_ref *ref;
    t_wall_ref *tmp;
    // faut mettre le first maillon de la liste chainee
    
    ref = env->map_wall_ref[pos.y][pos.x];
    while (ref != NULL)
    {
        tmp = ref;
        ref = ref->next;
    }
    ref = (t_wall_ref*)p_malloc(sizeof(t_wall_ref));
    ref->wall_id = wall_id;
    ref->next = NULL;
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

t_sector create_sector(t_env *env)
{

}
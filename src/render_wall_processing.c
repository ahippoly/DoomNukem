#include "global_header.h"
#include "render.h"
#include "editor.h"
#include "img_file.h"


double calc_wall_hit_scale(t_wall wall, t_point inter)
{
    int     x_min;
    int     x_max;
    double  inter_diff_x;
    double  tmp;

    sort_point_by_x(&wall.p1, &wall.p2);
    if (is_equ_tolerance(wall.p2.x - wall.p1.x, 0, INTER_TOLERANCE))
        return (modf((inter.y - wall.p1.y) / (wall.p2.y - wall.p1.y) * wall.length, &tmp));
    return (modf((inter.x - wall.p1.x) / (wall.p2.x - wall.p1.x) * wall.length, &tmp));
    
}

t_calced_walls check_inter_with_wall(t_wall wall, double rot, t_point pos, double look_rot)
{
    t_point inter;
    t_calced_walls res;

    res.dist = 9999;
    res.scale = 0;
    res.wall_id = wall.id;
    inter = inter_with_dir(pos, rot, create_t_point(wall.p1.x, wall.p1.y), create_t_point(wall.p2.x, wall.p2.y));
    if (inter.x != -42)
    {
        res.dist = ft_frange(cos(look_rot * M_PI_2) * (inter.x - pos.x) + sin(look_rot * M_PI_2) * (inter.y - pos.y), 0, res.dist);
        res.scale = calc_wall_hit_scale(wall, inter);
    }
        //dist = hypot(inter.x - pos.x, inter.y - pos.y) * cos((look_rot - rot )* M_PI_2);
    //printf("wall x min = %i, x max = %i, touch x = %f, scale = %f, rot = %f, look_rot = %f\n", wall.p1.x, wall.p2.x, inter.x, calc_wall_hit_scale(wall, inter), rot, look_rot);
    return (res);
}

t_calced_walls check_intersect_with_all_wall(t_data *d, t_map_data *map, double rot, double look_rot)
{
    int i;
    t_calced_walls res ;
    t_calced_walls tmp;
    t_point inter;
    t_wall wall;

    i = 0;
    res.dist = 9999;
    while (i < map->wall_count)
    {
        wall = map->wall_list[i];
        tmp = check_inter_with_wall(wall, rot, d->player_pos, look_rot);
        res = tmp.dist < res.dist ? tmp : res ;
        //ft_fmin(dist, check_inter_with_wall(wall, rot, d->player_pos, look_rot));
        i++;
    }
    //printf("dist of closest wall : %f\n", res.dist);
    return (res);
}

void sort_walls_by_dist(t_data *d, t_map_data *map, double current_angle)
{
    int i;
    int j;
    int tmp;
    t_calced_walls dist_scale;

    d->sorted_walls[0] = check_inter_with_wall(map->wall_list[0], current_angle, d->player_pos, d->rot);
    d->sorted_walls[0].wall_id = 0;
    i = 1;
    while (i < map->wall_count)
    {
        dist_scale = check_inter_with_wall(map->wall_list[i], current_angle, d->player_pos, d->rot);
        //printf("wall dist to player = %f\n",  dist_scale.dist);
        j = 0;
        while (dist_scale.dist < d->sorted_walls[j].dist && j < i)
            j++;
        tmp = j;
        j = i;
        while (j > tmp)
        {
            j--;
            d->sorted_walls[j + 1] = d->sorted_walls[j];
        }
        d->sorted_walls[j] = dist_scale;
        i++;
    }
    // i = 0;
    // while (i < map->wall_count)
    // {
    //     printf("wall sorted dist = %f, i = %i, map_count = %i\n", d->sorted_walls[i].dist, i, map->wall_count);
    //     i++;
    // }
}
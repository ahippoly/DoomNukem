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
    res.text_id = wall.texture_id;
    res.wall_id = wall.id;
    res.wall_rot = wall.rotation;
    res.alpha = (float)(100 - wall.transparency) / 100;
    inter = inter_with_dir(pos, rot, create_t_point(wall.p1.x, wall.p1.y), create_t_point(wall.p2.x, wall.p2.y));
    if (inter.x != -42)
    {
        res.dist = ft_frange(cos(look_rot) * (inter.x - pos.x) + sin(look_rot) * (inter.y - pos.y), 0, res.dist);
        res.scale = calc_wall_hit_scale(wall, inter);
    }
        //dist = hypot(inter.x - pos.x, inter.y - pos.y) * cos((look_rot - rot ));
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

t_calced_walls check_perp_wall(t_wall wall, t_point pos)
{
    t_point inter;
    t_point p1;
    t_point p2;
    t_calced_walls res;

    res.dist = 9999;
    res.scale = 0;
    res.text_id = wall.texture_id;
    res.wall_id = wall.id;
    res.wall_rot = wall.rotation;
    res.alpha = (float)(100 - wall.transparency) / 100;
    p1.x = pos.x + cos(wall.rotation - M_PI_2) * 30;
    p1.y = pos.y + sin(wall.rotation - M_PI_2) * 30;
    p2.x = pos.x + cos(wall.rotation + M_PI_2) * 30; 
	p2.y = pos.y + sin(wall.rotation + M_PI_2) * 30;
    printf("p2 = %f,%f\n", p2.x, p2.y);
    printf("cos = %f, sin = %f\n", cos(wall.rotation + M_PI_2), sin(wall.rotation + M_PI_2));
    inter = find_intersect(p1, p2, create_t_point(wall.p1.x, wall.p1.y), create_t_point(wall.p2.x, wall.p2.y));
    printf("Inter = %f,%f\n", inter.x, inter.y);
    if (inter.x != -42)
    {
        //res.dist = ft_frange(cos(wall.rotation + M_PI_2) * (inter.x - pos.x) + sin(wall.rotation + M_PI_2) * (inter.y - pos.y), 0, res.dist);
        res.dist = fabs(cos(wall.rotation + M_PI_2) * (inter.x - pos.x) + sin(wall.rotation + M_PI_2) * (inter.y - pos.y));
        res.scale = calc_wall_hit_scale(wall, inter);
    }
        //dist = hypot(inter.x - pos.x, inter.y - pos.y) * cos((look_rot - rot ));
    //printf("wall x min = %i, x max = %i, touch x = %f, scale = %f, rot = %f, look_rot = %f\n", wall.p1.x, wall.p2.x, inter.x, calc_wall_hit_scale(wall, inter), rot, look_rot);
    return (res);
}

t_calced_walls check_perp_all_wall(t_data *d, t_map_data *map, t_point pos)
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
        tmp = check_perp_wall(wall, d->player_pos);
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
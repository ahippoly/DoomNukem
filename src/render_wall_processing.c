#include "global_header.h"
#include "render.h"
#include "editor.h"
#include "img_file.h"


double calc_wall_hit_scale(t_wall wall, t_point inter)
{
    sort_t_point_by_x(&wall.p1_f, &wall.p2_f);
    if (is_equ_tolerance(wall.p2_f.x - wall.p1_f.x, 0, INTER_TOLERANCE))
        return (get_float_part((inter.y - wall.p1_f.y) / (wall.p2_f.y - wall.p1_f.y) * wall.length));
    return (get_float_part((inter.x - wall.p1_f.x) / (wall.p2_f.x - wall.p1_f.x) * wall.length));
}

double calc_wall_hit_scale_z(t_wall wall, t_point inter)
{
    sort_t_point_by_x(&wall.p1_f, &wall.p2_f);
    if (is_equ_tolerance(wall.p2_f.x - wall.p1_f.x, 0, INTER_TOLERANCE))
        return ( (inter.y - wall.p1_f.y) / (wall.p2_f.y - wall.p1_f.y) );
    return ( (inter.x - wall.p1_f.x) / (wall.p2_f.x - wall.p1_f.x) );
}

double calc_wall_hit_scale_x(t_wall wall, double scale_z)
{
    return (get_float_part(scale_z * wall.length));
}

t_calced_walls check_inter_with_wall(t_wall wall, double rot, t_point pos, double look_rot)
{
    t_point inter;
    t_calced_walls res;

    res.dist = 9999;
    res.scale = 0;
	res.wall = wall;
    inter = inter_with_dir(pos, rot, wall.p1_f, wall.p2_f);
    if (inter.x != -42)
    {
        res.dist = ft_frange(cos(look_rot) * (inter.x - pos.x) + sin(look_rot) * (inter.y - pos.y), 0, res.dist);
		res.scale_z = calc_wall_hit_scale_z(wall, inter);
        res.scale = calc_wall_hit_scale_x(wall, res.scale_z);
    }
        //dist = hypot(inter.x - pos.x, inter.y - pos.y) * cos((look_rot - rot ));
    //printf("wall x min = %i, x max = %i, touch x = %f, scale = %f, rot = %f, look_rot = %f\n", wall.p1_f.x, wall.p2.x, inter.x, calc_wall_hit_scale(wall, inter), rot, look_rot);
    return (res);
}

t_calced_walls check_intersect_with_all_wall(t_data *d, t_point pos, double rot, double look_rot)
{
    int i;
    t_calced_walls res ;
    t_calced_walls tmp;
    t_point inter;
    t_wall wall;

    i = 0;
    res.dist = 9999;
    while (i < d->map.wall_count)
    {
        wall = d->map.wall_list[i];
        tmp = check_inter_with_wall(wall, rot, pos, look_rot);
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
	res.wall = wall;
    p1.x = pos.x + cos(wall.rotation - M_PI_2) * 30;
    p1.y = pos.y + sin(wall.rotation - M_PI_2) * 30;
    p2.x = pos.x + cos(wall.rotation + M_PI_2) * 30; 
	p2.y = pos.y + sin(wall.rotation + M_PI_2) * 30;
    // printf("p2 = %f,%f\n", p2.x, p2.y);
    // printf("cos = %f, sin = %f\n", cos(wall.rotation + M_PI_2), sin(wall.rotation + M_PI_2));
    inter = find_intersect(p1, p2, wall.p1_f, wall.p2_f);
    // printf("Inter = %f,%f\n", inter.x, inter.y);
    if (inter.x != -42)
    {
        //res.dist = ft_frange(cos(wall.rotation + M_PI_2) * (inter.x - pos.x) + sin(wall.rotation + M_PI_2) * (inter.y - pos.y), 0, res.dist);
        res.dist = fabs(cos(wall.rotation + M_PI_2) * (inter.x - pos.x) + sin(wall.rotation + M_PI_2) * (inter.y - pos.y));
		res.scale_z = calc_wall_hit_scale_z(wall, inter);
        res.scale = calc_wall_hit_scale_x(wall, res.scale_z);
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

void sort_walls_by_dist(t_data *d, t_map_data *map, double current_angle, t_calced_walls *sorted_walls)
{
    int i;
    int j;
    int tmp;
    t_calced_walls dist_scale;

    sorted_walls[0] = check_inter_with_wall(map->wall_list[0], current_angle, d->player_pos, d->rot);
    i = 1;
    while (i < map->wall_count)
    {
        dist_scale = check_inter_with_wall(map->wall_list[i], current_angle, d->player_pos, d->rot);
        //printf("wall dist to player = %f\n",  dist_scale.dist);
        j = 0;
        while (dist_scale.dist < sorted_walls[j].dist && j < i)
            j++;
        tmp = j;
        j = i;
        while (j > tmp)
        {
            j--;
            sorted_walls[j + 1] = sorted_walls[j];
        }
        sorted_walls[j] = dist_scale;
        i++;
    }
    // i = 0;
    // while (i < map->wall_count)
    // {
    //     printf("wall sorted dist = %f, i = %i, map_count = %i\n", d->sorted_walls[i].dist, i, map->wall_count);
    //     i++;
    // }
}

void sort_perp_walls_dist(t_data *d, t_map_data *map, t_point pos, t_calced_walls *sorted_walls)
{
    int i;
    int j;
    int tmp;
    t_calced_walls dist_scale;

    sorted_walls[0] = check_perp_wall(map->wall_list[0], pos);
    i = 1;
    while (i < map->wall_count)
    {
        dist_scale = check_perp_wall(map->wall_list[i], pos);
        //printf("wall dist to player = %f\n",  dist_scale.dist);
        j = 0;
        while (dist_scale.dist < sorted_walls[j].dist && j < i)
            j++;
        tmp = j;
        j = i;
        while (j > tmp)
        {
            j--;
            sorted_walls[j + 1] = sorted_walls[j];
        }
        sorted_walls[j] = dist_scale;
        i++;
    }
    // i = 0;
    // while (i < map->wall_count)
    // {
    //     printf("wall sorted dist = %f, i = %i, map_count = %i\n", sorted_walls[i].dist, i, map->wall_count);
    //     i++;
    // }
}
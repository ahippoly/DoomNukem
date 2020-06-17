#include "global_header.h"
#include "render.h"
#include "editor.h"
#include "img_file.h"


void move_attempt(t_data *d, t_point *pos, float speed, t_rot look_rot)
{
    pos->y += speed * look_rot.sin_rot ;//* d->diff_time;
    pos->x += speed * look_rot.cos_rot ;//* d->diff_time;
}

float mod_pi(float rot)
{
	if (rot < 0)
		rot = PI_X_2 + rot;
	return(fmod(rot, PI_X_2));
}

int is_angle_in_range(float rot, float min, float max)
{
	printf("rot = %f, min = %f, max = %f\n", rot, min, max);
	if (min > max && (rot > min || rot < max))
		return (1);
	else if (rot > min && rot < max)
		return (1);
	return (0);
}

void move_with_collide(t_data *d, t_point *pos, t_rot rot, float speed)
{
    t_calced_walls sorted[NB_WALL_MAX];
	t_point inter;
	float	diff_x;
	int		will_collide;
	int		i;
	t_calced_walls res;

    sort_perp_walls_dist(d, &d->map, *pos, sorted);
    // printf("rot = %f, wall rot = %f\n", rot / M_PI_2, res.wall.rotation);
	// printf("diff mod pi = %f\n", mod_pi(rot - res.wall.rotation) / M_PI_2);
	i = 0;
	will_collide = 0;
	while (i < d->map.wall_count)
	{
		if (sorted[i].dist < WALL_SIZE)
		{
			inter = find_intersect_no_bound(*pos, (t_point){pos->x + (rot.cos_rot), pos->y + (rot.sin_rot)}, (sorted[i].wall.p1_f), (sorted[i].wall.p2_f));
			diff_x = inter.x - pos->x;
			if ( (diff_x > 0 && (rot.cos_rot) > 0) || (diff_x < 0 && (rot.cos_rot) < 0) )
			{
				res = sorted[i];
				//printf("wall z = %f, z_pos = %f\n", ft_interpolate(res.wall.p1_z_start + res.wall.p1_z_size, res.wall.p2_z_start + res.wall.p2_z_size, res.scale_z), d->z_pos);
				if (ft_interpolate(res.wall.p1_z_start + res.wall.p1_z_size, res.wall.p2_z_start + res.wall.p2_z_size, res.scale_z) > d->z_pos
				&& ft_interpolate(res.wall.p1_z_start, res.wall.p2_z_start, res.scale_z) - d->z_offset < d->z_pos)
					if (++will_collide > 1)
						break;
			}
		}
		i++;
	}
	// printf("inter : %f,%f, diff : %f,%f, dir : %f,%f\n", inter.x, inter.y, inter.x - pos->x, inter.y - pos->y, cos(rot), + sin(rot));
	if (will_collide == 1)
	{
		// printf("recalc needed, wall rot = %f, rot = %f\n", res.wall.rotation / M_PI_2, rot.rot / M_PI_2);
		move_attempt(d, pos, cos(rot.rot - res.wall.rotation) * speed, (t_rot){res.wall.rotation, cos(res.wall.rotation), sin(res.wall.rotation)});
		move_grabbed_wall(d, (t_rot){res.wall.rotation, cos(res.wall.rotation), sin(res.wall.rotation)}, cos(rot.rot - res.wall.rotation) * speed);
	}
	else if (will_collide < 1)
	{
		move_attempt(d, pos, speed, rot);
		move_grabbed_wall(d, rot, speed);
	}
	set_room_ground(d, *pos);
}

void gravity(t_data *d)
{
    d->z_pos += d->z_force;
    d->player_height = d->z_pos + d->z_offset;
	//if (check_in_room(d, d->player_pos) > -1)
	//	printf("is in room\n");
    if (d->z_pos > d->z_ground)
    {
        d->z_pos -=  GRAVITY_FORCE * d->air_time * d->air_time ;
        d->air_time += d->time - d->time_last_frame;
        //printf("air_time = %d\n", d->air_time);
    }
    if (d->z_pos < d->z_ground)
    {
        d->z_pos = d->z_ground;
        d->z_force = 0;
        d->air_time = 0;
    }
}
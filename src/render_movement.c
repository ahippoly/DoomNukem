#include "global_header.h"
#include "render.h"
#include "editor.h"
#include "img_file.h"


void move_attempt(t_point *pos, double speed, double look_rot)
{
    double cos_rot;
    double sin_rot;

    cos_rot = cos(look_rot);
    sin_rot = sin(look_rot);
    pos->y += speed * sin_rot;
    pos->x += speed * cos_rot;
}

double mod_pi(double rot)
{
	if (rot < 0)
		rot = PI_X_2 + rot;
	return(fmod(rot, PI_X_2));
}

int is_angle_in_range(double rot, double min, double max)
{
	printf("rot = %f, min = %f, max = %f\n", rot, min, max);
	if (min > max && (rot > min || rot < max))
		return (1);
	else if (rot > min && rot < max)
		return (1);
	return (0);
}

void move_with_collide(t_data *d, t_point *pos, double rot, double speed)
{
    t_calced_walls res;
	double cos_rot;
	double sin_rot;
    double proj_rot;

    res = check_perp_all_wall(d, &d->map, d->player_pos);

    t_point move_dir;

	proj_rot = acos(cos(rot - res.wall_rot));
    printf("rot = %f\n", rot / M_PI_2);
	if (res.dist < WALL_SIZE && check_inter_with_wall(d->map.wall_list[res.wall_id], rot, *pos, rot).dist != 9999)
	{
		printf("recalc needed, wall rot = %f\n", res.wall_rot / M_PI_2);
		cos_rot = cos(res.wall_rot);
		sin_rot = sin(res.wall_rot);

        move_dir.x = cos(rot) * speed;
        move_dir.y = sin(rot) * speed;
        printf("move_dir: %f,%f, sin:%f, cos:%f\n", move_dir.x,move_dir.y, sin_rot, cos_rot);
		// pos->x += move_dir.x * cos_rot - move_dir.y * cos_rot;
		// pos->y += move_dir.x * sin_rot - move_dir.y * sin_rot;
        // pos->x += cos(proj_rot + res.wall_rot) * speed;
		// pos->y += sin(proj_rot + res.wall_rot) * speed;
        move_attempt(pos, speed, rot);
	}
	else
	{
		move_attempt(pos, speed, rot);
	}
}

void gravity(t_data *d)
{
    d->z_pos += d->z_force;
    d->player_height = d->z_pos + d->z_offset;
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
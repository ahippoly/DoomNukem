#include "global_header.h"
#include "render.h"
#include "editor.h"
#include "img_file.h"

void move_mobs_in_range(t_data *d, t_mob *mobs, int nb_mob)
{
	int i;
	t_mob mob;

	i = 0;
	while (i < nb_mob)
	{
		mob = mobs[i];
		if (get_dist(mob.obj_ref->pos, d->player_pos) < mob.aggro_range)
			move_with_collide(d , mob.obj_ref, get_angle(mob.obj_ref->pos, d->player_pos), mob.speed);
		i++;
	}
}

void repulse_obj(t_data *d, t_obj *obj, float z_force, float speed)
{
	int i;

	i = 0;
	while (i < d->nb_repulsed)
	{
		
		if (d->repulsed[i++] == obj);
		{
			printf("mob found, not added to list, nb_repulse : %d\n", d->nb_repulsed);
			return ;
		}
	}
	obj->z_force = z_force;
	d->repulsed[d->nb_repulsed++] = obj;
}

void load_repulsed_obj(t_data *d, t_obj **repulsed, int nb_pulse)
{
	int i;
	t_obj	*obj;

	i = 0;
	while (i < nb_pulse)
	{
		obj = repulsed[i];
		if (obj->air_time > 0)
			move_with_collide(d, obj, get_angle(d->player_pos, obj->pos), 3);
		else
			del_from_array(*repulsed, &d->nb_repulsed, obj, sizeof(t_obj*));
		i++;
	}

}
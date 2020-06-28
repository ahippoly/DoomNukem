#include "proto_global.h"
#include "proto_global.h"
#include "proto_global.h"
#include "proto_global.h"

void change_mob_life(t_data *d, t_mob *mob, int damage)
{

}

void change_player_life(t_data *d, int *hp, int damage)
{
	*hp -= damage;
}

void check_mob_attack(t_param param)
{
	float dist;

	printf("player is attacked\n");
	dist = get_dist(param.d->player_pos, param.mob->obj_ref->pos);
	if (dist < param.mob->attack_dist + 1)
		change_player_life(param.d, &param.d->hud.hp, param.mob->dmg_per_hit);
}

void move_mobs_in_range(t_data *d, t_mob *mobs, int nb_mob)
{
	int i;
	t_mob *mob;
	float dist;

	i = 0;
	while (i < nb_mob)
	{
		mob = &mobs[i];
		dist = get_dist(mob->obj_ref->pos, d->player_pos);
		if (dist < mob->aggro_range && dist > MOB_MIN_RANGE)
			move_with_collide(d , mob->obj_ref, get_angle(mob->obj_ref->pos, d->player_pos), mob->speed);
		if (dist < mob->attack_dist && d->time - mob->attack_timer > mob->attack_delay)
		{
			printf("diff time mob attack = %i\n", d->time - mob->attack_timer);
			mob->attack_timer = d->time;
			set_sprite_callback(&mob->sprite, check_mob_attack, (t_param){d, mob});
			load_anim(&mob->sprite, d->time, ANIM_MOB_MELEE);
		}

		i++;
	}
}



void repulse_obj(t_data *d, t_obj *obj, float z_force, float speed)
{
	int i;

	i = 0;
	obj->z_force += z_force;
	while (i < d->nb_repulsed)
	{
		if (d->repulsed[i++] == obj);
		{
			//printf("mob found, not added to list, nb_repulse : %d\n", d->nb_repulsed);
			return ;
		}
	}
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

void shoot_gun(t_data *d, t_weapon *weapon)
{
	t_ray sorted[NB_MAX_OBJ];
	t_mob *origin;

	sort_ray_by_dist_player(d, d->player_pos, d->rot_calc, sorted);
	if (sorted[0].dist < weapon->range && sorted[0].room_id == TYPE_MOB)
	{
		origin = (t_mob*)sorted[0].obj_ref->origin;
		printf("mob hit speed = %f\n", origin->speed);
		repulse_obj(d, sorted[0].obj_ref, weapon->z_force, 5);
	}
}


void process_mobs_gameplay(t_data *d)
{
	load_repulsed_obj(d, d->repulsed, d->nb_repulsed);
	move_mobs_in_range(d, d->mobs, d->nb_mob);
	process_mobs_anim(d);
	
}
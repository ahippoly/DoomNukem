#include "proto_global.h"
#include "proto_global.h"
#include "proto_global.h"
#include "proto_global.h"


t_obj	convert_wall_to_obj(t_data *d, t_wall *wall)
{
	t_obj obj;
	t_img *text;

	obj.p1 = wall->p1;
	obj.p2 = wall->p2;
	obj.length = wall->length;
	text = &d->texture[wall->texture_id];
	// obj.text = (t_img){text->pixels, (SDL_Rect){0, 0, 0, 0}, text->w, text->h};
	obj.pixels = text->pixels;
	obj.w = text->w;
	obj.h = text->h;
	obj.z_height = (t_p_size){wall->p1_z_start, wall->p1_z_size};
	obj.z_step = (t_p_size){wall->p2_z_start - wall->p1_z_start, wall->p2_z_size - wall->p1_z_size};
	obj.z_text_offset = 0;
	obj.alpha = wall->alpha;
	// printf("wall z_height : pos = %f, size = %f\n", obj.z_height.pos, obj.z_height.size);
	// printf("wall z_step : pos = %f, size = %f\n", obj.z_step.pos, obj.z_step.size);
	obj.can_collide = wall->can_collide;
	// printf("wall collide = %i\n", wall->can_collide);
	obj.room_id = wall->room_id_ref;
	obj.rotation = calc_sin_cos_rot(wall->rotation);
	obj.z_ground = -1;
	// printf("wall rot = %.10f, rot = %.10f\n", wall->rotation, obj.rotation.rot);
	obj.origin = wall;
	return (obj);
}

void create_raybox(t_data *d, t_obj *obj, t_rot rot_calc)
{
	if (obj->room_id < -1)
	{
		obj->rotation = calc_sin_cos_rot(rot_calc.rot - M_PI_2);
		obj->p1.x = obj->pos.x - obj->size * rot_calc.sin_rot;
		obj->p1.y = obj->pos.y + obj->size * rot_calc.cos_rot;
		obj->p2.x = obj->pos.x + obj->size * rot_calc.sin_rot;
		obj->p2.y = obj->pos.y - obj->size * rot_calc.cos_rot;
		//sort_t_point_by_x(&obj->p1, &obj->p2);
		//printf("obj p1 : %f,%f, p2: %f,%f\n", obj->p1.x, obj->p1.y, obj->p2.x, obj->p2.y);
	}
}

void create_obj_raybox(t_data *d)
{
	int i;

	i = 0;
	while (i < d->nb_obj)
	{
		create_raybox(d, &d->obj_list[i++], d->rot_calc);
	}
}

t_obj	convert_mob_to_obj(t_data	*d,	t_mob *mob)
{
	t_obj	obj;

	obj.pos = mob->pos;
	obj.size = mob->size;
	obj.z_height.pos = mob->z_pos;
	obj.z_height.size = mob->z_size;
	obj.z_step.pos = 0;
	obj.z_step.size = 0;
	obj.z_text_offset = get_float_part(obj.z_height.pos + obj.z_height.size);
	obj.length = 1;
	obj.alpha = 1;
	obj.room_id = TYPE_MOB;
	// obj.text = (t_img){mob->text->pixels, (SDL_Rect){0, 0, 0, 0}, mob->text->w, mob->text->h};
	// obj.pixels = d->img[1].pixels;
	// obj.w = d->img[1].w;
	// obj.h = d->img[1].h;
	//print_sprite(&d->sprite[AFRIT]);
	obj.pixels = mob->sprite.dst;
	obj.w = mob->sprite.dst_w;
	obj.h = mob->sprite.dst_h;
	printf("obj : %i,%i\n", obj.w, obj.h);
	obj.can_collide = 0;
	obj.z_ground = DEFAULT_Z_GROUND;
	obj.z_force = 0;
	obj.air_time = 0;
	obj.origin = mob;
	return (obj);
}

t_obj	convert_prop_to_obj(t_data	*d,	t_props *props)
{
	t_obj	obj;

	obj.pos = props->pos;
	obj.size = props->size / 2;
	obj.z_height.pos = props->z_pos;
	obj.z_height.size = props->size;
	obj.z_step.pos = 0;
	obj.z_step.size = 0;
	obj.z_text_offset = get_float_part(obj.z_height.pos + obj.z_height.size);
	obj.length = 1;
	obj.alpha = 1;
	obj.room_id = TYPE_PROP;
	// obj.text = (t_img){props->text->pixels, (SDL_Rect){0, 0, 0, 0}, props->text->w, props->text->h};
	obj.pixels = props->text->pixels;
	obj.w = props->text->w;
	obj.h = props->text->h;
	obj.can_collide = props->can_collide;
	obj.z_ground = DEFAULT_Z_GROUND;
	obj.z_force = 0;
	obj.air_time = 0;
	obj.origin = props;
	return (obj);
}

void init_obj_room_ground(t_data *d, t_obj *obj_list, int nb_obj)
{
	int i;
	t_obj *curr;

	i = 0;
	while (i < nb_obj)
	{
		curr = &obj_list[i];
		if (curr->room_id < -1)
			curr->z_ground = set_room_ground(d, curr->pos);
		i++;
	}
}

void init_obj_list(t_data *d)
{
	int i;
	int j;

	d->nb_obj = d->map.wall_count + d->nb_props + d->nb_mob;
	i = 0;
	j = 0;
	while (i < d->map.wall_count)
	{
		d->obj_list[j++] = convert_wall_to_obj(d, &d->map.wall_list[i++]);
		// printf("wall obj created , i = %i wall_count = %i\n", i, d->map.wall_count);
	}
	i = 0;
	while (i < d->nb_props)
	{
		d->obj_list[j] = convert_prop_to_obj(d, &d->props[i]);
		d->props[i++].obj_ref = &d->obj_list[j++];
	}
	i = 0;
	while (i < d->nb_mob)
	{
		d->obj_list[j] = convert_mob_to_obj(d, &d->mobs[i]);
		d->mobs[i++].obj_ref = &d->obj_list[j++];
	}
	init_obj_room_ground(d, d->obj_list, d->nb_obj);
}

void correct_origin_ref(t_obj *obj_list, int i, int nb_obj, t_obj *obj)
{
	int size;
	int type;

	if (obj->room_id == TYPE_PROP)
	{
		type = TYPE_PROP;
		size = sizeof(t_props);
	}
	if (obj->room_id == TYPE_MOB)
	{
		type = TYPE_MOB;
		size = sizeof(t_mob);
	}
	while (i < nb_obj)
	{
		if (obj->room_id == type)
			obj->origin -= size;
		i++;
	}
}

void del_obj(t_obj *obj_list, int *nb_obj, t_obj *obj)
{
	int i;
	t_obj	*obj2;

	i = 0;
	while (i < *nb_obj)
		if (&obj_list[i++] == obj)
			break;
	i--;
	(*nb_obj)--;
	//correct_origin_ref(obj_list, i, *nb_obj, obj);
	while (i < *nb_obj)
	{
		obj = &obj_list[i + 1];
		if (obj->room_id == TYPE_PROP)
			((t_props*)obj->origin)->obj_ref -= 1;
		if (obj->room_id == TYPE_MOB)
			((t_mob*)obj->origin)->obj_ref -= 1;
		obj_list[i] = obj_list[i + 1];
		i++;
	}
}


#include "global_header.h"
#include "render.h"
#include "editor.h"
#include "img_file.h"


t_obj	convert_wall_to_obj(t_data *d, t_wall *wall)
{
	t_obj obj;
	t_img *text;

	obj.p1 = wall->p1_f;
	obj.p2 = wall->p2_f;
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
	obj.z_text_offset = 0;
	obj.can_collide = wall->can_collide;
	obj.room_id = wall->room_id_ref;
	obj.origin = wall;
	return (obj);
}

void create_raybox(t_data *d, t_obj *obj, t_rot rot_calc)
{
	if (obj->room_id < -1)
	{
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
	obj.z_text_offset = get_float_part(obj.z_height.pos);
	obj.length = 1;
	obj.alpha = 1;
	obj.room_id = TYPE_MOB;
	// obj.text = (t_img){mob->text->pixels, (SDL_Rect){0, 0, 0, 0}, mob->text->w, mob->text->h};
	obj.pixels = d->img[1].pixels;
	obj.w = d->img[1].w;
	obj.h = d->img[1].h;
	obj.can_collide = 0;
	obj.origin = mob;
	return (obj);
}

t_obj	convert_prop_to_obj(t_data	*d,	t_props *props)
{
	t_obj	obj;

	obj.pos = props->pos;
	obj.size = 0.5;
	obj.z_height.pos = props->z_pos;
	obj.z_height.size = 1;
	obj.z_step.pos = 0;
	obj.z_step.size = 0;
	obj.z_text_offset = get_float_part(obj.z_height.pos);
	obj.length = 1;
	obj.alpha = 1;
	obj.room_id = TYPE_PROP;
	// obj.text = (t_img){props->text->pixels, (SDL_Rect){0, 0, 0, 0}, props->text->w, props->text->h};
	obj.pixels = props->text->pixels;
	obj.w = props->text->w;
	obj.h = props->text->h;
	obj.can_collide = 0;
	obj.origin = props;
	return (obj);
}

void init_obj_list(t_data *d)
{
	int i;
	int j;

	d->nb_obj = d->map.wall_count ;//+ d->nb_props + d->nb_mob;
	i = 0;
	j = 0;
	while (i < d->map.wall_count)
	{
		d->obj_list[j++] = convert_wall_to_obj(d, &d->map.wall_list[i++]);
		printf("wall obj created , i = %i\n", i);
	}
	// i = 0;
	// while (i < d->nb_props)
	// {
	// 	d->obj_list[j] = convert_prop_to_obj(d, &d->props[i]);
	// 	d->props[i++].obj_ref = &d->obj_list[j++];
	// }
	// i = 0;
	// while (i < d->nb_mob)
	// {
	// 	d->obj_list[j] = convert_mob_to_obj(d, &d->mobs[i]);
	// 	d->mobs[i++].obj_ref = &d->obj_list[j++];
	// }
}

void del_obj(t_obj *obj_list, int *nb_obj, t_obj *obj)
{
	int i;

	i = 0;
	while (i < *nb_obj)
		if (&obj_list[i++] == obj)
			break;
	i--;
	while (++i < *nb_obj)
		obj_list[i - 1] = obj_list[i];
	(*nb_obj)--;
}
#include "proto_global.h"
#include "proto_global.h"
#include "proto_global.h"
#include "proto_global.h"

t_mob	add_mob_demon(t_data *d, SDL_Point pos)
{
	t_mob mob;

	mob.life = DEMON_PV;
	mob.dmg_per_hit = DEMON_ATTACK;
	mob.attack_speed = DEMON_ATTACK_SPEED;
	mob.attack_dist = DEMON_ATTACK_RANGE;
	mob.speed = DEMON_MOVE_SPEED;
	mob.aggro_range = DEMON_AGGRO_RANGE;
	mob.size = DEMON_SIZE;
	mob.pos.x = (float)pos.x / UNIT;
	mob.pos.y = (float)pos.y / UNIT;
	mob.z_pos = 10;
	mob.z_size = 1;
	return (mob);
}

t_props	add_prop_key(t_data *d, SDL_Point pos)
{
	t_props prop;

	prop.pos.x = (float)pos.x / UNIT;
	prop.pos.y = (float)pos.y / UNIT;
	prop.size = KEY_SIZE;
	prop.collectable = KEY_COLLECTABLE;
	prop.can_collide = 0;
	prop.id = KEY_ITEM_ID;
	prop.text = &d->img[IMG_KEY];
	prop.z_pos = 10;
	return (prop);
}

void load_icons(t_data *d, t_map_data *map)
{
	int i;
	int nb_prop;
	int nb_mob;
	t_icon	*current;

	i = 0;
	nb_mob = 0;
	nb_prop = 0;
	while (i < map->icon_count)
	{
		current = &map->icon_list[i];
		if (current->id_ref == DEMON_ICON_ID)
			d->mobs[nb_mob++] = add_mob_demon(d, current->pos_i);
		if (current->id_ref == KEY_ICON_ID)
			d->props[nb_prop++] = add_prop_key(d, current->pos_i);
		i++;
	}
	d->nb_mob = nb_mob;
	d->nb_props = nb_prop;
}
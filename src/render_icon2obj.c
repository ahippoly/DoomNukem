#include "global_header.h"
#include "render.h"
#include "editor.h"
#include "img_file.h"

t_mob	add_mob_demon(t_data *d, SDL_Point pos)
{
	t_mob mob;

	mob.life = DEMON_PV;
	mob.damage = DEMON_ATTACK;
	mob.attack_speed = DEMON_ATTACK_SPEED;
	mob.range = DEMON_ATTACK_RANGE;
	mob.speed = DEMON_MOVE_SPEED;
	mob.aggro_range = DEMON_AGGRO_RANGE;
	mob.size = DEMON_SIZE;
	mob.pos.x = (float)pos.x / UNIT;
	mob.pos.y = (float)pos.y / UNIT;
	mob.z_pos = 2;
	mob.z_size = 1;
	return (mob);
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
		i++;
	}
	d->nb_mob = nb_mob;
	d->nb_props = nb_prop;
}
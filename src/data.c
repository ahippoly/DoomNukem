#include "proto_global.h"

/* Fichier de malloc pour data.h */

/* malloc tableau d'img, nb nombre d'entrée du tableau */
t_img			*malloc_img(int size)
{
	t_img		*img;

	if (!(img = (t_img *)ft_memalloc(sizeof(t_img) * (size + 1))))
		return (NULL);
	return (img);
}

FMOD_SOUND		**malloc_fmod_sound_tab(int size)
{
	int			i;
	FMOD_SOUND	**sound;

	if (!(sound = (FMOD_SOUND **)ft_memalloc(sizeof(FMOD_SOUND *) * (size + 1))))
		return (NULL);
	return (sound);
}

FMOD_SOUND		*malloc_fmod_sound(int size)
{
	int			i;
	FMOD_SOUND	*sound;

	if (!(sound = (FMOD_SOUND *)ft_memalloc(sizeof(FMOD_SOUND) * (size + 1))))
		return (NULL);
	return (sound);
}

t_ssprite		*malloc_ssprite(int size)
{
	t_ssprite	*sprite;

	if (!(sprite = (t_ssprite *)ft_memalloc(sizeof(t_ssprite) * (size + 1))))
		return (NULL);
	return (sprite);
}

t_floor			*malloc_floor(int size)
{
	t_floor		*floor;

	if (!(floor = (t_floor *)ft_memalloc(sizeof(t_floor) * (size + 1))))
		return (NULL);
	return (floor);
}

t_floor			**malloc_floor_tab(int size)
{
	t_floor		**floor;
	int			i;

	if (!(floor = (t_floor **)ft_memalloc(sizeof(t_floor *) * (size + 1))))
		return (NULL);
	return (floor);
}

t_props			*malloc_props(int size)
{
	t_props		*prop;

	if (!(prop = (t_props *)ft_memalloc(sizeof(t_props) * (size + 1))))
		return (NULL);
	return (prop);
}

t_mob			*malloc_mob(int size)
{
	t_mob		*mob;

	if (!(mob = (t_mob *)ft_memalloc(sizeof(t_mob) * (size + 1))))
		return (NULL);
	return (mob);
}

t_obj			*malloc_obj(int size)
{
	t_obj		*obj;

	if (!(obj = (t_obj *)ft_memalloc(sizeof(t_obj) * (size + 1))))
		return (NULL);
	return (obj);
}

t_obj			**malloc_obj_tab(int size)
{
	t_obj		**obj;

	if (!(obj = (t_obj **)ft_memalloc(sizeof(t_obj*) * (size + 1))))
		return (NULL);
	return (obj);
}

t_sprite		*malloc_sprite(int size)
{
	t_sprite	*sprite;

	if (!(sprite = (t_sprite *)ft_memalloc(sizeof(t_sprite) * (size + 1))))
		return (NULL);
	return (sprite);
}

#include "global_header.h"
#include "render.h"
#include "editor.h"
#include "img_file.h"

// void create_raybox(t_data *d, t_props *prop, t_rot rot_calc)
// {
// 	prop->p1.x = prop->pos.x - prop->size * rot_calc.sin_rot;
// 	prop->p1.y = prop->pos.y - prop->size * rot_calc.cos_rot;
// 	prop->p2.x = prop->pos.x + prop->size * rot_calc.sin_rot;
// 	prop->p2.y = prop->pos.y + prop->size * rot_calc.cos_rot;
// }

// void create_props_raybox(t_data *d)
// {
// 	int i;

// 	i = 0;
// 	while (i < d->nb_props)
// 	{
// 		create_raybox(d, &d->props[i++], d->rot_calc);
// 	}
// }

t_range	calc_prop_draw_range(t_data *d, float dist, float height, float size)
{
	t_range	res;

	res.start = d->screen_height - ((height - d->player_height + size) * WIN_SIZE_Y) / dist;
	res.end = d->screen_height + ((d->player_height - height + size)  * WIN_SIZE_Y) / dist;
	return (res);
}

void draw_prop_slice(t_data *d, t_props *prop, t_ray ray, int x)
{
	t_range draw_y;
	int tx;
	unsigned int *pixels;
	float		th;
	float		th_step;

	draw_y = calc_prop_draw_range(d, ray.dist, prop->z_pos, prop->size);
	tx = ray.scale * prop->text->w;
	pixels = prop->text->pixels;
	th_step = prop->text->h / (draw_y.end - draw_y.start);
	th = 0;
	if (draw_y.start < 0)
	{
		th = -draw_y.start * th_step;
		draw_y.start = 0;
	}
	draw_y.end = ft_min(draw_y.end, WIN_SIZE_Y);
	while (draw_y.start < draw_y.end)
	{
		d->p_screen[x + draw_y.start] = pixels[tx + (int)th * prop->text->w];
		th += th_step;
		draw_y.start++;
	}
}

void cast_prop(t_data *d, t_props *prop)
{

}
#include "proto_global.h"
#include "proto_global.h"
#include "proto_global.h"
#include "proto_global.h"

void put_p(unsigned int *addr, unsigned int color, float alpha)
{
	*addr = color;
}

void put_p_alpha(unsigned int *addr, unsigned int color, float alpha)
{
	*addr = calc_transparency2(*addr, color, alpha);
}

void draw_text_slice(unsigned int *pixels, t_draw range, t_obj obj, t_ray ray)
{
	float ty_step;
	float ty;
	int		tx;
	int		p_cord;
	void	(*put_pix)(unsigned int*, unsigned int, float);

	tx = ray.mod_scale * obj.w;
	ty_step = (float)obj.h * (ray.z_text) / (range.end_y - range.start_y);
	ty = (1 - get_float_part(ray.z_height.pos + ray.z_height.size - obj.z_text_offset)) * obj.h;
	if (range.start_y < 0)
	{
		ty += ty_step * -range.start_y;
		range.start_y = 0;
	}
	range.start_y *= WIN_SIZE_X;
	range.end_y *= WIN_SIZE_X;
	range.end_y = ft_min(range.end_y, WIN_SIZE_Y * WIN_SIZE_X);
	//printf("range x = %i\n", range.start_x);
	p_cord = range.start_x + range.start_y;
	if (obj.alpha < 0.001)
		put_pix = &put_p;
	else
		put_pix = &put_p_alpha;
	while (p_cord < range.end_y)
	{
		while (ty > obj.h - INTER_TOLERANCE)
			ty -= obj.h;
		if (ty < 0)
			printf("ty neg : %f\n", ty);
		if (p_cord >= WIN_SIZE_X * WIN_SIZE_Y)
			printf("pos screen : %i,%i\n", range.start_x, (p_cord - range.start_x) / WIN_SIZE_X);
		if (tx + (int)ty * obj.w >= obj.h * obj.w)
			printf("t : %i,%f, obj-wh %d,%d\n", tx, ty, obj.w, obj.h);
		//pixels[p_cord] = obj.pixels[tx + (int)ty * obj.w];
		(*put_pix)(&pixels[p_cord], obj.pixels[tx + (int)ty * obj.w], obj.alpha);
		//pixels[p_cord] = calc_transparency2(pixels[p_cord], obj.pixels[tx + (int)ty * obj.w], obj.alpha);
		//calc_transparency(&pixels[p_cord], &obj.pixels[tx + (int)ty * obj.w], obj.alpha);
		ty += ty_step;
		p_cord += WIN_SIZE_X;
	}
}

t_draw	calc_ray_draw_range(t_data *d, t_ray ray, int x)
{
	t_draw	draw;


	draw.start_x = x;
	draw.end_x = x;

	// draw.start_y = d->screen_height - ((z_height.end - d->player_height) * WIN_SIZE_Y) / ray->dist;
	// draw.end_y = d->screen_height + ((d->player_height - z_height.start)  * WIN_SIZE_Y) / ray->dist;
	// draw.start_y = d->screen_height - ((z_height.pos - d->player_height) * WIN_SIZE_Y) / ray.dist;
	// draw.end_y = (draw.start_y + (z_height.size * WIN_SIZE_Y) / ray.dist);

	draw.start_y = d->screen_height - ((ray.z_height.pos + ray.z_height.size - d->player_height) * WIN_SIZE_Y) / ray.dist;
	draw.end_y = (draw.start_y + (ray.z_height.size * WIN_SIZE_Y) / ray.dist);
	draw.step_y = WIN_SIZE_X;

	// printf("ray draw range : x : %i,%i, y : %i,%i\n", draw.start_x, draw.end_x, draw.start_y, draw.end_y);
	return (draw);
}

// void draw_ray_simple(t_data *d, t_ray ray, t_draw draw, t_obj *obj)
// {
// 	float ty;
// 	float ty_step;
// 	t_img *text;


// 	text = &obj->text;
// 	ty_step = (float)text->h / (draw.end_y - draw.start_y + 1);
// 	draw.start_y = ft_max(draw.start_y, 0);
// 	draw.end_y = ft_min(draw.end_y, WIN_SIZE_Y);
// 	ty = 0;
// 	while (draw.start_y < draw.end_y)
// 	{
// 		// d->p_screen[draw.start_x + draw.start_y * WIN_SIZE_X] = 0xFFBBAADD;
// 		d->p_screen[draw.start_x + draw.start_y * WIN_SIZE_X] = obj->text.pixels[(int)(ray.mod_scale * text->w) + (int)(ty) * text->w];
// 		ty += ty_step;
// 		draw.start_y += 1;
// 	}
// }

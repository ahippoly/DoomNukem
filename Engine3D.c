/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Engine3D.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 01:19:12 by ahippoly          #+#    #+#             */
/*   Updated: 2019/10/18 17:33:14 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_vox create_vox(double x, double y, double z)
{
	t_vox vox;

	vox.x = x;
	vox.y = y;
	vox.z = z;
	return (vox);
}

t_point	vox_on_screen(t_vox point, t_vox cam_pos, t_pos cam_rot)
{
	t_vox		diff;
	double		depth;
	t_point		screen_pos;
	t_pos		sin_rot;
	t_pos		cos_rot;

	sin_rot.x = sin(cam_rot.x * M_PI_2);
	sin_rot.y = sin(cam_rot.y * M_PI_2);
	cos_rot.x = cos(cam_rot.x * M_PI_2);
	cos_rot.y = cos(cam_rot.y * M_PI_2);

	diff.x = point.x - cam_pos.x;
	diff.y = point.y - cam_pos.y;
	diff.z = point.z - cam_pos.z;

	depth = diff.x * sin_rot.y * sin_rot.x + diff.y * cos_rot.y * sin_rot.x + diff.z * cos_rot.x;
	depth *= 0.5;
	screen_pos.x = (diff.y * sin_rot.y - diff.x * cos_rot.y + depth) * WIN_SIZE / (depth * 2);
	screen_pos.y = (diff.z * sin_rot.x - diff.x * cos_rot.x * sin_rot.y - diff.y * cos_rot.x * cos_rot.y + depth) * WIN_SIZE / (depth * 2);

	//printf("vox_on_screen depth = %f\n", depth);
	if (depth < 0)
		screen_pos.x = -42;
	screen_pos.zdist = depth;
	return (screen_pos);
}

void line_intersect(t_vox cam_pos, t_pos cam_rot, t_vox *p1, t_vox *p2, t_line *line)
{
	double sin_rot;
	double cos_rot;
	double a1;
	double a2;
	double b1;
	double b2;
	t_pos inter;

//	t_vox p1;
//	t_vox p2;

//	p1.x = 1;
//	p1.y = 0;
//	p1.z = 0;

//	p2.x = 1;
//	p2.y = 1;
//	p2.z = 0;
	if ((line->pos1.x == -42 || line->pos2.x == -42)
		&& !(line->pos1.x == -42 && line->pos2.x == -42))
	{
		sin_rot = sin((cam_rot.y) * M_PI_2);
		cos_rot = cos((cam_rot.y) * M_PI_2);
		printf("Intersect needed\n");
		//line->text_ratio = 0;
		if (sin_rot < 0.001 && sin_rot > -0.001)
		{
			printf("case : sin_rot = 0\n");
			a1 = (p2->y - p1->y) / (p2->x - p1->x);
			b1 = p1->y - p1->x * a1;
			inter.x = cam_pos.x;
			inter.y = a1 * inter.x + b1;
			printf("inter.x = %f, max x = %f, min x = %f\n", inter.x, ft_fmax(p2->x, p1->x), ft_fmin(p2->x, p1->x));
			if (inter.x > ft_fmax(p2->x, p1->x) || inter.x < ft_fmin(p2->x, p1->x))
			{
				inter.x = - 42;
				inter.y = - 42;
			}
			// else
			// 	line->text_ratio = inter.x / p2->x;
		}
		else if (p2->x - p1->x != 0)
		{
			a1 = (p2->y - p1->y) / (p2->x - p1->x);
			b1 = p1->y - p1->x * a1;
			
			a2 = cos_rot / sin_rot;
			b2 = cam_pos.y - cam_pos.x * a2;
			
			inter.x = (b2 - b1) / (a1  - a2);
			printf("inter.x = %f, max x = %f, min x = %f\n", inter.x, ft_fmax(p2->x, p1->x), ft_fmin(p2->x, p1->x));
			if (inter.x > ft_fmax(p1->x, p2->x) || inter.x < ft_fmin(p1->x, p2->x))
			{
				inter.x = - 42;
				inter.y = - 42;
			}
			else
			{
				inter.y = a1 * inter.x + b1;
				// line->text_ratio = inter.x / p2->x;
			}
		}
		else 
		{
			a2 = cos_rot / sin_rot;
			b2 = cam_pos.y - cam_pos.x * a2;
			inter.x = p1->x;
			inter.y = a2 * inter.x + b2;
			printf("inter.y = %f, max x = %f, min x = %f\n", inter.y, ft_fmax(p2->y, p1->y), ft_fmin(p2->y, p1->y));
			if (inter.y > ft_max(p2->y, p1->y) || inter.y < ft_min(p2->y, p1->y))
			{
				inter.x = - 42;
				inter.y = - 42;
			}
			else
			{
				// line->text_ratio = inter.y / p2->y;
			}
			
		}
		if (line->pos1.x == -42 && inter.x != -42)
		{
			p1->x = inter.x;
			p1->y = inter.y;
		}
		else if (line->pos2.x == -42 && inter.x != -42)
		{
			p2->x = inter.x;
			p2->y = inter.y;
		}
/*	printf("a1 = %f, b1 = %f\na2 = %f, b2 = %f\n",a1, b1, a2, b2);
	printf("sin_rot = %f, cos_rot = %f\n", sin_rot, cos_rot);
	printf("inter.x = %f, inter.y = %f\n", inter.x, inter.y);
	printf("line.text_ratio = %f\n",line->text_ratio);
*/	}
}

t_point segment_intersect(t_point p1, t_point p2, t_point p3, t_point p4)
{
    double a1;
    double a2;
    double b1;
    double b2;
    t_point inter;

    if (p2.x - p1.x != 0 && p4.x - p3.x != 0)
    {
        a1 = (double)(p2.y - p1.y) / (p2.x - p1.x);
        b1 = p1.y - (double)p1.x * a1;

        a2 = (double)(p4.y - p3.y) / (p4.x - p3.x);
        b2 = p3.y - (double)p3.x * a2;

        inter.x = (double)(b2 - b1) / (a1  - a2);
        if (inter.x > ft_max(p1.x, p2.x) || inter.x < ft_min(p1.x, p2.x))
        {
            inter.x = - 42;
            inter.y = - 42;
        }
        else
            inter.y = a1 * inter.x + b1;
    }
    else if (p4.x - p3.x != 0)
    {
        a2 = (double)(p4.y - p3.y) / (p4.x - p3.x);
        b2 = p3.y - (double)p3.x * a2;
        inter.x = p1.x;
        inter.y = a2 * inter.x + b2;
        if (inter.y > ft_max(p2.y, p1.y) || inter.y < ft_min(p2.y, p1.y))
        {
            inter.x = - 42;
            inter.y = - 42;
        }
    }
    else if (p2.x - p1.x != 0)
    {
        a1 = (double)(p2.y - p1.y) / (p2.x - p1.x);
        b1 = p1.y - (double)p1.x * a1;
        inter.x = p3.x;
        inter.y = a1 * inter.x + b1;
        if (inter.y > ft_max(p4.y, p3.y) || inter.y < ft_min(p4.y, p3.y))
        {
            inter.x = - 42;
            inter.y = - 42;
        }
    }
	else
    {
        inter.x = - 42;
        inter.y = - 42;
    }
    return (inter);
}

t_line create_3Dlines(t_vox cam_pos, t_pos cam_rot, t_vox p1, t_vox p2)
{
	double sin_rot;
	double cos_rot;
	double a1;
	double a2;
	double b1;
	double b2;
	t_line line;

//	t_vox p1;
//	t_vox p2;

//	p1.x = 1;
//	p1.y = 0;
//	p1.z = 0;

//	p2.x = 1;
//	p2.y = 1;
//	p2.z = 0;
	sin_rot = sin((cam_rot.y + 0.5) * M_PI_2);
	cos_rot = cos((cam_rot.y + 0.5) * M_PI_2);
	line.pos1 = vox_on_screen(p1, cam_pos, cam_rot);
	line.pos2 = vox_on_screen(p2, cam_pos, cam_rot);
	
	cam_rot.x += 0.5;
	cam_rot.y += 0.5;
	line_intersect(cam_pos, cam_rot, &p1, &p2, &line);
	cam_rot.x -= 0.5;
	cam_rot.y -= 0.5;
	if (line.pos1.x == -42)
		line.pos1 = vox_on_screen(p1, cam_pos, cam_rot);
	else if (line.pos2.x == -42)
		line.pos2 = vox_on_screen(p2, cam_pos, cam_rot);
	cam_rot.x -= 0.5;
	cam_rot.y -= 0.5;
	
	line_intersect(cam_pos, cam_rot, &p1, &p2, &line);
	cam_rot.x += 0.5;
	cam_rot.y += 0.5;
	if (line.pos1.x == -42)
		line.pos1 = vox_on_screen(p1, cam_pos, cam_rot);
	else if (line.pos2.x == -42)
		line.pos2 = vox_on_screen(p2, cam_pos, cam_rot);
		
/*	printf("a1 = %f, b1 = %f\na2 = %f, b2 = %f\n",a1, b1, a2, b2);
	printf("sin_rot = %f, cos_rot = %f\n", sin_rot, cos_rot);
	printf("inter.x = %f, inter.y = %f\n", inter.x, inter.y);
	printf("line.text_ratio = %f\n",line.text_ratio);
*/	return (line);
}

//t_vox cut_frustum(t_vox cam_pos, t_pos cam_rot, t_vox p1, t_vox p2)
t_vox cut_frustum(t_vox cam_pos, t_pos cam_rot)
{
	t_pos scale;
	t_pos sin_rot;
	t_pos cos_rot;
	t_pos cam_dir;
	t_vox intersect;

	t_vox p1;
	t_vox p2;
	double divid;

	p1.x = 2;
	p1.y = 1;
	p1.z = 0;

	p2.x = 4;
	p2.y = 1;
	p2.z = 0;

	sin_rot.y = sin(cam_rot.y * M_PI_2);
	cos_rot.y = cos(cam_rot.y * M_PI_2);

	cam_dir.x = cam_pos.x + sin_rot.y * 1;
	cam_dir.y = cam_pos.y + cos_rot.y * 1;

	scale.x = ((p2.x - p1.x) * (cam_pos.y - p1.y) - (p2.y - p1.y) * (cam_pos.x - p1.x)) /
		((p2.y - p1.y) * (cam_dir.x - cam_pos.x) - (p2.x - p1.x) * (cam_dir.y - cam_pos.y));
	scale.y = ((cam_dir.x - cam_pos.x) * (cam_pos.y - p1.y) - (cam_dir.y - cam_pos.y) * (cam_pos.x * p1.x)) /
		((p2.y - p1.y) * (cam_dir.x - cam_pos.x) - (p2.x - p1.x) * (cam_dir.y - cam_pos.y));

	//scale.y = (cam_dir.x - cam_pos.x) * (cam_pos.y - p1.y) - (cam_dir.y - cam_pos.y) * (cam_pos.x * p1.x);
	//divid = (p2.y - p1.y) * (cam_dir.x - cam_pos.x) - (p2.x - p1.x) * (cam_dir.y - cam_pos.y);
	printf("sin_rot = %f, cos_rot = %f\n",sin_rot.y, cos_rot.y);
	printf("cam_dir.x = %f, cam_dir.y = %f\n", cam_dir.x, cam_dir.y);
	printf("scale.x = %f, scale.y = %f\n", scale.x, scale.y);
	printf("divid = %f\n", divid);
	return (intersect);
}

/*
t_vox cut_frustum_naze(t_vox cam_pos, t_pos cam_rot, t_vox p1, t_vox p2)
{
	SDL_Rect line;
	t_pos cos_rot;
	t_pos sin_rot;
	t_pos step;

	cos_rot.y = cos(cam_rot.y * M_PI_2);
	sin_rot.y = sin(cam_rot.y * M_PI_2);

	line.x = p1.x;
	line.y = pi.y;
	line.w = p2.x - p1.x;
	line.h = p2.x - p1.x;

	step.x = sin_rot / cos_rot;
	step.y = cos_rot / sin_rot;
}
*/
t_line create_line(t_point pos1, t_point pos2)
{
	t_line line;

	//line.text_ratio = 0;
	line.pos1.x = pos1.x;
	line.pos1.y = pos1.y;
	line.pos2.x = pos2.x;
	line.pos2.y = pos2.y;
	return (line);
}

t_line create_line_sdl(SDL_Point pos1, SDL_Point pos2)
{
	t_line line;

	//line.text_ratio = 0;
	line.pos1.x = pos1.x;
	line.pos1.y = pos1.y;
	line.pos2.x = pos2.x;
	line.pos2.y = pos2.y;
	return (line);
}

void draw_texture(t_line top, t_line bot, char *pixels, t_text *text)
{
	int i;
	double j;
	double step;
	double step_text;
	int length[2];
	t_point *line[2];
	int longer;
	double start_y_ratio;
	double end_y_ratio;
	t_disp_range ra;

	line[0] = mem_octant(top.pos1, top.pos2, &length[0], 0);
	line[1] = mem_octant(bot.pos1, bot.pos2, &length[1], 0);
	printf("top start pos : x1 = %d, y1 = %d, x2 = %d, y2 = %d \n", top.pos1.x, top.pos1.y, top.pos2.x, top.pos2.y);
	printf("bot start pos : x1 = %d, y1 = %d, x2 = %d, y2 = %d \n", bot.pos1.x, bot.pos1.y, bot.pos2.x, bot.pos2.y);
	if (length[0] != 0 && length[1] != 0)
	{
		if (length[0] > length[1])
		{
			step = (double)length[1] / length[0];
			step_text = text->w / length[0];
			longer = 0;
		}
		else
		{
			longer = 1;
			step = (double)length[0] / length[1];
			step_text = text->w / length[1];
		}
		
		i = 0;
		j = 0;
		//printf("texture pos : pos1 : x = %d, y = %d, pos2 : x = %d, y = %d\n", line[longer][i].x, line[longer][i].y, line[1 - longer][i].x, line[1 - longer][i].y);
		while (i < length[longer])
		{
			end_y_ratio = 0;
			start_y_ratio = 0;
		/*	if (line[longer][i].y > WIN_SIZE)
			{
				end_y_ratio = (double)(line[longer][i].y - WIN_SIZE) / WIN_SIZE;
				line[longer][i].y = WIN_SIZE;
			}
			if (line[longer][i].y < 0)
			{
				start_y_ratio = (double)-line[longer][i].y / WIN_SIZE;
				line[longer][i].y = 0;
			}
			//printf("start_y_ratio = %f, end_y_ratio = %f\n", start_y_ratio, end_y_ratio);
			if (line[1 - longer][(int)j].y > WIN_SIZE)
				line[1 - longer][(int)j].y = WIN_SIZE;
			if (line[1 - longer][(int)j].y < 0)
				line[1 - longer][(int)j].y = 0;
			*/
			if (line[longer][i].x < WIN_SIZE)
			{
				bresenham_texture(create_line(line[longer][i], line[1 - longer][(int)j]), pixels, text, (double)i / length[longer], ra);
			}
			j += step;
			i++;
		}
	}
	free(line[0]);
	free(line[1]);
}

void swap_triangle_point(t_point *p1, t_point *p2)
{
	t_point tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

t_point set_point_text_ratio(t_point p, double ratio_x, double ratio_y)
{
	if (ratio_x != -1)
		p.text_ratio.x = ratio_x;
	if (ratio_y != -1)
		p.text_ratio.y = ratio_y;
	return (p);
}

void put_pixel_attempt(unsigned int *p_tab, t_point pos, int color)
{
	if (pos.x > 0 && pos.x < WIN_SIZE
		&& pos.y > 0 && pos.y < WIN_SIZE)
	{
		p_tab[pos.x + pos.y * WIN_SIZE] = color;
	}
}

void draw_sub_rectangle(t_point point[4], char *pixels, t_text *text)
{
	unsigned int *p_tab;
	unsigned int *text_pix;
	t_point *line[2];
	int drawed_length[2];
	int length[2];
	int i;
	int j;
	int scan_length;
	double step_x;
	double step_y;
	t_pos line_text_ratio_step[2];
	t_pos current_text_ratio[2];
	t_pos correct_text_ratio[2];
	t_pos scan_ratio;
	int left_line;
	int out_of_screen_bot;
	double ratio;
	double ratio_step;

	p_tab = (unsigned int*)pixels;
	text_pix = (unsigned int*)text->pixels;
	if (point[1].x < point[0].x)
		swap_triangle_point(&point[1], &point[0]);
	if (point[3].x < point[2].x)
		swap_triangle_point(&point[3], &point[2]);
	
	line[0] = mem_octant(point[0], point[2], &drawed_length[0], -1);
	line[1] = mem_octant(point[1], point[3], &drawed_length[1], -1);
	length[0] = ft_abs(point[2].y - point[0].y);
	length[1] = ft_abs(point[3].y - point[1].y);
	// printf("DrawSubTriangle\n");
	// printf(" length0 = %d, length1 = %d\n", length[0], length[1]);
	line_text_ratio_step[0].x = (point[2].text_ratio.x - point[0].text_ratio.x) / length[0];
	line_text_ratio_step[0].y = (point[2].text_ratio.y - point[0].text_ratio.y) / length[0];
	line_text_ratio_step[1].x = (point[3].text_ratio.x - point[1].text_ratio.x) / length[1];
	line_text_ratio_step[1].y = (point[3].text_ratio.y - point[1].text_ratio.y) / length[1];
	current_text_ratio[0].x = point[0].text_ratio.x;
	current_text_ratio[0].y = point[0].text_ratio.y;
	current_text_ratio[1].x = point[1].text_ratio.x;
	current_text_ratio[1].y = point[1].text_ratio.y;

	// if (point[0].y < 0)
	// {
	// 	current_text_ratio[0].x += line_text_ratio_step[0].x * -point[0].y;
	// 	current_text_ratio[0].y += line_text_ratio_step[0].y * -point[0].y;
	// }
	// if (point[0].y > WIN_SIZE)
	// {
	// 	out_of_screen_bot = point[0].y - WIN_SIZE;
	// 	current_text_ratio[0].x += line_text_ratio_step[0].x * out_of_screen_bot;
	// 	current_text_ratio[0].y += line_text_ratio_step[0].y * out_of_screen_bot;
	// }
	// if (point[1].y < 0)
	// {
	// 	current_text_ratio[1].x += line_text_ratio_step[1].x * -point[0].y;
	// 	current_text_ratio[1].y += line_text_ratio_step[1].y * -point[0].y;
	// }
	// if (point[1].y > WIN_SIZE)
	// {
	// 	out_of_screen_bot = point[1].y - WIN_SIZE;
	// 	current_text_ratio[1].x += line_text_ratio_step[1].x * out_of_screen_bot;
	// 	current_text_ratio[1].y += line_text_ratio_step[1].y * out_of_screen_bot;
	// }
	
	
	// if (point[1].y < 0)
	// {
	// 	current_text_ratio[0].x += line_text_ratio_step[0].x * -point[1].y;
	// 	current_text_ratio[0].y += line_text_ratio_step[0].y * -point[1].y;
	// }
	// if (point[2].y < 0)
	// {
	// 	current_text_ratio[1].x += line_text_ratio_step[1].x * -point[2].y;
	// 	current_text_ratio[1].y += line_text_ratio_step[1].y * -point[2].y;
	// }

	i = 0;

	// if (point[2].y > point[0].y)
	// {
	// 	if (point[2].y >= WIN_SIZE)
	// 		length[1] -= point[2].y - WIN_SIZE;
	// }
	// else if (point[0].y >= WIN_SIZE)
	// {
	// 	i += point[0].y - WIN_SIZE;
	// }
	
	while (i < drawed_length[1])
	{
		current_text_ratio[0].x += line_text_ratio_step[0].x;
		current_text_ratio[0].y += line_text_ratio_step[0].y;
		current_text_ratio[1].x += line_text_ratio_step[1].x;
		current_text_ratio[1].y += line_text_ratio_step[1].y;
		//printf(" Current_ratio0 : x = %f, y = %f | Current_ratio1 : x = %f, y = %f\n", current_text_ratio[0].x, current_text_ratio[0].y, current_text_ratio[1].x, current_text_ratio[1].y);
		scan_length = line[1][i].x - line[0][i].x;
		scan_ratio.x = current_text_ratio[0].x;
		scan_ratio.y = current_text_ratio[0].y;
		step_x = (current_text_ratio[1].x - current_text_ratio[0].x) / scan_length;
		step_y = (current_text_ratio[1].y - current_text_ratio[0].y) / scan_length;
		//printf(" scan_ratio before : x = %f, y = %f\n", scan_ratio.x, scan_ratio.y);
		//printf(" scan_length = %d\n", scan_length);
		j = 0;
		if (line[0][i].x < 0)
		{
			j = -line[0][i].x;
			scan_ratio.x += step_x * j;
			scan_ratio.y += step_y * j;
			//printf("j = %d\n",j);
		}
		if (line[1][i].x > WIN_SIZE)
			scan_length -= line[1][i].x - WIN_SIZE;
		
		while (j < scan_length)
		{
			
			
			put_pixel_attempt(p_tab, create_point(line[0][i].x + j, line[0][i].y, 0), text_pix[(int)(ft_frange(scan_ratio.x, 0, 1) * text->w) + ((int)(ft_frange(scan_ratio.y, 0, 1) * text->h) * text->w)]);
			//p_tab[(line[0][i].x + j) + (line[0][i].y * WIN_SIZE)] = text_pix[(int)(scan_ratio.x * text->w) + ((int)(scan_ratio.y * text->h) * text->w)];
			//p_tab[(line[0][i].x + j) + (line[0][i].y * WIN_SIZE)] = 0xffffffff;
			//p_tab[(line[0][i].x + j) + (line[0][i].y * WIN_SIZE)] = 0xff000000 | ((int)(scan_ratio.y * 65536) & 0xff00ff00) | (int)(scan_ratio.x * 256);
			scan_ratio.x += step_x;
			scan_ratio.y += step_y;
			j++;
		}
		//printf(" scan_ratio after : x = %f, y = %f\n", scan_ratio.x, scan_ratio.y);
		//printf(" pixel from text : x = %d, y = %d\n", (int)(scan_ratio.x * text->w), (int)(scan_ratio.y * text->h * text->w));
		i++;
	}
	free(line[0]);
	free(line[1]);
}

int read_text_pix(t_pos text_ratio, t_text *text)
{
	unsigned int *text_pix;

	text_pix = (unsigned int *)text->pixels;
	text_ratio.x = ft_frange(text_ratio.x, 0, 1);
	text_ratio.y = ft_frange(text_ratio.y, 0, 1);
	return (text_pix[(int)(text_ratio.x * text->w) + (int)(text_ratio.y * text->h) * text->w]);
}

void draw_scanline(t_point start, t_point end, unsigned int *p_tab, t_text *text)
{
	int i;
	int scan_length;
	t_pos text_step;
	t_pos correct_text;
	double ratio;
	double ratio_step;
	
	scan_length = end.x - start.x;
	text_step.x = (end.text_ratio.x - start.text_ratio.x) / scan_length;
	text_step.y = (end.text_ratio.y - start.text_ratio.y) / scan_length;
	i = 0;
	if (start.x < 0)
	{
		i = -start.x;
		start.text_ratio.x += i * text_step.x;
		start.text_ratio.y += i * text_step.y;
		start.x = 0;
	}
	if (end.x > WIN_SIZE)
		scan_length -= (end.x - WIN_SIZE);
	if (scan_length > 0)
	{
	ratio = 0;
	ratio_step = (double)1 / scan_length;
	while (i < scan_length)
	{
		start.x++;
		//printf("START_ZDIST = %f, END_ZDIST = %f\n",start.zdist, end.zdist);
		correct_text.x = ((((double)1 - ratio) * start.text_ratio.x / start.zdist) + (ratio * end.text_ratio.x / end.zdist)) / (((double)1 - ratio) / start.zdist + ratio / end.zdist);
		correct_text.y = ((((double)1 - ratio) * start.text_ratio.y / start.zdist) + (ratio * end.text_ratio.y / end.zdist)) / (((double)1 - ratio) / start.zdist + ratio / end.zdist);
		// printf("ratio = %f, startzdist = %f, endzdist = %f\n", ratio, start.zdist, end.zdist);
		// printf("correct_text.x = %f, correct_text.y = %f\n",correct_text.x , correct_text.y);
		//printf("ratio = %f, 1-ratio = %f\n", ratio, 1- ratio);
		put_pixel_attempt(p_tab, start, read_text_pix(correct_text, text));
		// start.text_ratio.x += text_step.x;
		// start.text_ratio.y += text_step.y;
		//put_pixel_attempt(p_tab, start, 0xffffffff);
		ratio += ratio_step;
		i++;
	}
	}
}

void draw_sub_triangle(t_point point[3], char *pixels, t_text *text)
{
	unsigned int *p_tab;
	unsigned int *text_pix;
	t_point *line[2];
	int drawed_length[2];
	int draw_length;
	int length[2];
	int i;
	int is_toptobot;
	t_pos line_text_ratio_step[2];
	t_pos current_text_ratio[2];
	t_pos base_text_ratio[2];
	t_pos correct_text_ratio[2];
	t_pos correct_text;
	double zdist[2];
	double base_zdist[2];
	double zdist_step[2];
	double scan_zdist;
	double scan_zdist_step;
	t_pos scan_ratio;
	t_pos ratio;
	t_pos ratio_step;

	p_tab = (unsigned int*)pixels;
	text_pix = (unsigned int*)text->pixels;
	if (point[2].x < point[1].x)
		swap_triangle_point(&point[2], &point[1]);
	is_toptobot = 0;
	if (point[0].y < point[2].y)
		is_toptobot = 1;
	line[0] = mem_octant(point[0], point[1], &drawed_length[0], 2);
	line[1] = mem_octant(point[0], point[2], &drawed_length[1], 2);
	printf("draw_length: 1 = %d, 2 = %d\n", drawed_length[0], drawed_length[1]);
	length[0] = ft_abs(point[1].y - point[0].y);
	length[1] = ft_abs(point[2].y - point[0].y);
	// printf("DrawSubTriangle\n");
	// printf(" length0 = %d, length1 = %d\n", length[0], length[1]);
	line_text_ratio_step[0].x = (point[1].text_ratio.x - point[0].text_ratio.x) / length[0];
	line_text_ratio_step[0].y = (point[1].text_ratio.y - point[0].text_ratio.y) / length[0];
	line_text_ratio_step[1].x = (point[2].text_ratio.x - point[0].text_ratio.x) / length[1];
	line_text_ratio_step[1].y = (point[2].text_ratio.y - point[0].text_ratio.y) / length[1];
	current_text_ratio[0].x = point[0].text_ratio.x;
	current_text_ratio[0].y = point[0].text_ratio.y;
	current_text_ratio[1].x = point[0].text_ratio.x;
	current_text_ratio[1].y = point[0].text_ratio.y;
	zdist[0] = point[1].zdist;
	zdist[1] = point[2].zdist;
	base_zdist[0] = zdist[0];
	base_zdist[1] = zdist[1];
	zdist_step[0] = (point[1].zdist - zdist[0]) / length[0];
	zdist_step[1] = (point[2].zdist - zdist[0]) / length[1];

	base_text_ratio[0].x = point[0].text_ratio.x;
	base_text_ratio[0].y = point[0].text_ratio.y;
	base_text_ratio[1].x = point[0].text_ratio.x;
	base_text_ratio[1].y = point[0].text_ratio.y;
	i = 0;
	draw_length = ft_min(drawed_length[0], drawed_length[1]);
	//printf("draw_length = %i\n", draw_length);
	if (is_toptobot == 0)
	{
		ratio.y = 0;
		ratio_step.y = (double)1 / draw_length;
	}
	else
	{
		ratio.y = 1;
		ratio_step.y = (double)-1 / draw_length;
	}
	
	
	while (i < draw_length)
	{
		// line[0][i].zdist = ((double)1 - ratio.y) * point[1].zdist + ratio.y / ((((double)1 - ratio.y) / point[1].zdist + ratio.y / (point[0].zdist)));
		// line[1][i].zdist = ((double)1 - ratio.y) * point[2].zdist + ratio.y / ((((double)1 - ratio.y) / point[2].zdist + ratio.y / (point[0].zdist)));
		line[0][i].zdist = (double)1 / ((double)1 / point[1].zdist + ((double)1 / point[0].zdist - (double)1 / point[1].zdist) * ratio.y );
		line[1][i].zdist = (double)1 / ((double)1 / point[2].zdist + ((double)1 / point[0].zdist - (double)1 / point[2].zdist) * ratio.y );
		line[0][i].text_ratio.x = current_text_ratio[0].x;
		line[0][i].text_ratio.y = current_text_ratio[0].y;
		line[1][i].text_ratio.x = current_text_ratio[1].x;
		line[1][i].text_ratio.y = current_text_ratio[1].y;
		// printf("zdist : 0 = %f, 1 = %f, 2 = %f\n", point[0].zdist, point[1].zdist, point[2].zdist);
		// printf("Before scanline : ratioy = %f, startzdist = %f, endzdist = %f\n",ratio.y, line[0][i].zdist, line[1][i].zdist);
		draw_scanline(line[0][i], line[1][i], p_tab, text);
		current_text_ratio[0].x += line_text_ratio_step[0].x;
		current_text_ratio[0].y += line_text_ratio_step[0].y;
		current_text_ratio[1].x += line_text_ratio_step[1].x;
		current_text_ratio[1].y += line_text_ratio_step[1].y;
		ratio.y += ratio_step.y;
		i++;
	}
	free(line[0]);
	free(line[1]);
}

void sort_point_by_height(t_point point[3])
{
	if (point[0].y > point[1].y)
		swap_triangle_point(&point[0], &point[1]);
	if (point[0].y > point[2].y)
		swap_triangle_point(&point[0], &point[2]);
	if (point[1].y > point[2].y)
		swap_triangle_point(&point[1], &point[2]);
}

void	sort_rectangle_point_by_height(t_point point[4])
{
    int     i;

    i = 0;
    while (i < 3)
    {
        if (point[i].y > point[i + 1].y)
        {
            swap_triangle_point(&point[i], &point[i + 1]);
            i = -1;
        }
        i++;
    }
}

void print_triangle(t_point point[3], char *name)
{
	printf("Print Triangle : %s\n", name);
	printf(" point 1 : x = %d, y = %d\n", point[0].x, point[0].y);
	printf(" point 2 : x = %d, y = %d\n", point[1].x, point[1].y);
	printf(" point 3 : x = %d, y = %d\n", point[2].x, point[2].y);
}

void print_rectangle(t_point point[3], char *name)
{
	printf("Print Triangle : %s\n", name);
	printf(" point 1 : x = %d, y = %d\n", point[0].x, point[0].y);
	printf(" point 2 : x = %d, y = %d\n", point[1].x, point[1].y);
	printf(" point 3 : x = %d, y = %d\n", point[2].x, point[2].y);
}

void create_sub_triangle(t_point original[3], t_point sub[3], int is_topside)
{
	double coef_ratio;
	double tmp;
	double zdist[2];

	if (is_topside == 1)
	{
		sub[0] = original[0];
		sub[1] = original[1];
		sub[2] = original[2];
	}
	else
	{
		sub[0] = original[2];
		sub[1] = original[1];
		sub[2] = original[0];
	}
	if (sub[0].zdist > sub[2].zdist)
	{
		zdist[0] = sub[2].zdist;
		zdist[1] = sub[0].zdist;
	}
	else
	{
		zdist[0] = sub[0].zdist;
		zdist[1] = sub[2].zdist;
	}
	
	// printf("CreateSubTriangle\n");
	// printf("Is topside = %d\n",is_topside);
	// printf(" zdist origin: 2 = %f, 0 = %f\n", sub[2].zdist, sub[0].zdist);
	coef_ratio = ((double)sub[2].y - sub[1].y) / (sub[2].y - sub[0].y); 

	sub[2].text_ratio.x += (sub[0].text_ratio.x - sub[2].text_ratio.x) * coef_ratio;
	sub[2].text_ratio.y += (sub[0].text_ratio.y - sub[2].text_ratio.y) * coef_ratio;
	sub[2].y = sub[1].y;
	sub[2].x += coef_ratio * (sub[0].x - sub[2].x);



	if (is_topside == 1)
		coef_ratio = 1 - coef_ratio;
	//sub[2].zdist = ((1 - coef_ratio) * zdist[0]) + coef_ratio / (((1 - coef_ratio) / zdist[0] + coef_ratio / zdist[1]));
	sub[2].zdist = (double)1 / (((double)1 - coef_ratio) / zdist[0] + coef_ratio / zdist[1]);

	// printf(" coef_ratio = %f\n", coef_ratio);
	// printf(" adapted point : x = %d, y = %d\n", sub[2].x, sub[2].y);
	printf(" zdist adapted = %f\n", sub[2].zdist);
	// printf(" text_ratio : x = %f, y = %f\n", sub[2].text_ratio.x, sub[2].text_ratio.y);
}

void draw_triangle(t_point point[3], char *pixels, t_text *text)
{
	t_point	sub_triangle_top[3];
	t_point	sub_triangle_bot[3];

	sort_point_by_height(point);
	//printf("\n Top point : x = %d, y = %d\n Middle : x = %d, y = %d\n Bot : x = %d, y = %d\n", point[0].x, point[0].y, point[1].x, point[1].y, point[2].x, point[2].y);
	create_sub_triangle(point, sub_triangle_top, 1);
	create_sub_triangle(point, sub_triangle_bot, 0);
	// print_triangle(sub_triangle_top, "TopTriangle");
	// print_triangle(sub_triangle_bot, "BotTriangle");
	draw_sub_triangle(sub_triangle_top, pixels, text);
	draw_sub_triangle(sub_triangle_bot, pixels, text);
}

void draw_textured_triangle(t_point begin, t_point corner, t_point end, int side, t_text *text, char *pixels)
{
	unsigned int		*p_tab;
	t_point				*begin_corner;
	t_point				*corner_end;
	t_point				*begin_end;
	int					begin_corner_l;
	int					corner_end_l;
	int 				begin_end_l;
	SDL_Point			*lowest_point;
	t_point	point[3];
	t_point	sub_triangle_top[3];
	t_point	sub_triangle_bot[3];
	//SDL_Point			point[3];
	//t_pos				text_ratio[3];

	//printf("TRIANGLE :\n beg : x = %d, y = %d\n corner : x = %d, y = %d\n end : x = %d, y = %d\n", begin.x,begin.y, corner.x, corner.y, end.x, end.y);
	point[0] = begin;
	point[0].text_ratio.x = 0;
	point[0].text_ratio.y = 0;
	point[1] = corner;
	if (side == 0)
	{
		point[1].text_ratio.x = 1;
		point[1].text_ratio.y = 0;
	}
	else
	{
		point[1].text_ratio.x = 0;
		point[1].text_ratio.y = 1;
	}
	
	point[2] = end;
	point[2].text_ratio.x = 1;
	point[2].text_ratio.y = 1;

	draw_triangle(point, pixels, text);
}

void draw_textured_rectangle(t_line top, t_line bot, t_text *text, char *pixels)
{
	t_line tl_br;
	t_line bl_tr;

	t_point center;
	t_point point[4][3];
	
	//draw_textured_triangle(top.pos1, top.pos2, bot.pos2, 0, text, pixels);
	//draw_textured_triangle(top.pos1, bot.pos1, bot.pos2, 1, text, pixels);
	printf("Rectangle point : \n x = %d, y = %d\n x2 = %d, y2 = %d\n x3 = %d y3 = %d\n x4 = %d y4 = %d\n", top.pos1.x, top.pos1.y, top.pos2.x, top.pos2.y, bot.pos1.x, bot.pos1.y, bot.pos2.x, bot.pos2.y);

	center = segment_intersect(top.pos1, bot.pos2, bot.pos1, top.pos2);
	point[0][0] = top.pos1;
	point[0][1] = center;
	point[0][2] = top.pos2;
	point[0][0].text_ratio.x = 0;
	point[0][0].text_ratio.y = 0;
	point[0][1].text_ratio.x = 0.5;
	point[0][1].text_ratio.y = 0.5;
	point[0][2].text_ratio.x = 1;
	point[0][2].text_ratio.y = 0;

	point[1][0] = top.pos1;
	point[1][1] = center;
	point[1][2] = bot.pos1;
	point[1][0].text_ratio.x = 0;
	point[1][0].text_ratio.y = 0;
	point[1][1].text_ratio.x = 0.5;
	point[1][1].text_ratio.y = 0.5;
	point[1][2].text_ratio.x = 0;
	point[1][2].text_ratio.y = 1;

	point[2][0] = bot.pos1;
	point[2][1] = center;
	point[2][2] = bot.pos2;
	point[2][0].text_ratio.x = 0;
	point[2][0].text_ratio.y = 1;
	point[2][1].text_ratio.x = 0.5;
	point[2][1].text_ratio.y = 0.5;
	point[2][2].text_ratio.x = 1;
	point[2][2].text_ratio.y = 1;

	point[3][0] = top.pos2;
	point[3][1] = center;
	point[3][2] = bot.pos2;
	point[3][0].text_ratio.x = 1;
	point[3][0].text_ratio.y = 0;
	point[3][1].text_ratio.x = 0.5;
	point[3][1].text_ratio.y = 0.5;
	point[3][2].text_ratio.x = 1;
	point[3][2].text_ratio.y = 1;

	draw_triangle(point[0], pixels, text);
	draw_triangle(point[1], pixels, text);
	draw_triangle(point[2], pixels, text);
	draw_triangle(point[3], pixels, text);

	//draw_textured_triangle(top.pos1, top.pos2, bot.pos2, 0, text, pixels);
	//draw_textured_triangle(top.pos1, bot.pos1, bot.pos2, 1, text, pixels);
}

void draw_textured_rectangle2(t_line top, t_line bot, t_text *text, char *pixels)
{
	t_point point[3][3];
	t_point middle_bot;

	printf("Rectangle point : \n x = %d, y = %d\n x2 = %d, y2 = %d\n x3 = %d y3 = %d\n x4 = %d y4 = %d\n", top.pos1.x, top.pos1.y, top.pos2.x, top.pos2.y, bot.pos1.x, bot.pos1.y, bot.pos2.x, bot.pos2.y);
	if (top.pos1.x != -42
	&& top.pos2.x != -42
	&& bot.pos1.x != -42
	&& bot.pos2.x != -42)
	{
		middle_bot.x = (bot.pos1.x + bot.pos2.x) / 2;
		middle_bot.y = (bot.pos1.y + bot.pos2.y) / 2;
		point[0][0] = top.pos1;
		point[0][1] = middle_bot;
		point[0][2] = bot.pos1;
		point[0][0].text_ratio.x = 0;
		point[0][0].text_ratio.y = 0;
		point[0][1].text_ratio.x = 0.5;
		point[0][1].text_ratio.y = 1;
		point[0][2].text_ratio.x = 0;
		point[0][2].text_ratio.y = 1;

		point[1][0] = top.pos1;
		point[1][1] = middle_bot;
		point[1][2] = top.pos2;
		point[1][0].text_ratio.x = 0;
		point[1][0].text_ratio.y = 0;
		point[1][1].text_ratio.x = 0.5;
		point[1][1].text_ratio.y = 1;
		point[1][2].text_ratio.x = 1;
		point[1][2].text_ratio.y = 0;

		point[2][0] = top.pos2;
		point[2][1] = middle_bot;
		point[2][2] = bot.pos2;
		point[2][0].text_ratio.x = 1;
		point[2][0].text_ratio.y = 0;
		point[2][1].text_ratio.x = 0.5;
		point[2][1].text_ratio.y = 1;
		point[2][2].text_ratio.x = 1;
		point[2][2].text_ratio.y = 1;

		draw_triangle(point[0], pixels, text);
		draw_triangle(point[1], pixels, text);
		draw_triangle(point[2], pixels, text);
	}
}

void draw_textured_rectangle3(t_line top, t_line bot, t_text *text, char *pixels)
{
	t_point point[2][3];

	point[0][0] = top.pos1;
	point[0][1] = top.pos2;
	point[0][2] = bot.pos2;
	point[0][0].text_ratio.x = 0;
	point[0][0].text_ratio.y = 0;
	point[0][1].text_ratio.x = 1;
	point[0][1].text_ratio.y = 0;
	point[0][2].text_ratio.x = 1;
	point[0][2].text_ratio.y = 1;

	point[1][0] = top.pos1;
	point[1][1] = bot.pos1;
	point[1][2] = bot.pos2;
	point[1][0].text_ratio.x = 0;
	point[1][0].text_ratio.y = 0;
	point[1][1].text_ratio.x = 0;
	point[1][1].text_ratio.y = 1;
	point[1][2].text_ratio.x = 1;
	point[1][2].text_ratio.y = 1;

	draw_triangle(point[0], pixels, text);
	draw_triangle(point[1], pixels, text);
}

// void draw_rectangle(t_point point[4], char *pixels, t_text *text)
// {
// 	t_point	sub_triangle_top[3];
// 	t_point	sub_triangle_bot[3];

// 	sort_point_by_height(point);
// 	// printf("\n Top point : x = %d, y = %d\n Middle : x = %d, y = %d\n Bot : x = %d, y = %d\n", point[0].x, point[0].y, point[1].x, point[1].y, point[2].x, point[2].y);
// 	create_sub_triangle(point, sub_triangle_top, 1);
// 	create_sub_triangle(point, sub_triangle_bot, 0);
// 	draw_sub_triangle(sub_triangle_top, pixels, text);
// 	draw_sub_triangle(sub_triangle_bot, pixels, text);
// }

void draw_textured_rectangle4(t_line top, t_line bot, t_text *text, char *pixels)
{
	t_point point[2][3];

	point[0][0] = top.pos1;
	point[0][1] = top.pos2;
	point[0][2] = bot.pos2;
	point[0][0].text_ratio.x = 0;
	point[0][0].text_ratio.y = 0;
	point[0][1].text_ratio.x = 1;
	point[0][1].text_ratio.y = 0;
	point[0][2].text_ratio.x = 1;
	point[0][2].text_ratio.y = 1;

	point[1][0] = top.pos1;
	point[1][1] = bot.pos1;
	point[1][2] = bot.pos2;
	point[1][0].text_ratio.x = 0;
	point[1][0].text_ratio.y = 0;
	point[1][1].text_ratio.x = 0;
	point[1][1].text_ratio.y = 1;
	point[1][2].text_ratio.x = 1;
	point[1][2].text_ratio.y = 1;

	printf("zdist : 1 = %f, 2 = %f, 3 = %f, 4 = %f\n", top.pos1.zdist, top.pos2.zdist, bot.pos1.zdist, bot.pos2.zdist);

	draw_triangle(point[0], pixels, text);
	draw_triangle(point[1], pixels, text);
}
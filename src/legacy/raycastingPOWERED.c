/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 05:02:25 by ahippoly          #+#    #+#             */
/*   Updated: 2019/10/18 18:08:58 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
t_point load_corner(t_var *v, int i, int j, int h)
{
	SDL_Point pos;
	SDL_Point size;
	SDL_Point pos2;
	SDL_Point size2;
	SDL_Point win_size;
	t_vox diff;
	double width;
	double depth;
	double startx;
	double starty;
	double diffy_screenpos;
	double diffx_screenpos;
	SDL_Point endray;
    SDL_Point startray;
    SDL_Point perso_pos;
	t_point ret;
	int half_screen;
	double rot;
	double roty;
	double sin_rot;
	double cos_rot;
	double sin_roty;
	double cos_roty;

	size.x = 3;
	size.y = 3;
	pos2.x = 0;
	pos2.y = 0;
	size2.x = 2;
	size2.y = 90;

	ret.x = -42;
	ret.y = 0;
	if (i == -42 && j == -42)
		return (ret);

	pos.x = i * MINI_MAP_W / (v->map_size.x) +  MINI_MAP_X;
	pos.y = j * MINI_MAP_H / (v->map_size.y) +  MINI_MAP_Y;

	rot = v->rot * M_PI_2;
	roty = v->roty * M_PI_2;

	sin_rot = sin(rot);
	sin_roty = sin(roty);
	cos_rot = cos(rot);
	cos_roty = cos(roty);

	half_screen = WIN_SIZE / 2;

	diff.x = i - v->perso_pos.x;
	diff.y = j - v->perso_pos.y;
	diff.z = h - v->perso_pos.z;
	depth = diff.x * sin_rot * sin_roty + diff.y * cos_rot * sin_roty + diff.z * cos_roty;
	depth *= v->fov;
	 *cos(M_PI_4); 
	 *sin(v->fov); 
	 *v->fov;
//	diffy_screenpos = diff.y * sin(rot) - diff.x * cos(rot);
	diffx_screenpos = diff.y * sin_rot 
		//+ diff.x * cos(rot) * cos(roty) 
		- diff.x * cos_rot;
	diffy_screenpos = diff.z * sin_roty - diff.x * cos_roty * sin_rot - diff.y * cos_roty * cos_rot;
	width = depth * 2;
		* sin(M_PI_4);
		* sin(v->fov); 
		* v->fov;
	startx = diffx_screenpos + depth;
	starty = diffy_screenpos + depth;
	printf("i = %i, j = %i\n",i , j);
	printf("posx =  %i , posy = %i, posz =  %i \n",pos.x, pos.y,h);
	printf("diffx = %f, diffy = %f, diffz = %f\n",diff.x, diff.y, diff.z);
//	printf("diffx_distance = %f\n", diffx_distance);
	printf("diffy_screenpos = %f\n", diffy_screenpos);
//              printf("diff_layer calc = %f\n",  sin( M_PI_2));
	printf("depth = %f, width = %f\n", depth,  width);
//	printf("         dist2 = %f, width2 = %f\n", depth * cos(v->fov * M_PI_2),width2);
	printf("startx = %f, starty = %f\n", startx, starty);
*/
//	printf("start = %f\n", diffx_distance);
/*	endray.x =  pos.x + 100 * cos((v->rot) * M_PI_2);
	endray.y =  pos.y + 100 * -sin((v->rot) * M_PI_2);
	startray.x =  pos.x + 100 * -cos((v->rot) * M_PI_2);
	startray.y =  pos.y + 100 * sin((v->rot) * M_PI_2);
	octant(startray, endray, v->p_tab, 0xff00aa00);

//////////////////////////////////////////////////////  Display CALC

	//if (startx > 0 && startx < width && starty > 0 && starty < width)
	{
		ret.x = startx * WIN_SIZE / width;
		//pos2.y = WIN_SIZE / 2 - 200 / (diffx_distance * 0.5);
		//size2.y = 300 / (diffx_distance * 0.5);
		ret.y = starty * WIN_SIZE / width;
//		put_rect(v->p_tab, pos2, size2, 0xffffffff, v->win_size);
//		put_rect(v->p_tab, pos, size, 0xffffffff, v->win_size);
	}
	if (depth < 0)
	{
		ret.x = -42;
		ret.y = -42;
	}
	ret.zdist = depth;
	return (ret);
}
*/

void draw_line(t_var *v, t_line line, int color)
{
	octant(line.pos1, line.pos2, v->p_tab, color, 0);
}

void load_cube_lines(t_var *v, int x, int y, int z, t_vox cam_pos, t_pos cam_rot)
{
	draw_line(v, create_3Dlines(cam_pos, cam_rot, create_vox(x, y, z), create_vox(x + 1, y, z)), 0xffaaffcc);
	draw_line(v, create_3Dlines(cam_pos, cam_rot, create_vox(x + 1, y, z), create_vox(x + 1, y + 1, z)), 0xffaaffcc);
	draw_line(v, create_3Dlines(cam_pos, cam_rot, create_vox(x, y + 1, z), create_vox(x + 1, y + 1, z)), 0xffaaffcc);
	draw_line(v, create_3Dlines(cam_pos, cam_rot, create_vox(x, y, z), create_vox(x, y + 1, z)), 0xffaaffcc);

// draw_texture(create_3Dlines(cam_pos, cam_rot, create_vox(x, y, z), create_vox(x + 1, y, z))
// , create_3Dlines(cam_pos, cam_rot, create_vox(x, y + 1, z), create_vox(x + 1, y + 1, z))
// , v->p_tab, &v->stone);

draw_textured_rectangle4(create_3Dlines(cam_pos, cam_rot, create_vox(x, y, z), create_vox(x + 1, y, z))
, create_3Dlines(cam_pos, cam_rot, create_vox(x, y + 1, z), create_vox(x + 1, y + 1, z))
, &v->stone, v->p_tab);

// draw_texture(create_3Dlines(cam_pos, cam_rot, create_vox(x, y, z), create_vox(x + 1, y, z))
// , create_3Dlines(cam_pos, cam_rot, create_vox(x, y, z + 1), create_vox(x + 1, y, z + 1))
// , v->p_tab, &v->stone);

// draw_textured_rectangle4(create_3Dlines(cam_pos, cam_rot, create_vox(x, y, z), create_vox(x + 1, y, z))
//  , create_3Dlines(cam_pos, cam_rot, create_vox(x, y, z + 1), create_vox(x + 1, y, z + 1))
//  , &v->stone, v->p_tab);

	draw_line(v, create_3Dlines(cam_pos, cam_rot, create_vox(x, y, z), create_vox(x, y, z + 1)), 0xffaabbcc);
	draw_line(v, create_3Dlines(cam_pos, cam_rot, create_vox(x + 1, y, z), create_vox(x + 1, y, z + 1)), 0xffaabbcc);
	draw_line(v, create_3Dlines(cam_pos, cam_rot, create_vox(x + 1, y + 1, z), create_vox(x + 1, y + 1, z + 1)), 0xffaabbcc);
	draw_line(v, create_3Dlines(cam_pos, cam_rot, create_vox(x, y + 1, z), create_vox(x, y + 1, z + 1)), 0xffaabbcc);

	draw_line(v, create_3Dlines(cam_pos, cam_rot, create_vox(x, y, z + 1), create_vox(x + 1, y, z + 1)), 0xffaabbcc);
	draw_line(v, create_3Dlines(cam_pos, cam_rot, create_vox(x + 1, y, z + 1), create_vox(x + 1, y + 1, z + 1)), 0xffaabbcc);
	draw_line(v, create_3Dlines(cam_pos, cam_rot, create_vox(x + 1, y + 1, z + 1), create_vox(x, y + 1, z + 1)), 0xffaabbcc);
	draw_line(v, create_3Dlines(cam_pos, cam_rot, create_vox(x, y, z + 1), create_vox(x, y + 1, z + 1)), 0xffaabbcc);
}

/*
void load_cube_plane(t_var *v, int x, int y, int z, t_point corner[4])
{
	SDL_Point point;
	SDL_Point point2;
	t_line top;
	t_line bot;
	t_vox pos3d;
	t_pos cam_rot;
	t_vox pt1;
	t_vox pt2;
	t_line inter;

	pt1.x = x;
	pt1.y = y;
	pt1.z = z;

	cam_rot.x = v->roty;
	cam_rot.y = v->rot;

	//corner[0] = vox_on_screen(pos3d, v->perso_pos, cam_rot);
	corner[0] = load_corner(v, x , y , z );
	corner[1] = load_corner(v, x + 1, y , z);
	corner[2] = load_corner(v, x , y + 1 , z);
	corner[3] = load_corner(v, x + 1, y + 1 , z);

	//printf("YES 1\n");
	top.pos1 = corner[0];
	top.pos2 = corner[1];
	bot.pos1 = corner[2];
	bot.pos2 = corner[3];

	pt2.x = x;
	pt2.y = y + 1;
	pt2.z = z;
	printf("pt1: x = %f, y = %f, z = %f\n",pt1.x,pt1.y,pt1.z);
	//disp_text(v->p_tab, v->img_tab, v->img_size);
	//draw_texture(top, bot, v->p_tab, &v->stone);
	inter.pos1 = corner[0];
	inter.pos2 = corner[1];
	line_intersect(v->perso_pos, cam_rot, &pt1, &pt2, &inter);
	corner[0] = inter.pos1;
	corner[1] = inter.pos2;
	octant(corner[0], corner[1], v->p_tab, 0xff00ffff, 0);
	octant(corner[0], corner[2], v->p_tab, 0xff00ffff, 0);
	octant(corner[1], corner[3], v->p_tab, 0xff00ffff, 0);	
	octant(corner[2], corner[3], v->p_tab, 0xff00ffff, 0);
}
*/

/*
void load_cube_point(t_var *v, int x, int y, int z)
{
	t_point upcorner[4];
	t_point downcorner[4];
	t_point point;
	t_point point2;
	int i;
	int j;
	int h;

	load_cube_plane(v, x, y, z, upcorner);
	load_cube_plane(v, x, y, z - 1, downcorner);
	
	t_line top;
    t_line bot;

	top.pos1 = upcorner[0];
    top.pos2 = upcorner[1];
    bot.pos1 = downcorner[0];
    bot.pos2 = downcorner[1];

	//draw_texture(top, bot, v->p_tab, &v->stone);

	octant(downcorner[0], upcorner[0], v->p_tab, 0xff00ffff, 0);
	octant(downcorner[1], upcorner[1], v->p_tab, 0xff00ffff, 0);
	octant(downcorner[2], upcorner[2], v->p_tab, 0xff00ffff, 0);	
	octant(downcorner[3], upcorner[3], v->p_tab, 0xff00ffff, 0);
}
*/
void load_wall(t_var *v)
{
	int x;
	int y;
	int z;
	t_point point;
	t_line wall_hight_tmp;
	t_line wall_hight;
	t_line wall_hight2;
	t_pos cam_rot;
	cam_rot.x = v->roty;
	cam_rot.y = v->rot;

	x = 0;
	while (x < v->map_size.x)
	{
		y = 0;
		while (y < v->map_size.y)
		{
			z = 0;
			while (z < v->map_size.z)
			{
			//printf("i = %i , j = %i\n",i,j);
				if (v->map[x][y][z] != 0)
				{
					//printf("i = %i , j = %i, map = %i , Id = %i , height = %i\n",i,j, v->map[j][i], v->map[j][i] / 100, v->map[j][i] % 100);
					// if (v->map[x][y][z] < 5 && v->map[x][y][z] > 1) //load triangle
					// 	load_triangle_point(v, x, y, -z, v->map[x][y][z]);
					// else
						//load_cube_point(v, x, y, -z);
						load_cube_lines(v, x, y, z, v->perso_pos, cam_rot);
				}
				z++;
			}
			y++;
		}
		x++;
	}
}

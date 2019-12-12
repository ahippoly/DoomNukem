/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 05:02:25 by ahippoly          #+#    #+#             */
/*   Updated: 2019/09/14 01:18:26 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

SDL_Point load_corner(t_var *v, int i, int j, int h)
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
	SDL_Point ret;
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

	ret.x = -10000;
	ret.y = 0;

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
	//* cos(M_PI_4); 
	//* sin(v->fov); 
	//* v->fov;
//	diffy_screenpos = diff.y * sin(rot) - diff.x * cos(rot);
	diffx_screenpos = diff.y * sin_rot 
		//+ diff.x * cos(rot) * cos(roty) 
		- diff.x * cos_rot;
	diffy_screenpos = diff.z * sin_roty - diff.x * cos_roty * sin_rot - diff.y * cos_roty * cos_rot;
	width = depth * 2;
		//* sin(M_PI_4);
		//* sin(v->fov); 
		//* v->fov;
	startx = diffx_screenpos + depth;
	starty = diffy_screenpos + depth;
/*	printf("i = %i, j = %i\n",i , j);
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
*/
//////////////////////////////////////////////////////  Display CALC

	if (startx > 0 && startx < width && starty > 0 && starty < width)
	{
		pos2.x = startx * WIN_SIZE / width;
		//pos2.y = WIN_SIZE / 2 - 200 / (diffx_distance * 0.5);
		//size2.y = 300 / (diffx_distance * 0.5);
		pos2.y = starty * WIN_SIZE / width;
		ret.x = pos2.x;
		ret.y = pos2.y;
//		put_rect(v->p_tab, pos2, size2, 0xffffffff, v->win_size);
//		put_rect(v->p_tab, pos, size, 0xffffffff, v->win_size);
	}
	return (ret);
}

void load_cube_plane(t_var *v, int x, int y, int z , SDL_Point corner[4])
{
	SDL_Point point;
	SDL_Point point2;

	corner[0] = load_corner(v, x , y , z);
	corner[1] = load_corner(v, x + 1, y , z);
	corner[2] = load_corner(v, x , y + 1 , z);
	corner[3] = load_corner(v, x + 1, y + 1 , z);

	octant(corner[0], corner[1], v->p_tab, 0xff00ffff);
	octant(corner[0], corner[2], v->p_tab, 0xff00ffff);
	octant(corner[1], corner[3], v->p_tab, 0xff00ffff);	
	octant(corner[2], corner[3], v->p_tab, 0xff00ffff);
}


void load_cube_point(t_var *v, int x, int y, int z)
{
	SDL_Point upcorner[4];
	SDL_Point downcorner[4];
	SDL_Point point;
	SDL_Point point2;
	int i;
	int j;
	int h;

	load_cube_plane(v, x, y, z, upcorner);
	load_cube_plane(v, x, y, z - 1, downcorner);
	
	octant(downcorner[0], upcorner[0], v->p_tab, 0xff00ffff);
	octant(downcorner[1], upcorner[1], v->p_tab, 0xff00ffff);
	octant(downcorner[2], upcorner[2], v->p_tab, 0xff00ffff);	
	octant(downcorner[3], upcorner[3], v->p_tab, 0xff00ffff);
}

void load_wall(t_var *v)
{
	int x;
	int y;
	int z;
	SDL_Point point;
	t_line wall_hight_tmp;
	t_line wall_hight;
	t_line wall_hight2;

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
					if (v->map[x][y][z] < 5 && v->map[x][y][z] > 1) //load triangle
						load_triangle_point( v, x, y, -z, v->map[x][y][z]);
					else
						load_cube_point( v, x, y, -z);
				}
				z++;
			}
			y++;
		}
		x++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 05:02:25 by ahippoly          #+#    #+#             */
/*   Updated: 2019/04/09 00:19:14 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_line load_corner(t_var *v, int i, int j, int h)
{
	SDL_Point pos;
	SDL_Point size;
	SDL_Point pos2;
	SDL_Point posz;
	SDL_Point size2;
	SDL_Point win_size;
	t_pos diff;
	t_pos diff2;
	double diff_z;
	double diff_z_down;
	double width;
	double width2;
	double width_z;
	double width_z_down;
	double depth;
	double depth_z;
	double depth_z_down;
	double start;
	double start_z;
	double start_z_down;
	double diffx_distance;
	double diffy_screenpos;
	double diffz_screenpos;
	double diffz_down_screenpos;
	SDL_Point endray;
    SDL_Point startray;
    SDL_Point perso_pos;
	t_line ret;
	int half_screen;

	size.x = 3;
	size.y = 3;
	pos2.x = 0;
	pos2.y = 0;
	size2.x = 2;
	size2.y = 90;

	ret.pos1.x = -10000;
	ret.pos2.x = 0;
	ret.pos1.y = 0;
	ret.pos2.y = 0;

	half_screen = WIN_SIZE / 2;

	diff.x = i - v->perso_pos.x;
	diff.y = j - v->perso_pos.y;
	diff_z = -v->z_pos + h;
	diff_z_down = -v->z_pos + h - 1;
	depth = (diff.x * sin((v->rot) * M_PI_2) + diff.y * cos((v->rot) * M_PI_2));
	depth_z = (diff.x * sin((v->roty) * M_PI_2) + diff_z * cos((v->roty) * M_PI_2));
	depth_z_down = (diff.x * sin((v->roty) * M_PI_2) + diff_z_down * cos((v->roty) * M_PI_2));
	diffx_distance = depth 
		//* cos(M_PI_4); 
		//* sin(v->fov); 
		* v->fov;
	diffy_screenpos = (diff.y * sin((v->rot) * M_PI_2)) - (diff.x * cos((v->rot) * M_PI_2));
	diffz_screenpos = (diff_z * sin((v->roty) * M_PI_2)) - (diff.x * cos((v->roty) * M_PI_2));
	diffz_down_screenpos = (diff_z_down * sin((v->roty) * M_PI_2)) - (diff.x * cos((v->roty) * M_PI_2));
	pos.x = i * MINI_MAP_W / (v->map_size.x) +  MINI_MAP_X;
	pos.y = j * MINI_MAP_H / (v->map_size.y) +  MINI_MAP_Y;
	width2 = depth * 2 * sin(v->fov * M_PI_2);
	width = depth * 2 
		//* sin(M_PI_4);
		//* sin(v->fov); 
		* v->fov;
	width_z = depth_z * 2;
	width_z_down = depth_z_down * 2;
	start = diffy_screenpos + diffx_distance;
	start_z = diffz_screenpos + depth_z;
	start_z_down = diffz_down_screenpos + depth_z_down;
	printf("i = %i, j = %i\n",i , j);
	printf("posx = %i , posy = %i\n",pos.x, pos.y);
	printf("map_h = %im , z_pos = %f\n",v->map[j][i] , v->z_pos);
	printf("diffx = %f, diffy = %f diff_z = %f\n",diff.x, diff.y,diff_z);
//	printf("diffx_distance = %f\n", diffx_distance);
	printf("diffy_screenpos = %f\n", diffy_screenpos);
	printf("diffz_screenpos = %f\n", diffz_screenpos);
//              printf("diff_layer calc = %f\n",  sin( M_PI_2));
	printf("diffx_distance = %f, width =    %f\n", diffx_distance, width);
	printf("depth_z = %f, width_z = %f\n", depth_z, width_z);
	printf("dist2   = %f, width2  = %f\n", depth * cos(v->fov * M_PI_2),width2);
	printf("start   = %f  start_z = %f\n", start,start_z);
	printf("startzdown   = %f  widthdown = %f\n", start_z_down,width_z_down);
//	printf("start = %f\n", diffx_distance);
/*	endray.x =  pos.x + 100 * cos((v->rot) * M_PI_2);
	endray.y =  pos.y + 100 * -sin((v->rot) * M_PI_2);
	startray.x =  pos.x + 100 * -cos((v->rot) * M_PI_2);
	startray.y =  pos.y + 100 * sin((v->rot) * M_PI_2);
	octant(startray, endray, v->p_tab, 0xff00aa00);
*/
////////////////////////////////////////////////////// Display CALC

	if (start > 0 && start < width )
	{
		pos2.x = start * WIN_SIZE / width;
		posz.x = pos2.x;
		//pos2.y = WIN_SIZE / 2 - 200 / (diffx_distance * 0.5);
		//size2.y = 300 / (diffx_distance * 0.5);
		pos2.y = start_z * WIN_SIZE / width_z;
		posz.y = start_z_down * WIN_SIZE / width_z_down;
		ret.pos1.x = pos2.x;
		ret.pos1.y = pos2.y;
		ret.pos2.x = pos2.x;
		ret.pos2.y = posz.y;
		octant(pos2, posz, v->p_tab, 0xffffffff);
		//put_rect(v->p_tab, pos2, size2, 0xffffffff, v->win_size);
		//put_rect(v->p_tab, pos, size, 0xffffffff, v->win_size);
	}
	return (ret);
}

void load_wall(t_var *v)
{
	int i;
	int j;
	t_line wall_hight_tmp;
	t_line wall_hight;
	t_line wall_hight2;

	i = 0;
	while (i < v->map_size.x)
	{
		j = 0;
		while (j < v->map_size.y)
		{
			//printf("i = %i , j = %i\n",i,j);
			if (v->map[j][i] > 0)
			{
				wall_hight = load_corner(v , i , j, v->map[j][i]);
				wall_hight_tmp = wall_hight;
				wall_hight2 = load_corner(v , i+1 , j, v->map[j][i]);
				if (wall_hight.pos1.x != -10000 && wall_hight2.pos1.x != -10000)
				{
					octant(wall_hight.pos1, wall_hight2.pos1, v->p_tab, 0xff00ffff);
					octant(wall_hight.pos2, wall_hight2.pos2, v->p_tab, 0xff00ffff);
				}
				wall_hight = load_corner(v , i+1 , j+1, v->map[j][i]);
				if (wall_hight.pos1.x != -10000 && wall_hight2.pos1.x != -10000)
				{
					octant(wall_hight.pos1, wall_hight2.pos1, v->p_tab, 0xff00ffff);
					octant(wall_hight.pos2, wall_hight2.pos2, v->p_tab, 0xff00ffff);
				}	
				wall_hight2 = load_corner(v , i , j+1, v->map[j][i]);
				if (wall_hight.pos1.x != -10000 && wall_hight2.pos1.x != -10000)
				{
					octant(wall_hight.pos1, wall_hight2.pos1, v->p_tab, 0xff00ffff);
					octant(wall_hight.pos2, wall_hight2.pos2, v->p_tab, 0xff00ffff);
				}
				if (wall_hight_tmp.pos1.x != -10000 && wall_hight2.pos1.x != -10000)
				{
					octant(wall_hight_tmp.pos1, wall_hight2.pos1, v->p_tab, 0xff00ffff);
					octant(wall_hight_tmp.pos2, wall_hight2.pos2, v->p_tab, 0xff00ffff);
				}
			}
			j++;
		}
		i++;
	}
}

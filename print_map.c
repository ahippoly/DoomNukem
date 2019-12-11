/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 14:58:26 by ahippoly          #+#    #+#             */
/*   Updated: 2019/04/14 19:13:04 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void put_border(char *p_tab, SDL_Point disp_size)
{
	SDL_Point pos;
	SDL_Point size;

	pos.x = 0;
	pos.y = 0;
	size.x = MINI_MAP_W;
	size.y = MINI_MAP_H;
	put_rect(p_tab, pos, size, 0xff0000ff, disp_size);
	pos.x = 2;
	pos.y = 2;
	size.x = MINI_MAP_W - 4;
	size.y = MINI_MAP_H - 4;
	put_rect(p_tab, pos, size, 0x00000000, disp_size);
}

void print_map(t_var *v)
{
	SDL_Rect disp_pos;
	SDL_Rect perso_pos;
	t_point endray;
	t_point startray;
	double rot;
	double roty;
	double fov;
	double rot_left;
	double rot_right;

	rot = v->rot * M_PI_2;
	roty = v->roty * M_PI_2;
	fov = v->fov * M_PI_4;
	rot_left = (v->rot - 0.5) * M_PI_2;
	rot_right = (v->rot + 0.5) * M_PI_2;
		
	disp_pos.x = MINI_MAP_X;
	disp_pos.y = MINI_MAP_Y;
	disp_pos.w = MINI_MAP_W;
	disp_pos.h = MINI_MAP_H;
	perso_pos.x = v->perso_pos.x * MINI_MAP_W / (v->map_size.x) + MINI_MAP_X;
	perso_pos.y = v->perso_pos.y * MINI_MAP_H / (v->map_size.y) + MINI_MAP_Y;
	perso_pos.w = PERSO;
	perso_pos.h = PERSO;
	bzero(v->p_tab, WIN_SIZE * WIN_SIZE * 4);
	load_wall(v);
/////////////////////// MINI_MAP FOV DISPLAY  ////////////////////////////////
	startray.x = perso_pos.x;
	startray.y = perso_pos.y;
	endray.x = perso_pos.x + 150 * sin(rot - fov) * sin(roty);
	endray.y = perso_pos.y + 150 * cos(rot - fov) ;
	octant(startray, endray, v->p_tab, 0xffff00ff, 0);
	endray.x = perso_pos.x + 150 * sin(rot + fov) * sin(roty);
	endray.y = perso_pos.y + 150 * cos(rot + fov) ;
//	endray.x = perso_pos.x + 150 * sin((v->rot + 0.5) * M_PI_2);// * cos((v->fov) * M_PI_2);
//	endray.y = perso_pos.y + 150 * cos((v->rot + 0.5) * M_PI_2) * sin((v->fov) * M_PI_2);
	octant(startray, endray, v->p_tab, 0xffff00ff, 0);
	endray.x = perso_pos.x + 100 * sin(rot) * sin(roty);
	endray.y = perso_pos.y + 100 * cos(rot);
	octant(startray, endray, v->p_tab, 0xff00ffff, 0);
	startray.x = perso_pos.x + 100 * sin(rot - fov) * sin(roty);
	startray.y = perso_pos.y + 100 * cos(rot - fov) ;
	endray.x = perso_pos.x + 100 * sin(rot + fov) * sin(roty);
	endray.y = perso_pos.y + 100 * cos(rot + fov) ;
//	startray.x = perso_pos.x + 100 * sin((v->rot - 0.5) * M_PI_2);// * cos((v->fov) * M_PI_2);
//	startray.y = perso_pos.y + 100 * cos((v->rot - 0.5) * M_PI_2) * sin((v->fov) * M_PI_2);
//	endray.x = perso_pos.x + 100 * sin((v->rot + 0.5) * M_PI_2);// * cos((v->fov) * M_PI_2);
//	endray.y = perso_pos.y + 100 * cos((v->rot + 0.5) * M_PI_2) * sin((v->fov) * M_PI_2);
	octant(startray, endray, v->p_tab, 0x0000ff00, 0);
	//SDL_RenderClear(v->rend);


/////////////////////////////////// MINI_MAP SIDE FOV DISPLAY  ////////////////////////////
	perso_pos.x = v->perso_pos.x * MINI_MAP_W / (v->map_size.x) + MINI_MAP_X;
	perso_pos.y = v->perso_pos.z * MINI_MAP_H / (v->map_size.y) + MINI_MAP_Y + 240;
	startray.x = perso_pos.x;
	startray.y = perso_pos.y;
	endray.x = perso_pos.x + 150 * sin(roty - fov) * sin(rot);
	endray.y = perso_pos.y + 150 * cos(roty - fov) ;
	octant(startray, endray, v->p_tab, 0xffff00ff, 0);
	endray.x = perso_pos.x + 150 * sin(roty + fov) * sin(rot);
	endray.y = perso_pos.y + 150 * cos(roty + fov) ;
//	endray.x = perso_pos.x + 150 * sin((v->rot + 0.5) * M_PI_2);// * cos((v->fov) * M_PI_2);
//	endray.y = perso_pos.y + 150 * cos((v->rot + 0.5) * M_PI_2) * sin((v->fov) * M_PI_2);
	octant(startray, endray, v->p_tab, 0xffff00ff, 0);
	endray.x = perso_pos.x + 100 * sin(roty) * sin(rot);
	endray.y = perso_pos.y + 100 * cos(roty);
	octant(startray, endray, v->p_tab, 0xff00ffff, 0);
	startray.x = perso_pos.x + 100 * sin(roty - fov) * sin(rot);
	startray.y = perso_pos.y + 100 * cos(roty - fov) ;
	endray.x = perso_pos.x + 100 * sin(roty + fov) * sin(rot);
	endray.y = perso_pos.y + 100 * cos(roty + fov) ;
//	startray.x = perso_pos.x + 100 * sin((v->rot - 0.5) * M_PI_2);// * cos((v->fov) * M_PI_2);
//	startray.y = perso_pos.y + 100 * cos((v->rot - 0.5) * M_PI_2) * sin((v->fov) * M_PI_2);
//	endray.x = perso_pos.x + 100 * sin((v->rot + 0.5) * M_PI_2);// * cos((v->fov) * M_PI_2);
//	endray.y = perso_pos.y + 100 * cos((v->rot + 0.5) * M_PI_2) * sin((v->fov) * M_PI_2);
	octant(startray, endray, v->p_tab, 0x0000ff00, 0);

/////////////////////////////////// MINI_MAP SIDE 2 FOV DISPLAY  ////////////////////////////
	perso_pos.x = v->perso_pos.y * MINI_MAP_W / (v->map_size.x) + MINI_MAP_X;
	perso_pos.y = v->perso_pos.z * MINI_MAP_H / (v->map_size.y) + MINI_MAP_Y + 440;
	startray.x = perso_pos.x;
	startray.y = perso_pos.y;
	endray.x = perso_pos.x + 150 * sin(roty - fov) * cos(rot);
	endray.y = perso_pos.y + 150 * cos(roty - fov) ;
	octant(startray, endray, v->p_tab, 0xffff00ff, 0);
	endray.x = perso_pos.x + 150 * sin(roty + fov) * cos(rot);
	endray.y = perso_pos.y + 150 * cos(roty + fov) ;
//	endray.x = perso_pos.x + 150 * sin((v->rot + 0.5) * M_PI_2);// * cos((v->fov) * M_PI_2);
//	endray.y = perso_pos.y + 150 * cos((v->rot + 0.5) * M_PI_2) * sin((v->fov) * M_PI_2);
	octant(startray, endray, v->p_tab, 0xffff00ff, 0);
	endray.x = perso_pos.x + 100 * sin(roty) * cos(rot) ;
	endray.y = perso_pos.y + 100 * cos(roty);
	octant(startray, endray, v->p_tab, 0xff00ffff, 0);
	startray.x = perso_pos.x + 100 * sin(roty - fov) * cos(rot);
	startray.y = perso_pos.y + 100 * cos(roty - fov) ;
	endray.x = perso_pos.x + 100 * sin(roty + fov) * cos(rot);
	endray.y = perso_pos.y + 100 * cos(roty + fov) ;
//	startray.x = perso_pos.x + 100 * sin((v->rot - 0.5) * M_PI_2);// * cos((v->fov) * M_PI_2);
//	startray.y = perso_pos.y + 100 * cos((v->rot - 0.5) * M_PI_2) * sin((v->fov) * M_PI_2);
//	endray.x = perso_pos.x + 100 * sin((v->rot + 0.5) * M_PI_2);// * cos((v->fov) * M_PI_2);
//	endray.y = perso_pos.y + 100 * cos((v->rot + 0.5) * M_PI_2) * sin((v->fov) * M_PI_2);
	octant(startray, endray, v->p_tab, 0x0000ff00, 0);


	SDL_UpdateTexture(v->screen, NULL, v->p_tab, WIN_SIZE*4);
	SDL_RenderCopy(v->rend, v->screen, NULL, NULL);
	SDL_RenderCopy(v->rend, v->mini_map_xy, NULL, &disp_pos);
	disp_pos.y = MINI_MAP_Y + 200;
	SDL_RenderCopy(v->rend, v->mini_map_xz, NULL, &disp_pos);
	disp_pos.y = MINI_MAP_Y + 400;
	SDL_RenderCopy(v->rend, v->mini_map_yz, NULL, &disp_pos);
/*	SDL_RenderCopy(v->rend, v->character, NULL, &perso_pos);
	perso_pos.x = v->perso_pos.y * MINI_MAP_W / (v->map_size.x) + MINI_MAP_X;
	perso_pos.y = v->perso_pos.z * MINI_MAP_H / (v->map_size.y) + MINI_MAP_Y + 440;
	SDL_RenderCopy(v->rend, v->character, NULL, &perso_pos);
	perso_pos.x = v->perso_pos.x * MINI_MAP_W / (v->map_size.x) + MINI_MAP_X;
	perso_pos.y = v->perso_pos.y * MINI_MAP_H / (v->map_size.y) + MINI_MAP_Y;
	SDL_RenderCopy(v->rend, v->character, NULL, &perso_pos);*/
	SDL_RenderPresent(v->rend);	
}

void print_side_view(t_var *v)
{

}

void perso_char_ini(t_var *v)
{
	int i;
	unsigned int *tab;

	tab = (unsigned int*)v->p_perso;
	i = 0;
	while (i < PERSO * PERSO)
		tab[i++] = 4294967295;
	SDL_UpdateTexture(v->character, NULL, v->p_perso, PERSO*4);
}
/*
void put_octant(SDL_Point step, SDL_Point pos, t_var *v)
{
	octant(pos, v->perso_pos, v->p_tab, 0xffff00ff);
	pos.x += step.x;
	octant(pos, v->perso_pos, v->p_tab, 0xffff00ff);
	pos.x -= step.x;
	pos.y += step.y;
	octant(pos, v->perso_pos, v->p_tab, 0xffff00ff);
	pos.x += step.x;
	octant(pos, v->perso_pos, v->p_tab, 0xffff00ff);
}
*/
void map_ini(char ***map, SDL_Point size, t_var *v)
{
	int x;
	int y;
	int z;
	SDL_Point pos;
	SDL_Point step;
	SDL_Point disp_size;
	SDL_Point tmp;
	char *p_tab;
	char *p_tab2;
	char *p_tab3;

	disp_size.x = MINI_MAP_W;
	disp_size.y = MINI_MAP_H;
	step.x = size.x / v->map_size.x;
	step.y = size.y / v->map_size.y;
	if (!(p_tab = (char*)malloc(sizeof(char) * MINI_MAP_H * MINI_MAP_W * 4)))
		exit(1);
	if (!(p_tab2 = (char*)malloc(sizeof(char) * MINI_MAP_H * MINI_MAP_W * 4)))
		exit(1);
	if (!(p_tab3 = (char*)malloc(sizeof(char) * MINI_MAP_H * MINI_MAP_W * 4)))
		exit(1);
	put_border(p_tab, disp_size);
	put_border(p_tab2, disp_size);
	put_border(p_tab3, disp_size);
	perso_char_ini(v);
	x = 0;
	while (x < v->map_size.x)
	{
		y = 0;
		while (y < v->map_size.y)
		{
			z = 0;
			while (z < v->map_size.z)
			{
				if (map[x][y][z] > 0)
				{
					//printf("x = %i, y = %i, z = %i, map[x][y][z] = %i\n", x, y, z, map[x][y][z]);
//put octant
					pos.x = x * step.x;
					pos.y = y * step.y;
					put_rect(p_tab, pos, step, 0xff0000ff, disp_size);
					pos.y = MINI_MAP_W - (z + 5)  * step.y;
					put_rect(p_tab2, pos, step, 0xff0000ff, disp_size);
					pos.x = x * step.x;
					put_rect(p_tab3, pos, step, 0xff0000ff, disp_size);
					//pos.x += MINI_MAP_X;
					//pos.y += MINI_MAP_Y;
					//put_octant(step, pos, v);
				}
				z++;
			}
			y++;
		}
		x++;
	}
	SDL_UpdateTexture(v->mini_map_xy, NULL, p_tab, MINI_MAP_W * 4);
	SDL_UpdateTexture(v->mini_map_xz, NULL, p_tab2, MINI_MAP_W * 4);
	SDL_UpdateTexture(v->mini_map_yz, NULL, p_tab3, MINI_MAP_W * 4);
	free(p_tab);
	free(p_tab2);
	free(p_tab3);
	print_map(v);
}

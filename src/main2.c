/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 23:51:11 by ahippoly          #+#    #+#             */
/*   Updated: 2019/10/17 17:53:23 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void draw_diag(int size, SDL_Texture *text)
{
	char *pixel_tab;
	int i;

	pixel_tab = (char*)malloc(size * size * 4);
	i = 0;
	while (i < size * 4)
	{
		pixel_tab[i * size  + i] = (char)255;
		pixel_tab[i * size  + i + 3] = (char)255;
		i += 4;
	}
	SDL_UpdateTexture(text,NULL,pixel_tab,size*4);
	free(pixel_tab);
}

void set_rect(SDL_Rect *size, int w, int h)
{
	size->x = 0;
	size->y = 0;
	size->w = w;
	size->h = h;
}

void ptab_ini(char *p_tab, int floor_h)
{
	int x;
	int y;

	x = 0;
	y = 0;

	while (y < WIN_SIZE / floor_h)
	{
		x = 0;
		while (x < WIN_SIZE)
		{
			p_tab[(y * WIN_SIZE + x) * 4] = (char)255;
			p_tab[(y * WIN_SIZE + x) * 4 + 3] = (char)255;
			x++;
		}
		y++;
	}
	while (y < WIN_SIZE)
	{
		x = 0;
		while (x < WIN_SIZE)
		{
			p_tab[(y * WIN_SIZE + x) * 4] = 0;
			p_tab[(y * WIN_SIZE + x) * 4 + 3] = (char)255;
			x++;
		}
		y++;
	}
}

void put_rect(char *pixel, SDL_Point pos, SDL_Point size, int color, SDL_Point win_size)
{
	int i;
	int j;
	SDL_Point end;
	unsigned int *tab;
	int negx;
	int negy;

	tab = (unsigned int*)pixel;
	negx = 1;
	negy = 1;
	if (size.y < 0)
	{
		size.y = -size.y;
		negy = -1;
	}
	if (size.x < 0)
	{
		size.x = -size.x;
		negx = -1;
	}
	end.x = pos.x + size.x;
	end.y = pos.y + size.y;
	if (end.x > win_size.x)
		end.x = win_size.x;
	if (end.y > win_size.y)
		end.y = win_size.y;
	if (pos.x < 0)
		pos.x = 0;
	if (pos.y < 0)
		pos.y = 0;
	i = pos.y;
	while (i < end.y)
	{
		j = pos.x;
		while (j < end.x)
		{
			tab[i * win_size.x + j] = color;
			j++;
		}
		i++;
	}
}

void put_view_ray(char *pixel, SDL_Point cube_pos[2], t_point pos, float rot, char color)
{
	t_point endpoint;

	endpoint.x = pos.x - (100 * cos(rot * M_PI_2));
	endpoint.y = pos.y - (100 * sin(rot * M_PI_2));
	octant(pos, endpoint, pixel, color, 0);
}
/*
void clear_tab_ini(t_var *v)
{
	unsigned int *tab = (unsigned int*)v->p_clear;
	int i;
	int end;

	i = 0;
	end = WIN_SIZE * WIN_SIZE;
	while (i < end)
		tab[i++] = 0x000000ff;
}
*/
void var_ini(t_var *v, char *file)
{
	v->win = SDL_CreateWindow("test",
						   SDL_WINDOWPOS_CENTERED,
						   SDL_WINDOWPOS_CENTERED,
						   WIN_SIZE,
						   WIN_SIZE,
						   SDL_WINDOW_SHOWN);
	v->rend = SDL_CreateRenderer(v->win, -1, SDL_RENDERER_ACCELERATED);
	v->screen = SDL_CreateTexture(v->rend, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, WIN_SIZE, WIN_SIZE);
	v->mini_map_xy = SDL_CreateTexture(v->rend, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, MINI_MAP_W, MINI_MAP_H);
	v->mini_map_xz = SDL_CreateTexture(v->rend, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, MINI_MAP_W, MINI_MAP_H);
	v->mini_map_yz = SDL_CreateTexture(v->rend, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, MINI_MAP_W, MINI_MAP_H);
	v->character = SDL_CreateTexture(v->rend, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, 10, 10);
	v->p_tab = (char*)malloc(WIN_SIZE * WIN_SIZE * 4);	
	v->map = readfile2(file, v);
	printf("map_size : x = %f, y = %f, z = %f\n",v->map_size.x ,v->map_size.y, v->map_size.z);
	// v->perso_pos.x = 0.766921;
	// v->perso_pos.y = 1.380223;
	// v->perso_pos.z = -1.600000;
	v->perso_pos.x = 1.5;
	v->perso_pos.y = -2;
	v->perso_pos.z = -0.5;
	v->fov = 1;
	v->rot = 0;
	v->roty = 1;
	v->win_size.x = WIN_SIZE;
    v->win_size.y = WIN_SIZE;
	v->stone.pixels = ft_load_bmp("img/stones.bmp",&v->stone.w, &v->stone.h);
	printf("IMG_SIZE, x = %i, y = %i\n",v->img_size.x, v->img_size.y);
	//clear_tab_ini(v);
	SDL_SetTextureBlendMode(v->mini_map_xy, SDL_BLENDMODE_ADD);
	SDL_SetTextureBlendMode(v->mini_map_xz, SDL_BLENDMODE_ADD);
	SDL_SetTextureBlendMode(v->mini_map_yz, SDL_BLENDMODE_ADD);
	SDL_SetRenderDrawBlendMode(v->rend, SDL_BLENDMODE_BLEND);
//	SDL_SetTextureBlendMode()
	printf("test\n");
}

int main(int ac, char **av)
{
	SDL_Event e;
	SDL_Window *win;
	SDL_Texture *screen;
	SDL_Texture *view;
	SDL_Rect image_size;
	const Uint8 *keyboard;
	void *pixel_view;
	int pitch;
	int w;
	int h;
	int quit = 0;
	float posx;
	float posy;
	int **map;
	int map_h;
	int map_w;
	int floor_h;
	float coef_x;
	float coef_y;
	SDL_Point perso;
	SDL_Point perso_size;
	SDL_Point map_size;
	float rot;
	t_var v;
	t_pos cam_rot;
	t_line test;
	t_vox pt1;
	t_vox pt2;
	t_point mousebutton[MOUSE];
	int savedmouse;
	int i;

	ac = 1;
	savedmouse = 0;
	SDL_Init(SDL_INIT_VIDEO);
	var_ini(&v,av[1]);
	printf("segfault 1?\n");
	printf("segfault2\n");
	printf("segfault2 33 \n");
	map_size.x = 100;
	map_size.y = 100;
	map_ini(v.map, map_size, &v);
	i = 0;
	while (i < MOUSE)
		mousebutton[i++].x = -1;
	while (!quit)
	{
		while (SDL_PollEvent(&e))
		{
			SDL_PumpEvents();
			keyboard = SDL_GetKeyboardState(NULL);
			if (e.type == SDL_QUIT)
				quit = 1;
			cam_rot.x = v.roty;
			cam_rot.y = v.rot;
			if (e.type == SDL_KEYDOWN)
			{
				if (keyboard[SDL_SCANCODE_ESCAPE])
					quit = 1;
				if (keyboard[SDL_SCANCODE_W])
				{
					v.perso_pos.y += 0.1 * cos((v.rot) * M_PI_2);
					v.perso_pos.x += 0.1 * sin((v.rot) * M_PI_2);
					print_map(&v);
				}
				if (keyboard[SDL_SCANCODE_S])
				{
					v.perso_pos.y -= 0.1 * cos((v.rot) * M_PI_2);
					v.perso_pos.x -= 0.1 * sin((v.rot) * M_PI_2);
					print_map(&v);
				}
				if (keyboard[SDL_SCANCODE_A])
				{
					v.perso_pos.y += 0.1 * cos((v.rot + 1) * M_PI_2);
					v.perso_pos.x += 0.1 * sin((v.rot + 1) * M_PI_2);
					print_map(&v);
				}
				if (keyboard[SDL_SCANCODE_D])
				{					
					v.perso_pos.y -= 0.1 * cos((v.rot + 1) * M_PI_2);
					v.perso_pos.x -= 0.1 * sin((v.rot + 1) * M_PI_2);
					print_map(&v);
				}
				if (keyboard[SDL_SCANCODE_Q])
				{
					v.rot += (double)0.02;
					print_map(&v);
				}
				if (keyboard[SDL_SCANCODE_E])
				{
					v.rot -= (double)0.02;
					print_map(&v);
				}
				if (keyboard[SDL_SCANCODE_F])
				{
					v.perso_pos.z += (double)0.1;
					print_map(&v);
				}
				if (keyboard[SDL_SCANCODE_R])
				{
					v.perso_pos.z -= (double)0.1;
					print_map(&v);
				}
				if (keyboard[SDL_SCANCODE_T])
				{
					v.roty += (double)0.02;
					print_map(&v);
				}
				if (keyboard[SDL_SCANCODE_G])
				{
					v.roty -= (double)0.02;
					print_map(&v);
				}
				if (keyboard[SDL_SCANCODE_Z])
				{
					//	if (v.fov < 10)
					{
						v.fov += (double)0.05;
						print_map(&v);
					}
				}
				if (keyboard[SDL_SCANCODE_X])
				{
					if (v.fov > 0.051)
					{
						v.fov -= (double)0.05;
						print_map(&v);
					}
				}
				if (keyboard[SDL_SCANCODE_B])
				{
					test.pos1.x = -42;
					test.pos1.y = 500;
					test.pos2.x = 1000;
					test.pos2.y = 700;
//					adapt_out_screen(&test1, &test2);
					//octant(test1, test2, v.p_tab, 0xffffffff);
					pt1.x = 1;
					pt1.y = 0;
					pt1.z = 0;
					pt2.x = 1;
					pt2.y = 1;
					pt2.z = 0;
					line_intersect(v.perso_pos, cam_rot, &pt1, &pt2, &test);
					//draw_textured_rectangle2(create_line())
//					cut_frustum(v.perso_pos, cam_rot);
				}
				printf("       rotx = %f \n",v.rot);
				printf("       roty = %f \n",v.roty);
				printf("perso_pos.x = %f \n",v.perso_pos.x);
				printf("perso_pos.y = %f \n",v.perso_pos.y);
				printf("perso_pos.z = %f \n",v.perso_pos.z);
				printf("        fov = %f \n",v.fov);
				printf("key pressed = %i \n",e.key.keysym.scancode);
			}
			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				if (e.button.button == SDL_BUTTON_LEFT)
				{
					printf("MOUSE POS : x = %d, y = %d\n", e.button.x, e.button.y);
					if (savedmouse < MOUSE)
					{
						mousebutton[savedmouse].x = e.button.x;
						mousebutton[savedmouse].y = e.button.y;
						savedmouse++;
					}
					else
					{
						savedmouse = 0;
						//printf("created line , p1 : x = %d, y = %d, p2 : x = %d, y = %d\n",mousebutton1.x, mousebutton1.y, e.button.x, e.button.y);
						//draw_textured_rectangle4(create_line(mousebutton[0], mousebutton[1]), create_line(mousebutton[2], create_point(e.button.x, e.button.y, 0)), &v.stone, v.p_tab);
						draw_textured_triangle(mousebutton[0], mousebutton[1], mousebutton[2],0 , &v.stone, v.p_tab);
						octant(mousebutton[0], mousebutton[1], v.p_tab, 0xffffffff, 2);
						octant(mousebutton[1], mousebutton[2], v.p_tab, 0xffffffff, 2);
						octant(mousebutton[2], mousebutton[0], v.p_tab, 0xffffffff, 2);
						SDL_UpdateTexture(v.screen, NULL, v.p_tab, WIN_SIZE * 4);
						SDL_RenderCopy(v.rend, v.screen, NULL, NULL);
						SDL_RenderPresent(v.rend);	
					}
				}
			}
		}
	}

	//	SDL_FreeFormat(format);
	//SDL_Quit();
	return (0);
}

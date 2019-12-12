/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 23:51:11 by ahippoly          #+#    #+#             */
/*   Updated: 2019/06/25 23:09:53 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/SDL2/SDL.h"
#include "wolf.h"
#include <math.h>

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

int main(int ac, char **av)
{
	SDL_Renderer *rend;
	SDL_Window *win = NULL;
	SDL_Event e;
	SDL_Texture *text;
	SDL_Rect image_size;
//	SDL_PixelFormat *format;
//	void *pixel_tab;
	char *bmp;
	int pitch;
	int w;
	int h;
	int quit = 0;
	ac = 1;
//	SDL_Color green = {0, 255, 0, 255};
	printf("WORKEDvwew");
	SDL_Init(SDL_INIT_VIDEO);
	printf("WORKED");
	
	win = SDL_CreateWindow("test",
						   SDL_WINDOWPOS_CENTERED,
						   SDL_WINDOWPOS_CENTERED,
						   WIN_SIZE,
						   WIN_SIZE,
						   SDL_WINDOW_SHOWN);
	rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	bmp = ft_load_bmp(av[1], &w, &h);
	printf("w = %i , h = %i\n",w,h);
	text = SDL_CreateTexture(rend, SDL_PIXELFORMAT_BGRA32, SDL_TEXTUREACCESS_STREAMING, w, h);
	pitch = w * 4;
	set_rect(&image_size,w,h);	
	SDL_UpdateTexture(text,NULL,bmp,w*4);
	SDL_RenderCopy(rend,text,NULL,NULL);
	SDL_RenderPresent(rend);
	while (!quit)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				quit = 1;
			}
			if (e.type == SDL_KEYDOWN)
			{
				printf("key pressed = %i , %i\n",e.key.keysym.scancode, e.key.keysym.sym);
			}
			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				quit = 1;
			}
		}
	}
//	SDL_FreeFormat(format);
	//SDL_Quit();
	return (0);
}

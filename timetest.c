#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include "aponswolf/includes/SDL2/SDL.h"

#define C clock()
#define S 1000000
int main()
{
	Uint32 c;
	double i;
	int lever;

	SDL_Init(SDL_INIT_VIDEO);
	write(1, "Starting...\n", 13);
	c = SDL_GetTicks();
	i = 1;
	lever = 1;
	while (SDL_GetTicks() - c <= 10000)
	{
		if(SDL_GetTicks() - c <= 1000)
		{
			write(1, "Nice\n", 6);
		}
		if(SDL_GetTicks() - c == 5500 && lever)
		{
			write(1, "4.5 seconds remaining...\n", 26);
			lever--;
		}
		if(SDL_GetTicks() >= 9000 && i)
		{
			write(1, "1 sec left\n", 12);
			i--;
		}
	}
	printf("Time reached !");
	return (0);
}
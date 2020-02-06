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
	int quit;
	const Uint8 *key;

	SDL_Init(SDL_INIT_VIDEO);
	write(1, "Starting...\n", 13);
	// c = SDL_GetTicks();
	// i = 1;
	// lever = 1;
	// while (SDL_GetTicks() - c <= 100)
	// {
	// 	if(SDL_GetTicks() - c <= 1000)
	// 	{
	// 		write(1, "Nice\n", 6);
	// 	}
	// 	if(SDL_GetTicks() - c == 5500 && lever)
	// 	{
	// 		write(1, "4.5 seconds remaining...\n", 26);
	// 		lever--;
	// 	}
	// 	if(SDL_GetTicks() >= 9000 && i)
	// 	{
	// 		write(1, "1 sec left\n", 12);
	// 		i--;
	// 	}
	// }
	quit = 1;
	while (quit)
	{
			printf("sponz NOPE\n");
		key = SDL_GetKeyboardState(NULL);
			printf("sponz NOPE 3\n");

		SDL_PumpEvents();
			printf("sponz NOPE 2\n");
		
		if (key[SDL_SCANCODE_Z])
		{
			printf("sponz\n");
			quit = 0;
		}
	}
	printf("Time reached !");
	return (0);
}
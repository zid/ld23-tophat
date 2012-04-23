#include <SDL.h>

int events(void)
{
	SDL_Event e;

	SDL_PollEvent(&e);
	
	switch(e.type)
	{
		case SDL_QUIT:
			return 0;
		break;
		default:
			return 1;
		break;
	}
}

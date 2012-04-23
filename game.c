#include <SDL.h>	/* TODO: Get rid of this and add input.h */
#include "game.h"
#include "video.h"

enum {
	TITLE_SCREEN,
	GAMEPLAY
};

static int state;
static Uint8 *keys;

void game_init(void)
{
	state = TITLE_SCREEN;
}

static void game_title(void)
{
	draw_title_screen();
	if(keys[SDLK_LEFT] || keys[SDLK_RIGHT] || keys[SDLK_UP] || keys[SDLK_DOWN])
		state = GAMEPLAY;
}

static void game_play(void)
{
	draw_background();
}

void game_logic(void)
{
	SDL_PumpEvents();

	keys = SDL_GetKeyState(NULL);

	switch(state)
	{
		case TITLE_SCREEN:
			game_title();
		break;
		case GAMEPLAY:
			game_play();
		break;
	}

	render();
}


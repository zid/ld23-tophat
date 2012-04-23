#include <SDL.h>
#include "textures.h"

#define W 640
#define H 640

static SDL_Surface *screen;
static SDL_Surface *tex[MAX_TEXTURES];

int video_init(void)
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Unable to init SDL video: %s\n", SDL_GetError());
		return 0;
	}

	screen = SDL_SetVideoMode(W, H, 16, SDL_HWSURFACE | SDL_DOUBLEBUF);
	if(!screen)
	{
		printf("Unable to set video mode.\n");
		return 0;
	}

	return 1;
}

const char *texture_names[] = {
	"losescreen.bmp",
	"intro.bmp",
	"winscreen.bmp",
	"1.bmp",
	"2.bmp",
	"3.bmp",
	"playerup.bmp",
	"playerdown.bmp",
	"playerleft.bmp", 
	"playerright.bmp",
	"playerprojectiledown.bmp",
	"playerprojectileup.bmp",
	"playerprojectileleft.bmp",
	"playerprojectileright.bmp",
	"enemyflame.bmp",
	"enemyup.bmp",
	"enemydown.bmp",
	"enemyleft.bmp",
	"enemyright.bmp",
	"background.bmp"
};
	
int load_textures(void)
{
	int i;
	
	for(i = 0; i < MAX_TEXTURES; i++)
	{
		tex[i] = SDL_LoadBMP(texture_names[i]);
		if(!tex[i])
			return 0;
	}

	return 1;
}

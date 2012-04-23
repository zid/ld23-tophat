#include <stdio.h>
#include <SDL.h>
#include <SDL_mixer.h>

#define RATE 22050
#define	FORMAT AUDIO_S16
#define CHANNELS 2
#define BUFFERS 4096

struct mixer {
	Mix_Music *music;
	int frequency, channels;
	Uint16 format;
};

static struct mixer mix;
static int nosound = 0;

int audio_init(void)
{
	if(SDL_Init(SDL_INIT_AUDIO) < 0)
	{
		fprintf(stderr, "Warning: Unable to init SDL_mixer: %s\n", SDL_GetError());
		nosound = 1;
		return 1;
	}

	if(Mix_OpenAudio(RATE, FORMAT, CHANNELS, BUFFERS) < 0)
	{
		fprintf(stderr, "Warning: Unable to create mixer.\n");
		nosound = 1;
		return 1;
	}

	Mix_QuerySpec(&mix.frequency, &mix.format, &mix.channels);

	mix.music = Mix_LoadMUS("music.it");

	return 1;
}

void play_music(void)
{
	if(nosound)
		return;

	Mix_PlayMusic(mix.music, -1);
}

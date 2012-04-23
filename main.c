#include <stdlib.h>
#include "video.h"
#include "audio.h"
#include "event.h"
#include "game.h"

int main(int argc, char *argv[])
{
	int r;

	r = video_init();
	if(!r)
		return EXIT_FAILURE;

	r = audio_init();
	if(!r)
		return EXIT_FAILURE;

	r = load_textures();
	if(!r)
		return EXIT_FAILURE;

	play_music();
	game_init();

	while(1)
	{
		if(!events())
			break;

		game_logic();
	}
	
	return EXIT_SUCCESS;
}

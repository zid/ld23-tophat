#include <stdlib.h>
#include "video.h"
#include "audio.h"
#include "event.h"

int main(int argc, char *argv[])
{
	int r;

	r = video_init();
	if(!r)
		return EXIT_FAILURE;

	r = audio_init();
	if(!r)
		return EXIT_FAILURE;

	play_music();

	while(1)
	{
		if(!events())
			break;
	}
	
	return EXIT_SUCCESS;
}

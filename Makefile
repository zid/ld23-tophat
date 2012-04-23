ld: main.c video.c audio.c event.c
	gcc main.c video.c audio.c event.c  -o ld -lSDL -lSDL_mixer -I/usr/include/SDL/

ld: main.c video.c audio.c event.c game.c
	gcc main.c video.c audio.c event.c game.c -o ld -ggdb -lSDL -lSDL_mixer -I/usr/include/SDL/

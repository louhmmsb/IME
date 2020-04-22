#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <SDL.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

struct rect_list_type {
	SDL_Rect rect;
	int velocity;
	struct rect_list_type *next;
};

extern struct rect_list_type *rect_list;

#endif

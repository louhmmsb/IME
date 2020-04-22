#include <stdlib.h>
#include <SDL.h>

#include "graphic.h"
#include "free.h"

#define MAX_VELOCITY 150
#define RECT_SIZE 100

struct rect_list_type *rect_list = NULL;

static SDL_Window *wind = NULL;
static SDL_Renderer *rend = NULL;

void update_x_pos()
{
	struct rect_list_type *current = rect_list;
	while (current != NULL) {
		current->rect.x += current->velocity;
		current = current->next;
	}
}

void insert_random_rect_list(void)
{
	struct rect_list_type *new_node = malloc(sizeof(struct rect_list_type));

	new_node->rect.x = rand() % WINDOW_WIDTH;
	new_node->rect.y = rand() % WINDOW_HEIGHT;
	new_node->velocity = 1 + rand() % (MAX_VELOCITY - 1);
	new_node->rect.w = RECT_SIZE;
	new_node->rect.h = RECT_SIZE;

	if (rect_list == NULL) {
		new_node->next = NULL;
		rect_list = new_node;
	} else {
		new_node->next = rect_list;
		rect_list = new_node;
	}
}

Uint32 callback(Uint32 interval, void *params)
{
	destroy_unused_rects();
	insert_random_rect_list();
	update_x_pos();
	return interval;
}

void render(void)
{
	SDL_SetRenderDrawColor(rend, 0xff, 0xff, 0xff, 0xff);
	SDL_RenderClear(rend);

	SDL_SetRenderDrawColor(rend, 0x00, 0x00, 0x00, 0xff);

	struct rect_list_type *current = rect_list;
	while (current != NULL) {
		SDL_RenderDrawRect(rend, &current->rect);
		current = current->next;
	}

	SDL_RenderPresent(rend);
}

int main(void)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0) {
		printf("erro: %s\n", SDL_GetError());
		return -1;
	}
	srand(SDL_GetTicks());

	wind = SDL_CreateWindow("ball",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH, WINDOW_HEIGHT, 0);
	if (!wind) {
		printf("erro: %s\n", SDL_GetError());
		return -1;
	}
	rend = SDL_CreateRenderer(wind, -1, SDL_RENDERER_PRESENTVSYNC);
	if (!rend) {
		printf("erro: %s\n", SDL_GetError());
		return -1;
	}

	if (SDL_AddTimer(100, callback, NULL) == 0) {
		printf("erro: %s\n", SDL_GetError());
	}

	int should_quit = 0;
	do {
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				should_quit = 1;
			}
		}
		render();
	} while(!should_quit);

	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(wind);
	SDL_Quit();
	return 0;
}

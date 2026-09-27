#define SDL_MAIN_USE_CALLBACKS 1

#include<SDL3/SDL.h>
#include<SDL3/SDL_main.h>
#include<SDL3_image/SDL_image.h>
#include<iostream>

#define MY_WINDOW_WIDTH 1280
#define MY_WINDOW_HEIGHT 720

static SDL_Window* window;
static SDL_Renderer* renderer;

SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[]) {
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer("Sugazu", MY_WINDOW_WIDTH, MY_WINDOW_HEIGHT, 0, &window, &renderer);
	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void* appstate) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	SDL_FRect charrect = {static_cast<float>(MY_WINDOW_WIDTH / 2 - 360), 0.0f, 720.0f, 720.0f};
	SDL_Texture* charimg = IMG_LoadTexture(renderer, "sprites/ildar.png");
	SDL_RenderTexture(renderer, charimg, NULL, &charrect);
	SDL_DestroyTexture(charimg);
	SDL_RenderPresent(renderer);
	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event) {
	if (event->type == SDL_EVENT_QUIT) {
		return SDL_APP_SUCCESS;
	}
	return SDL_APP_CONTINUE;
}
void SDL_AppQuit(void* appstate, SDL_AppResult result) {

}
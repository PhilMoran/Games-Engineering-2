#pragma once
#include <SDL.h>
#include "Sprite.h"
//#include <SDL_image.h>


class Game {
private:
	Sprite* sprite = new Sprite();
	bool isRunning;
	int index;
	SDL_Renderer *renderer;
	SDL_Window* window;
public:
	void Initialize();
	void HandleEvents();
	void Update();
	void Render();
	void CleanUp();

	bool IsRunning();
};
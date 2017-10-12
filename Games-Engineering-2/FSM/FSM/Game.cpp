#include "Game.h"
#include "Sprite.h"

void Game::Initialize()
{
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("An SDL2 window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	sprite->Load(renderer);
	isRunning = true;
}

void Game::HandleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{	
		if (event.type == SDL_QUIT)
		{
			isRunning = false;
		}
	}

}

void Game::Render()
{
	// clear the screen
	SDL_RenderClear(renderer);

	sprite->Render(renderer);

	// flip the backbuffer
	// this means that everything that we prepared behind the screens is actually shown
	SDL_RenderPresent(renderer);
}

void Game::Update()
{
	HandleEvents();
	Render();
	sprite->Update();
}

void Game::CleanUp()
{
	sprite->Destroy();
}

bool Game::IsRunning()
{
	return isRunning;
}

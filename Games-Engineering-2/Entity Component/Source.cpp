#include <SDL.h>
#include <SDL_image.h>
#include "Entity.h"
#include "HealthComponent.h"
#include "PositionComponent.h"
#include "ControlComponent.h"
#include "AI_System.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{

	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
	SDL_Window* window = SDL_CreateWindow("Entity Component", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 800, SDL_WINDOW_SHOWN);
	SDL_Texture *image = nullptr;


	Entity player;
	Entity alien;
	Entity dog;
	Entity cat;

	HealthComponent healthComponent;
	PositionComponent positionComponent;
	ControlComponent controlComponent;
	AI_System aiSystem;
	

	player.addComponent(healthComponent);
	alien.addComponent(healthComponent);
	dog.addComponent(healthComponent);
	cat.addComponent(healthComponent);
	
	player.addComponent(positionComponent);
	alien.addComponent(positionComponent);
	dog.addComponent(positionComponent);
	cat.addComponent(positionComponent);

	player.addComponent(controlComponent);

	aiSystem.addEntity(alien);
	aiSystem.addEntity(dog);
	aiSystem.addEntity(cat);


	bool isRunning = true;


	while (isRunning)
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
	SDL_Quit();
	return 0;
}
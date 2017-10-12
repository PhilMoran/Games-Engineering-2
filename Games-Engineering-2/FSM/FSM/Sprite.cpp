#include "Sprite.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>


Sprite::Sprite()
{
}


void Sprite::Load(SDL_Renderer* renderer)
{
	playerSprite = IMG_LoadTexture(renderer, "Sonic.png");


	texRect.x = 150;
	texRect.y = 100;
	texRect.w = 200;
	texRect.h = 300;

	animRect.x = 0;
	animRect.y = 52;
	animRect.w = 32;
	animRect.h = 36;
}
void Sprite::Render(SDL_Renderer* renderer)
{
	// copy the texture to the rendering context
	SDL_RenderCopy(renderer, playerSprite, &animRect, &texRect);
}

void Sprite::Update()
{
	Animation fsm;
	State state;
	

	if (i == 0)
	{
		fsm.idle(&animRect);
		std::this_thread::sleep_for(std::chrono::microseconds(100000));
	}
	else if (i == 1)
	{
		fsm.climbing(&animRect);
		std::this_thread::sleep_for(std::chrono::microseconds(100000));
	}
	else if (i == 2)
	{
		fsm.jumping(&animRect);
		std::this_thread::sleep_for(std::chrono::microseconds(100000));
	}
}

void Sprite::Destroy()
{
	SDL_DestroyTexture(playerSprite);
}
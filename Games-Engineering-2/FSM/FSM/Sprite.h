#pragma once
#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "SDL.h"
#include "FSM.h"
#include <thread>
#include <iostream>

class Sprite {
public:
	SDL_Texture *playerSprite;
	SDL_Rect texRect;
	SDL_Rect currentTile;
	SDL_Rect animRect;
	int i = 1;

	Sprite();

	void Load(SDL_Renderer*);
	void Render(SDL_Renderer*);
	void Update();
	void Destroy();
private:
	
};

#endif
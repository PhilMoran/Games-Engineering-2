#include "AI.h"
#include <thread>
#include <string>
#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <algorithm>
#include <Vector2D.h>

AI::AI()
{
	for (int i = 0; i < 5; i++)
	{
		ai_Dest[i].x = rand() % 400 + 500;
		ai_Dest[i].y = rand() % 200 + 500;
		ai_Dest[i].w = 32;
		ai_Dest[i].h = 32;

		ai_Source.x = 0;
		ai_Source.y = 0;
		ai_Source.w = 64;
		ai_Source.h = 105;
	}

}


AI::~AI()
{

}
void AI::Load(SDL_Renderer * m_rend)
{
	for (int i = 0; i < 5; i++)
	{
		aiSurf.push_back(SDL_LoadBMP("assets/enemy.bmp"));
		ai.push_back(SDL_CreateTextureFromSurface(m_rend,aiSurf.at(i)));
		SDL_FreeSurface(aiSurf.at(i));
	}
	
}
void AI::Render(SDL_Renderer * m_rend)
{
	for (int i = 0; i < 5; i++)
	{
		SDL_RenderCopy(m_rend, ai.at(i), &ai_Source, &ai_Dest[i]);
	}
}

void AI::SpawnZone()
{
	if (mapNum == 1)
	{
		for (int i = 0; i < 5; i++)
		{
			ai_Dest[i].x = 100;
			ai_Dest[i].y = 100;
		}
	
	}
}

void AI::Update()
{
	for (int i = 0; i < 5; i++)
	{
		ai_Dest[i].x -= 1;
	}
	
}

void AI::Collisions()
{
	
}

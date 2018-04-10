#include "AI.h"



AI::AI()
{
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
		ai_Dest[i].x = 100;
		ai_Dest[i].y = 100;
		ai_Dest[i].w = 500;
		ai_Dest[i].h = 500;

		ai_Source[i].x = 0;
		ai_Source[i].y = 0;
		ai_Dest[i].w = 64;
		ai_Dest[i].h = 105;
		SDL_RenderCopy(m_rend, ai.at(i), &ai_Source[i], &ai_Dest[i]);
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

}

void AI::Collisions()
{

}

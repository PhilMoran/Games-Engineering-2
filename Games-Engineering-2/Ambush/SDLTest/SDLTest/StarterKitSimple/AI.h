#pragma once
#include <SDL.h>
#include <vector>

using namespace std;
class AI
{
public:
	AI();
	~AI();
	void Load(SDL_Renderer * m_rend);
	void Render(SDL_Renderer * m_rend);
	void SpawnZone();
	void Update();
	void Collisions();
private:
	
	vector<SDL_Texture*> ai;
	vector<SDL_Surface*> aiSurf;
	SDL_Rect ai_Source[5];
	SDL_Rect ai_Dest[5];

	int mapNum = 1;
	
};


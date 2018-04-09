#include <SDL.h>
#include <iostream>
class Levels
{
public:
	Levels();
	~Levels();
	typedef struct Map
	{
		int tile[30][30];
	};
	int ticks;
	SDL_Surface *wallSurf;
	SDL_Surface *floorSurf;
	SDL_Texture *wall;
	SDL_Texture *floor;
	void initTiles(SDL_Renderer * m_rend);
	void loadMap(char *name);
	void drawMap(SDL_Renderer * m_rend);
	Map map;
	SDL_Rect sourceRect;
	SDL_Rect destRect;
};


// somewhere in main.cpp

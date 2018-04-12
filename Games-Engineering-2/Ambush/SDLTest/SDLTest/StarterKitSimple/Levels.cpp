#include "Levels.h"
#include <vector>

Levels::Levels()
{
	sourceRect.x = 0;
	sourceRect.y = 0;
	sourceRect.w = 32;
	sourceRect.h = 32;

	destRect.x = 0;
	destRect.y = 0;
	destRect.w = 32;
	destRect.h = 32;
}


Levels::~Levels()
{
}

void Levels::initTiles(SDL_Renderer * m_rend)
{
	/* Load the brick image */

	wallSurf = SDL_LoadBMP("assets/wall.bmp");
	wall = SDL_CreateTextureFromSurface(m_rend, wallSurf);
	SDL_FreeSurface(wallSurf);
	/* If we get back a NULL image, just exit */

	if (wall == NULL)
	{
		std::cout << "NO LOAD WALL" << std::endl;
	}

	/* Load the background image */

	floorSurf = SDL_LoadBMP("assets/floor.bmp");
	floor = SDL_CreateTextureFromSurface(m_rend, floorSurf);
	SDL_FreeSurface(floorSurf);
	/* If we get back a NULL image, just exit */

	if (floor == NULL)
	{
		std::cout << "NO LOAD FLOOR" << std::endl;
	}

	loadMap("assets/map1.txt");
}
void Levels::loadMap(char *name)
{
	int x, y;
	FILE *fp;

	fp = fopen(name, "rb");

	/* If we can't open the map then exit */

	if (fp == NULL)
	{
		printf("Failed to open map %s\n", name);
	}

	/* Read the data from the file into the map */

	for (y = 0; y<30; y++)
	{
		for (x = 0; x<30; x++)
		{
			fscanf(fp, "%d", &map.tile[y][x]);
		}
	}

	/* Close the file afterwards */

	fclose(fp);
}
void Levels::drawMap(SDL_Renderer * m_rend)
{
	
	/* Draw the map */
	int tempX;
	int tempY;
		for (int y = 0; y < 30; y++)
		{
			tempY = y * 32;
			for (int x = 0; x < 30; x++)
			{
				tempX = x * 32;
				destRect.x = tempX;
				destRect.y = tempY;
				if (map.tile[y][x] == 1)
				{
					SDL_RenderCopy(m_rend, wall, &sourceRect, &destRect);
				}
				if (map.tile[y][x] == 0)
				{
					SDL_RenderCopy(m_rend, floor, &sourceRect, &destRect);
				}
				
			}
		}
	}
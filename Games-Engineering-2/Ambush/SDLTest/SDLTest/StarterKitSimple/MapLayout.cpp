#include "MapLayout.h"



MapLayout::MapLayout()
{
}


MapLayout::~MapLayout()
{
}
void MapLayout::Display()
{
	
	for (int i = 1; i <= size * size; ++i) {
		std::cout << data[i - 1] << " ";
		if (!(i % size)) std::cout << "\n";
	}
}
bool MapLayout::getIfInDanger(Vector2 position) 
{
	if (position.y < 0) position.y = 0;
	if (position.x < 0) position.x = 0;
	if (position.y >= 20) position.y = size - 1;
	if (position.x >= 20) position.x = size - 1;
	return(data[position.getX() + (position.getY() * size)] == 'X');
}
void  MapLayout::setElement(char&& asda, Vector2 position)
{
	data[position.getX() + (position.getY() * size)] = asda;
}
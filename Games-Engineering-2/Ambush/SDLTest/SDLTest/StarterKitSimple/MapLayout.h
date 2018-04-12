#pragma once
#include <vector>
#include "Vector2D.h"
#include <iostream>
class MapLayout
{
private:
		std::vector<char> data;
		int size;
public:
		MapLayout();
		~MapLayout();
		MapLayout(int _size) : size(_size) {
			data.resize(size * size);
			for (int i = 0; i < size * size; ++i) data[i] = '.';
		}
		void Display();

		bool getIfInDanger(Vector2 position);

		void setElement(char&& asda, Vector2 position);
};


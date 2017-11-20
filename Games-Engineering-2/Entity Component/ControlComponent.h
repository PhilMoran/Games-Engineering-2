#pragma once
#include "Component.h"
#include <iostream>
class ControlComponent : public Component
{
public:
	ControlComponent() : pos(200, 200) { std::cout << "Control Component System" << std::endl; }
	int getPosition()
	{
		return pos.x, pos.y;
	}
	void setPosition(Point2D tempPos)
	{
		this->pos = tempPos;
	}
private:
	Point2D pos;
};
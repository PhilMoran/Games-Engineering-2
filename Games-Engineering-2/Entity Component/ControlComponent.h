#pragma once
#include "Component.h"
class ControlComponent : public Component
{
public:
	ControlComponent() : pos(200, 200) {}
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
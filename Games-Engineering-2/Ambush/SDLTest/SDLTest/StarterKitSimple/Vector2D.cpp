#include "Vector2D.h"



Vector2::Vector2()
{
}


Vector2::~Vector2()
{
}

Vector2 Vector2::operator+(const Vector2 & other)
{
	Vector2 temp;
	temp.x = this->x + other.x;
	temp.y = this->y + other.y;
	return temp;
}

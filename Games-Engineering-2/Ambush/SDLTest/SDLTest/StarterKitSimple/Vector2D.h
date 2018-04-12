#pragma once
class Vector2
{
public:
	int x, y;
	Vector2(int _x, int _y) : x(_x), y(_y) {}
	Vector2();
	~Vector2();

	Vector2 operator +(const Vector2& other);
	int getX() const { return x; }
	int getY() const { return y; }

	friend class Map;
};

#pragma once
#include <vector>
#include <Vector2D.h>
#include <MapLayout.h>
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;
struct Node
{
	Vector2 position;
	int G, H, F;
	Node* parent = nullptr;

	Node() = default;
	Node(const Node& other) = default;
	Node(Vector2 pos) :position(pos) {};

	void calc(const Vector2& endPos) {
		H = static_cast<int>((abs(static_cast<double>(position.getX() - endPos.getX())) + abs(static_cast<double>(position.getY() - endPos.getY()))));
		G = parent ? parent->G + 1 : 1;
		F = G + H;
	}

	bool operator==(const Node& other) const {
		return (position.getX() == other.position.getX() && position.getY() == other.position.getY());
	}
	bool operator!=(const Node& other) const {
		return !(*this == other);
	}
	bool operator<(const Node& other)  const {
		return(F < other.F);
	}
};

class Solver
{
public:
		Vector2 startPos, endPos;
		std::vector<Vector2> directions;
		MapLayout map;
	public:
		Solver();
		Solver(Vector2 _startPos, Vector2 _endPos, int size);

		bool aStar();
};


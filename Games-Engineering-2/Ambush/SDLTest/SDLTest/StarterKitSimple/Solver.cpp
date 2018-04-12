#include "Solver.h"


Solver::Solver()
{

}
Solver::Solver(Vector2 _startPos, Vector2 _endPos, int size) : startPos(_startPos), endPos(_endPos) {
	MapLayout temp(size);
	map = temp;


	map.setElement('X', Vector2(14, 15));
	map.setElement('X', Vector2(15, 15));
	map.setElement('X', Vector2(16, 15));
	map.setElement('X', Vector2(16, 14));
	map.setElement('X', Vector2(16, 13));

	directions.resize(8);
	directions[0] = Vector2(-1, 1);
	directions[1] = Vector2(-1, 0);
	directions[2] = Vector2(-1, -1);
	directions[3] = Vector2(0, 1);
	directions[4] = Vector2(0, -1);
	directions[5] = Vector2(1, 1);
	directions[6] = Vector2(1, 0);
	directions[7] = Vector2(1, -1);
}
bool Solver::aStar() {
	Node startNode(startPos);
	Node goalNode(Vector2(endPos.getX(), endPos.getY()));

	if (map.getIfInDanger(startNode.position) || map.getIfInDanger(goalNode.position)) {
		std::cout << "Either the start of this map is obstructed or so is the end.";
		return false;
	}

	list<Node> openList;
	list<Node> closedList;

	startNode.calc(endPos);
	openList.push_back(startNode);

	while (!openList.empty()) {
		auto current = Node(*std::min_element(openList.begin(), openList.end()));

		current.calc(endPos);

		closedList.push_back(current);
		openList.remove(current);
		if (current == goalNode) break;

		for (auto& direction : directions) {
			Node successor(direction + current.position);

			if (map.getIfInDanger(successor.position) || successor.position.getX() > 20 - 1 ||
				successor.position.getY() > 20 - 1 || successor.position.getX() < 0 ||
				successor.position.getY() < 0 ||
				std::find(closedList.begin(), closedList.end(), successor) != closedList.end()) {
				continue;
			}

			successor.calc(endPos);

			auto inOpen = std::find(openList.begin(), openList.end(), successor);
			if (inOpen == openList.end()) {
				successor.parent = &closedList.back();
				successor.calc(endPos);

				openList.push_back(successor);
			}
			else
				if (successor.G < inOpen->G) successor.parent = &closedList.back();
		}
	}

	if (!openList.size()) {
		std::cout << "No path has been found\n";
		return false;
	}

	auto inClosed = std::find(closedList.begin(), closedList.end(), goalNode);
	if (inClosed != closedList.end()) {
		while (*inClosed != startNode) {
			map.setElement('Y', inClosed->position);
			*inClosed = *inClosed->parent;
		}
	}

	//map.Display();
	return true;
}
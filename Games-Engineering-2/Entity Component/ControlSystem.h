#pragma once
#include "Component.h"
#include <iostream>
class ControlSystem
{
	std::vector<Component> entities;
public:
	ControlSystem() {};
	~ControlSystem() {};
	void addEntity(Component e) {}
	void update();
};
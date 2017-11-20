#pragma once
#include "Component.h"
#include <iostream>

class RenderSystem
{
	std::vector<Component> entities;
public:
	RenderSystem() {};
	~RenderSystem() {};
	void addEntity(Component e) {}
	void update();
};


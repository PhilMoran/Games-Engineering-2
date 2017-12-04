#pragma once
#include "Entity.h"
#include "Component.h"
#include <iostream>
class AI_System
{
	std::vector<Component> entities;
public:
	void addEntity(Component e){}
	void update()
	{
		std::cout << "AI Updating" << std::endl;

	}
};
#pragma once
#include "Component.h"
#include <vector>
class Entity
{
	int id;
public:
	Entity() {};
	void addComponent(Component c)
	{
		components.push_back(c);
	}
	std::vector<Component> getComponents() 
	{ 
		return components; 
	}

private:
	std::vector<Component> components;
	
};
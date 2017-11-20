#pragma once
#include "Component.h"
#include <iostream>
class HealthComponent: public Component
{
public:
	HealthComponent() : health(100)
	{
		std::cout << "HealthUpdate" << std::endl;
	}
	int getHealth() { return health; }
	void setHealth(int health)
	{
		this->health = health;
	}
private:
	int health;
};

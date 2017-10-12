#pragma once
#include <iostream>
#include "SDL.h"
#include "Sprite.h"
#include <thread>

class Animation 
{
	class State* current;
	
public:
	Animation();
	void setCurrent(State* s)
	{
		current = s;
	}
	void idle(SDL_Rect*);
	void jumping(SDL_Rect*);
	void climbing(SDL_Rect*);

};
class State
{
public:
	virtual void idle(Animation* a)
	{
		std::cout << "STATE::IDLING" << std::endl;
	}
	virtual void jumping(Animation* a)
	{
		std::cout << "STATE::JUMPING" << std::endl;
	}
	virtual void climbing(Animation* a)
	{
		std::cout << "STATE::CLIMBING" << std::endl;
	}
};
class Idle : public State
{
public:
	Idle(){};
	~Idle(){};
	void jumping(Animation* a);
	void climbing(Animation* a);
};
class Jumping : public State
{
public:
	Jumping() {};
	~Jumping() {};
	void idle(Animation* a);
};
class Climbing : public State
{
public:
	Climbing() {};
	~Climbing() {};
	void idle(Animation* a);
	

};

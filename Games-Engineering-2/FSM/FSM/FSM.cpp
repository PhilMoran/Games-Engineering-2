#include "FSM.h"

Animation::Animation()
{
	current = new Idle();
}
void Animation::idle(SDL_Rect * animRect)
{
	if (animRect->y > 54)
	{
		animRect->y = 54;
	}
	if (animRect->y < 54)
	{
		animRect->y = 54;
	}
	if (animRect->x >= 63)
	{
		animRect->x = 0;
	}
	else if (animRect->x <= 64)
	{
		animRect->x += 32;
	}
	
	current->idle(this);
}
void Animation::jumping(SDL_Rect * animRect)
{
	current->jumping(this);
	
		if (animRect->y > 162)
		{
			animRect->y = 162;
		}
		if (animRect->y < 162)
		{
			animRect->y = 162;
		}
		if (animRect->x >= 160)
		{
			animRect->x = 0;
		}
		if (animRect->x < 160)
		{
			animRect->x += 34.5;
		}
}
void Animation::climbing(SDL_Rect * animRect)
{
	animRect->w = 32;
	animRect->h = 36;

	if (animRect->y > 490)
	{
		animRect->y = 490;
	}
	if (animRect->y < 490)
	{
		animRect->y = 490;
	}
	if (animRect->x >= 128)
	{
		animRect->x = 0;
	}
	if (animRect->x < 128)
	{
		animRect->x += 32;
	}
	current->climbing(this);
}

void Idle::jumping(Animation * a)
{
	std::cout << "Jumping" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
void Idle::climbing(Animation* a)
{
	std::cout << "Climbing" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

void Jumping::idle(Animation * a)
{
	std::cout << "Going from Jumping to Idling" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

void Climbing::idle(Animation * a)
{
	std::cout << "Going from Climbing to Idling" << std::endl;
	a->setCurrent(new Idle());
	delete this;

}

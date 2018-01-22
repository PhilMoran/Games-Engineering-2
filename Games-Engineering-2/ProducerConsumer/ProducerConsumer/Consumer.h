#pragma once
#include <iostream>
#include "Thread.h"

class Consumer: public Thread
{
public:
	Consumer();
	~Consumer();

	int b;
	//Producer pro;
	void run();
};


#pragma once
#include <iostream>
#include <math.h>
#include "Thread.h"
class Producer: public Thread
{
public:
	Producer();
	~Producer();
	
	
	int a;
	int i = 0;
	//int produced;
	void run();
};


// ProducerConsumer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	Producer *producer = new Producer();
	Consumer *consumer = new Consumer();

	
	producer->run();
	consumer->run();
	
	system("PAUSE");
    return 0;
}


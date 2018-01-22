#include "stdafx.h"
#include "Producer.h"

using namespace std;

Producer::Producer()
{
	a = 0;
	p = 0;
}


Producer::~Producer()
{
}

void Producer::run()
{
	cout << "Producer Starting" << endl;
	while (p < n)
	{	
		
		while (p != c)
		{
			cout << "Short order cook spinning" << endl;
			break;
		}
		a = (int)rand() * 100;
		cout << "Making a Burger"<< endl;
		buf = a;
		p = p + 1;

	}
	cout << "Finished Making Burgers" << endl;
	//produced = p;
}
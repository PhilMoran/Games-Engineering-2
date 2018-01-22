#include "stdafx.h"
#include "Consumer.h"

using namespace std;

Consumer::Consumer()
{
	b = 0;
	c = 0;
}


Consumer::~Consumer()
{
}

void Consumer::run()
{
	cout << "Consumer Starting" << endl;
	while (c < n)
	{
		while (p<= c)
		{
			cout << "Starving Waiting on a burger"<< endl;
			break;
		}
		cout << "Eating Burger" << endl;
		b = buf;
		c = c + 1;
	}
	cout<<"Finished Making Burgers"<<endl;
}
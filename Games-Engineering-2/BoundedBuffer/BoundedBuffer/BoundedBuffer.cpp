// BoundedBuffer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

int mutex = 1, full = 0, empty = 5,front=0;
//int buffer[];

int main()
{
	int n;
	void producer();
	void consumer();
	int wait(int);
	int signal(int);

	printf("\n1.Producer\n2.Consumer\n3.Close");

	while (1)
	{
		printf("\nEnter your choice:");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			if ((mutex == 1) && (empty != 0))
			{
				producer();
			}
			else
			 printf("Buffer is at capacity");
			break;

		case 2:
			if ((mutex == 1) && (full != 0))
			{
				consumer();
			}
			else
				printf("Buffer empty nothing to be eaten");
			break;
		case 3:
			exit(0);
			break;
		}
	}

	return 0;
}

int wait(int s)
{
	return (--s);
}

int signal(int s)
{
	return(++s);
}

void producer()
{
	mutex = wait(mutex);
	full = signal(full);
	empty = wait(empty);
	//buffer[front] = 1;
	front++;
	printf("\nProducer produces the item %d", front);
	mutex = signal(mutex);
}

void consumer()
{
	mutex = wait(mutex);
	full = wait(full);
	empty = signal(empty);
	printf("\nConsumer consumes item %d", front);
	//buffer[front] = 0;
	front--;
	mutex = signal(mutex);
}
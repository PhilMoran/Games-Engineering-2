// BoundedBuffer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include <thread>

int mutex = 1, full = 0,empty =5, front = 0;
int writing = 0;
int numReader = 0;
int buffer[5];

void producer();
void consumer();
void reader();
void writer();
int wait(int);
int signal(int);

int main()
{
	
	std::thread writer(writer);
	std::thread reader(reader);
	
	writer.join();
	reader.join();
	

	

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
	buffer[front] = 1;
	front++;
	printf("\nProducer produces the item %d", front);
	mutex = signal(mutex);
}

void consumer()
{
	mutex = wait(mutex);
	full = wait(full);
	empty = signal(empty);
	buffer[front] = 0;
	printf("\nConsumer consumes item %d", front);
	front--;
	mutex = signal(mutex);
}
void reader()
{
	wait(mutex);
	numReader++;
	if (1 == numReader) // If we are the first reader get write lock 
	{
		wait(writing); // Once we have it, it keeps writers at bay
		std::cout << "\n \nReaderLock" << std::endl;
	}
	signal(mutex);

	std::cout << "BufferData:" << buffer[0] << buffer[1] << buffer[2] << buffer[3] << buffer[4] << std::endl;
	wait(mutex);   // Allow writers

	numReader--;
	if (0 == numReader) // If we are the last reader to leave
	{
		std::cout << "ReaderUnlock" << std::endl;
		signal(writing); // Allow writers
	}
	signal(mutex);
}
void writer()
{
	int n;
	

	printf("\n1.Producer\n2.Consumer\n3.Close");
	while (1)
	{
		printf("\nEnter your choice:");
		scanf("%d", &n);
		std::cout<<std::endl;
		switch (n)
		{
		case 1:
			if ((mutex == 1) && (empty != 0))
			{
				std::cout << "Writing LOCK" << std::endl;
				wait(writing);
				producer();
				signal(writing);
				std::cout << "\nWriting UNLOCK" << std::endl;
				reader();
			}
			else
				printf("Buffer is at capacity");
			break;

		case 2:
			if ((mutex == 1) && (full != 0))
			{
				std::cout << "Writing LOCK" << std::endl;
				wait(writing);
				consumer();
				std::cout << "\nWriting UNLOCK" << std::endl;
				reader();
			}
			else
				printf("Buffer empty nothing to be eaten");
			break;
		case 3:
			exit(0);
			break;
		}
	}
	
	
}
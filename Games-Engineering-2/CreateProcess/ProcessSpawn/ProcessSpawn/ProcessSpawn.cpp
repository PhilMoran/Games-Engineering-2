// ProcessSpawn.cpp : Defines the entry point for the console application.
//
#include <Windows.h>
#include "stdafx.h"
#include <iostream>
#include <tchar.h>
#include <stdio.h>

using namespace std;


int main()
{
	
	int arow1[3];
	int arow2[3];
	int arow3[3];
	cout << "Matrix A" << endl;
	cout << "Enter 3 Values for the first row of matrix" << endl;
	cin >> arow1[0] >> arow1[1]>>arow1[2];
	cout << "Enter 3 Values for the second row of matrix" << endl;
	cin >> arow2[0] >> arow2[1] >> arow2[2];
	cout << "Enter 3 Values for the third row of matrix" << endl;
	cin >> arow3[0] >> arow3[1] >> arow3[2];

	int a[3][3]=
	{
		{arow1[0],arow1[1],arow1[2]},
		{arow2[0],arow2[1],arow2[2] },
		{arow3[0],arow3[1],arow3[2] }
	
	};

	int brow1[3];
	int brow2[3];
	int brow3[3];
	cout << "Matrix B" << endl;
	cout << "Enter 3 Values for the first row of matrix" << endl;
	cin >> brow1[0] >> brow1[1] >> brow1[2];
	cout << "Enter 3 Values for the second row of matrix" << endl;
	cin >> brow2[0] >> brow2[1] >> brow2[2];
	cout << "Enter 3 Values for the third row of matrix" << endl;
	cin >> brow3[0] >> brow3[1] >> brow3[2];

	int b[3][3] =
	{
		{ brow1[0],brow1[1],brow1[2] },
		{ brow2[0],brow2[1],brow2[2] },
		{ brow3[0],brow3[1],brow3[2] }

	};

	int c[3][3]=
	{
		{ arow1[0]*brow1[0]+arow1[1]*brow2[0]+arow1[2]*brow3[0], arow1[0] * brow1[1] + arow1[1] * brow2[1] + arow1[2] * brow3[0],arow1[0] * brow1[2] + arow1[1] * brow2[2] + arow1[2] * brow3[2] },
		{ arow2[0] * brow1[0] + arow2[1] * brow2[0] + arow2[2] * brow3[0], arow2[0] * brow1[1] + arow2[1] * brow2[1] + arow2[2] * brow3[0],arow2[0] * brow1[2] + arow2[1] * brow2[2] + arow2[2] * brow3[2] },
		{ arow3[0] * brow1[0] + arow3[1] * brow2[0] + arow3[2] * brow3[0], arow3[0] * brow1[1] + arow3[1] * brow2[1] + arow3[2] * brow3[0],arow3[0] * brow1[2] + arow3[1] * brow2[2] + arow3[2] * brow3[2] }
	};
	cout << "MATRIX A = "<< endl;
	for (int i = 0; i < 3; i++)
	{
		cout << a[i][0]<<",";
		cout << a[i][1]<< ",";
		cout << a[i][2]<< ",";
		cout << endl;
	}
	cout << "MATRIX B = " << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << b[i][0] << ",";
		cout << b[i][1] << ",";
		cout << b[i][2] << ",";
		cout << endl;


	}
	cout << "MATRIX C = " << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << c[i][0] << ",";
		cout << c[i][1] << ",";
		cout << c[i][2] << ",";
		cout << endl;


	}
	cin.get();

	system("Pause");
    return 0;
}


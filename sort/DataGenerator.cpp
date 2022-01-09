#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include "DataGenerator.h"
using namespace std;

template <class T>
void HoanVi(T &a, T &b)
{
	T x = a;
	a = b;
	b = x;
}

//-------------------------------------------------

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int* a, int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand()%n;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int) time(NULL));
	for (int i = 0; i < 10; i ++)
	{
		int r1 = rand()%n;
		int r2 = rand()%n;
		HoanVi(a[r1], a[r2]);
	}
}

void write_to_file(int * a, int n, string output){
	fstream fo;
	fo.open(output, ios::out);
	fo << n << endl;
	for (int i = 0; i < n; i++)
		fo << a[i] << " ";
	fo.close();
}

void GenerateData(int* a, int n, int dataType)
{
	switch (dataType)
	{
	case 0:	// ngẫu nhiên
		GenerateRandomData(a, n);
		write_to_file(a, n, "input_rand.txt");
		break;
	case 1:	// có thứ tự
		GenerateSortedData(a, n);
		write_to_file(a, n, "input_sorted.txt");
		break;
	case 2:	// có thứ tự ngược
		GenerateReverseData(a, n);
		write_to_file(a, n, "input_rev.txt");
		break;
	case 3:	// gần như có thứ tự
		GenerateNearlySortedData(a, n);
		write_to_file(a, n, "input_nsorted.txt");
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}
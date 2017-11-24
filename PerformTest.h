//Performance.h : Abstract class to test performance on two differnet methods of implementing priority queue.
#ifndef PERFORMTEST_H
#define PERFORMTEST_H
#include <ctime>
#include <iostream>
#include <Windows.h>
using namespace std;

class PerformTest
{
public:
	virtual void run(int operations = 0) = 0;
	virtual void test(int operations = 0)
	{
		LARGE_INTEGER nFreq, begin, end;
		QueryPerformanceFrequency(&nFreq);
		QueryPerformanceCounter(&begin);
		//clock_t begin = clock();
		this->run(operations);
		//clock_t end = clock();
		QueryPerformanceCounter(&end);
		double period = (end.QuadPart - begin.QuadPart) / (double)nFreq.QuadPart;
		cout <<period*1000 << " ms.\n";
	}
};

#endif
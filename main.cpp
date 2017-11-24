//main.cpp : Main function to test class:'MinHeap'
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "PerformanceTest\HeapTest.h"
#include "PerformanceTest\ListTest.h"
using namespace std;


int main()
{
	//initialize
	int operations = 1000;
	int values[6] = { 100, 500, 1000, 2000, 3000, 4000 };
	PerformTest* test;

	for (int i = 0; i < 6; i++)
	{
		cout << values[i] << " values for 1000 operations.\n";
		cout << "Heap test : ";
		test = new HeapTest(values[i], operations);
		test->test(operations);

		cout << "List test : ";
		test = new ListTest(values[i], operations);
		test->test(operations);

		cout << "================================" << endl;
	}

	system("pause");
	return 0;
}
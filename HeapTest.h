//HeapTest.h : Test performance of int max heap.
#ifndef HEAPTEST_H
#define HEAPTEST_H
#include "PerformTest.h"
#include "../PriorityQueue/MaxHeap.h"
#include <cstdlib>
using namespace std;

//template class:'HeapTest'
class HeapTest :public PerformTest
{
private:
	MaxHeap<int>* maxheap;
	int values;
public:
	//constructor
	HeapTest(int values, int operations)
	{
		this->values = values;
		maxheap=new MaxHeap<int>(values+operations);
		for (int i = 0; i < values; i++)
		{
			maxheap->push(rand() % values);
		}
	}

	virtual void run(int operations = 0)
	{
		for (int i = 0; i < operations; i++)
		{
			int choose = rand() % 2;
			if (choose == 1)
			{
				maxheap->push(rand() % values);
			}
			else
			{
				maxheap->pop();
			}
		}
	}
};
#endif
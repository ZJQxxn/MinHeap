//ListTest.h : Class to test unordered list.
#ifndef LISTTEST_H
#define LISTTEST_H
#include "PerformTest.h"
#include "../PriorityQueue/UnorderList.h"

class ListTest :public PerformTest
{
private:
	UnorderList<int>* list;
	int values;
public:
	//constructor
	ListTest(int values, int operations)
	{
		this->values = values;
		list = new UnorderList<int>(values + operations);
		for (int i = 0; i < values; i++)
		{
			list->push(rand() % values);
		}
	}

	virtual void run(int operations = 0)
	{
		for (int i = 0; i < operations; i++)
		{
			int choose = rand() % 2;
			if (choose == 1)
			{
				list->push(rand() % values);
			}
			else
			{
				list->pop();
			}
		}
	}
};
#endif
//UnorderList.h : Implementation of an unordered list to realize a max priority queue.
#ifndef UNORDERLIST_H
#define UNORDERLIST_H
#include "PriorityQueue.h"

//template unordered list
template<typename T>
class UnorderList :public PriorityQueue<T>
{
private:
	T* element;
	int size;
	int capacity;
public:
	UnorderList(int cap = 10);
	~UnorderList();

	//overrides
	virtual bool isEmpty();
	virtual void push(const T&);
	virtual void pop();
	virtual const T& getTop();
};


//Constructor and destructor
template<typename T>
UnorderList<T>::UnorderList(int cap)
{
	this->capacity = cap;
	this->size = 0;
	this->element = new int[this->capacity];
}

template<typename T>
UnorderList<T>::~UnorderList()
{
	delete this->element;
}


//Overrides
/*
	Determin whether list is empty.
*/
template<typename T>
bool UnorderList<T>::isEmpty()
{
	return (this->size == 0);
}

/*
	Push an eement into unordered list.
*/
template<typename T>
void UnorderList<T>::push(const T& ele)
{
	if (this->capacity == this->size)
	{
		cout << "Full heap!" << endl;
		return;
	}
	this->element[size++] = ele;
}

/*
	Pop the max element.
*/
template<typename T>
void UnorderList<T>::pop()
{
	if (this->isEmpty())
	{
		cout << "Empty heap!" << endl;
		return;
	}

	int maxIndex = 0;
	for (int i = 0; i < size; i++)
	{
		if (element[i] > element[maxIndex])
		{
			maxIndex = i;
		}
	}
	//delete max element
	element[maxIndex].~T();
	element[maxIndex] = element[--size];
}

/*
	Get max element.
*/
template<typename T>
const T& UnorderList<T>::getTop()
{
	T* max = &element[0];
	for (int i = 1; i < size; i++)
	{
		if (element[i] > *max)
		{
			max = &element[i];
		}
	}
	return *max;
}

#endif
//MaxHeap.h : Implementation of a maxheap template class.
#ifndef MAXHEAP_H
#define MAXHEAP_H
#include "PriorityQueue.h"

//template maxheap
template<typename T>
class MaxHeap :public PriorityQueue<T>
{
private:
	T* element;
	int size;
	int capacity;
public:
	MaxHeap(int cap = 10);
	~MaxHeap();

	//overrides
	virtual bool isEmpty();
	virtual void push(const T&);
	virtual void pop();
	virtual const T& getTop();
};


//Constructor and destructor
template<typename T>
MaxHeap<T>::MaxHeap(int cap)
{
	this->capacity = cap;
	this->size = 0;
	this->element = new int[this->capacity];
}

template<typename T>
MaxHeap<T>::~MaxHeap()
{
	delete this->element;
}


//Overrides
/*
	Determin whether heap is empty.
*/
template<typename T>
bool MaxHeap<T>::isEmpty()
{
	return (this->size == 0);
}

/*
	Push an element into max heap.
*/
template<typename T>
void MaxHeap<T>::push(const T& ele)
{
	if (this->capacity == this->size)
	{
		cout << "Full heap!" << endl;
		return;
	}
	if (this->isEmpty())
	{
		this->element[1] = ele;
		this->size++;
	}
	else
	{

		//add new element at back of element array
		int current = (size + 1);
		//if new element larger than its parent
		while (current!=1 && ele > this->element[current / 2])
		{
			this->element[current] = this->element[current / 2];
			current = current / 2;
		}
		//find correct position
		this->element[current] = ele;
		this->size++;
	}
}

/*
	Pop the max element.
*/
template<typename T>
void MaxHeap<T>::pop()
{
	if (this->isEmpty())
	{
		cout << "Empty heap!" << endl;
		return;
	}
	else
	{
		this->element[1].~T();

		//To satisfy definition of complete binary tree,
		//pick out the rightmost leaf node from the bottom.
		T& last = this->element[size];

		this->size--;

		//move from top to bottom
		int current = 1;
		int child = 2;
		while (child <= this->size)
		{
			//find larger child of current
			if (child < this->size)
			{
				child = (element[child] > element[child + 1]) ? child : (child + 1);
			}
			//until find correct positon for the 'last'
			if (last >= element[child])
			{
				break;
			}

			//move current down 
			element[current] = element[child];
			current = child;
			child = current * 2;
		}
		element[current] = last;
	}
}

/*
	Get max element.
*/
template<typename T>
const T& MaxHeap<T>::getTop()
{
	return this->element[1];
}

#endif
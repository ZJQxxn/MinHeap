//MinHeap.h : Implementation of a template min heap.
#ifndef MINHEAP_H
#define MINHEAP_H
#include "PriorityQueue.h"

//tmplate class:'MinHeap'
template <typename T>
class MinHeap :public PriorityQueue<T>
{
private:
	int size;
	int capacity;
	T* element;
public:
	MinHeap(int cap = 10);
	~MinHeap();

	//overrides
	virtual bool isEmpty();
	virtual void push(const T&);
	virtual void pop();
	virtual const T& getTop();
};


//Constructor and destructor
template<typename T>
MinHeap<T>::MinHeap(int cap)
{
	this->capacity = cap;
	this->size = 0;
	this->element = new int[this->capacity];
}

template<typename T>
MinHeap<T>::~MinHeap()
{
	delete this->element;
}


//Overrides
/*
	Determin whether heap is empty.
*/
template<typename T>
bool MinHeap<T>::isEmpty()
{
	return (this->size == 0);
}

/*
	Push an eement into min heap.
*/
template<typename T>
void MinHeap<T>::push(const T& ele)
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
		int current = (size+1);
		//if new element smaller than its parent
		while (current != 1 && ele < this->element[current / 2])
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
	Pop the minima element.
*/
template<typename T>
void MinHeap<T>::pop()
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
			//find smaller child of current
			if (child < this->size)
			{
				child = (element[child] < element[child + 1]) ? child : (child + 1);
			}
			//until find correct positon for the max element
			if (last <= element[child])
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
	Get minima element.
*/
template<typename T>
const T& MinHeap<T>::getTop()
{
	return this->element[1];
}


#endif
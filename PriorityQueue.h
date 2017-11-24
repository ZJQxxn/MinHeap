//PriorityQueue.h : Declaretion of abstract priority queue template class.
#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

//abstract class:'PriorityQueue'
template <typename T>
class PriorityQueue
{
public:
	virtual bool isEmpty() = 0;
	virtual void push(const T& ele) = 0;
	virtual void pop() = 0;
	virtual const T& getTop() = 0;
};
#endif
#pragma once
#include <iostream>

using namespace std;
template <class T>
	struct QueueNode
	{
		T value;
		QueueNode* next;
	};
template <class T>
class LinkQueue {
private:

	QueueNode<T>* front;
	QueueNode<T>* rear;
	int numItems;

public:
	LinkQueue();				// constructor with a size of the que
	~LinkQueue();						// destructor
	void enqueue(T);				// this is used to push an item into the LinkQueue
	void dequeue(T&);				// this is to pop without returning the object
	bool isEmpty();
	void clear();
};

// constructor
template <class T>
LinkQueue<T>::LinkQueue()
{
	front	= nullptr;
	rear	= nullptr;
	numItems = 0;
}

// Destructor
template <class T>
LinkQueue<T>::~LinkQueue()
{
	clear();
}

// Insert a value at the rear of the LinkQueue
template <class T>
void LinkQueue<T>::enqueue(T num)
{
	QueueNode<T>* newNode	= nullptr;
	newNode				= new QueueNode<T>;
	newNode->value		= num;
	newNode->next		= nullptr;

	if (isEmpty())
		front= rear		= newNode;
	else
	{
		rear->next		= newNode;
		rear			= newNode;
	}
	numItems++;
}

// remove value at front of LinkQueue
template <class T>
void LinkQueue<T>::dequeue(T& num)
{
	QueueNode<T>* temp = nullptr;
	if (isEmpty())
		cout << "The queue is empty...\n";
	else
	{
		num		= front->value;
		temp	= front->next;
		delete front;
		front	= temp;
		numItems--;
	}
}

// The function returns true if empty
// and false otherwise
template <class T>
bool LinkQueue<T>::isEmpty()
{
	bool status = true;
	if (numItems)
		status = false;
	return status;
}

// this function resets the front and rear
template <class T>
void LinkQueue<T>::clear()
{
	T value; // Dummy value

	while (!isEmpty())
	{
		dequeue(value);
	}
}
#pragma once
#include <iostream>

using namespace std;

template <class T>
class Queue {
private:
	T* queueArray;
	int queueSize, front, rear, numItems;

public:
	Queue(int size);				// constructor with a size of the que
	~Queue();						// destructor
	void enqueue(T);				// this is used to push an item into the queue
	void dequeue(T&);				// this is to pop without returning the object
	bool isEmpty();
	bool isFull();
	void clear();
};

// constructor
template <class T>
Queue<T>::Queue(int s)
{
	queueArray	= new T[s];
	queueSize	= s;
	front		= 0;
	rear		= 0;
	numItems	= 0;
}

// Destructor
template <class T>
Queue<T>::~Queue()
{
	delete[] queueArray;
	queueArray = nullptr;
}

// Insert a value at the rear of the queue
template <class T>
void Queue<T>::enqueue(T num)
{
	if (isFull())
		cout << "The queue is full.\n";
	else
	{
		// Calculate the new rear position
		rear = (rear + 1) % queueSize;
		// Insert new item
		queueArray[rear] = num;
		// Update item count
		numItems++;
	}
}

// remove value at front of queue
template <class T>
void Queue<T>::dequeue(T& num)
{
	if (isEmpty())
		cout << "The queue is Empty.\n";
	else
	{
		// Calculate the new rear position
		front = (front + 1) % queueSize;
		// Retrieve front item
		num = queueArray[front];
		// Update item count
		numItems--;
	}
}

// The function returns true if empty
// and false otherwise
template <class T>
bool Queue<T>::isEmpty()
{
	bool status = true;
	if (numItems)
		status = false;
	return status;
}
// this function returns true if it is full 
template <class T>
bool Queue<T>::isFull()
{
	bool status = true;
	if (numItems < queueSize)
	{
		status = false;
	}
	return status;
}

// this function resets the front and rear
template <class T>
void Queue<T>::clear()
{
	front = queueSize - 1;	// why have them as -1
	rear = queueSize - 1;	// 
	numItems = 0;
}
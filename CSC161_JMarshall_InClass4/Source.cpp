#include <iostream>
#include "MyArrayQueue.h"
#include "LinkQueue.h"
using std::cout;
using std::cin;
using std::endl;

int main() {

	// Constant for the Queue size
	const int SIZE = 5;

	// Create a queue object
	Queue<double> Queue(SIZE);

	cout << "Enqueing " << SIZE << " items...\n";

	for (int i = 0; i < SIZE; i++)
		Queue.enqueue(i * 1.1);

	// Attempt to enque again
	cout << "Now attempting to enqueue again..." << endl;
	Queue.enqueue(33.4);

	// dequeue and retrieve all items in queue
	cout << "The values in the queue were:\n";
	while (!Queue.isEmpty())
	{
		double value;
		Queue.dequeue(value);
		cout << value << endl;
	}


	// linked list

		// Constant for the Queue size
	const int SIZE2 = 5;

	// Create a queue object
	LinkQueue<double> LQueue;

	cout << "Enqueing linked " << SIZE << " items...but not really we dont have a limit here\n";

	for (int i = 0; i < SIZE; i++)
		LQueue.enqueue(i * 1.1);

	// Attempt to enque again
	cout << "Now attempting to enqueue again..." << endl;
	LQueue.enqueue(33.4);

	// dequeue and retrieve all items in queue
	cout << "The values in the queue were:\n";
	while (!LQueue.isEmpty())
	{
		double value;
		LQueue.dequeue(value);
		cout << value << endl;
	}



	return 0;
}
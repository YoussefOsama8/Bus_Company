#pragma once
#include "Node.h"

template <typename T>
class Queue
{
private:
	Node<T>* frontPtr;

	int count;
public:
	Queue();
	bool isEmpty() const;
	int getCount() const;
	bool enqueue(const T& newEntry);
	bool dequeue(T& frntEntry);
	bool peekFront(T& frntEntry)  const;
	void printq();
	~Queue();
};




template <typename T>
Queue<T>::Queue()//constructor
{
	frontPtr = nullptr;
	//backPtr = nullptr;
	count = 0;

}


template <typename T>
bool Queue<T>::isEmpty() const
{
	return !count;
}

template <typename T>
int Queue<T>::getCount() const
{
	return count;
}



template <typename T>
bool Queue<T>::enqueue(const T& newEntry)//adds a new entry to the back of the queue
{
	Node<T>* newNodePtr = new Node<T>(newEntry);

	// Insert the new node
	if (isEmpty())
		frontPtr = newNodePtr; // The queue is empty
	else {
		Node<T>* backPtr = frontPtr;
		while (backPtr->getNext() != nullptr)
			backPtr = backPtr->getNext();
		backPtr->setNext(newNodePtr); // The queue was not empty
	}
	//backPtr = newNodePtr; // New node is at back
	count++;
	return true;
} 





template <typename T>
bool Queue<T>::dequeue(T& frontEntry)//Removes the front of this queue
{
	if (isEmpty())
		return false;

	Node<T>* nodeToDeletePtr = frontPtr;
	frontEntry = frontPtr->getItem();//put the item of the first node in the queue to an object store it
	frontPtr = frontPtr->getNext();//the next node is the front of the queue

	delete nodeToDeletePtr;//delete the front node

	count--;
	return true;//item is removed

}
template <typename T>
void Queue<T>::printq()
{
	if (!frontPtr)
		return;
	Node<T>* p = frontPtr;
	while (p) {
		cout << *p->getItem();
		p = p->getNext();
	}

}



template <typename T>
bool Queue<T>::peekFront(T& frontEntry) const
{
	if (isEmpty())
		return false;

	frontEntry = frontPtr->getItem();
	return true;

}


template <typename T>
Queue<T>::~Queue()
{
}



//26.12
#ifndef _LISTS
#define _LISTS

#include "LinkedList.cpp"


template < class T >
class Stack
{
private:
	LinkedList<T> a;
public:

	Stack();
	Stack(const Stack<T>& aStack);
	virtual~Stack();

	bool isEmpty()const;
	bool push(const T& item);
	bool pop();
	T peek()const;
};



template<class T>
class Queue{
private:
	LinkedList<T> *listPtr;
public:
	Queue();
	Queue(const Queue<T>& aqueue);
	virtual ~Queue();

	bool isEmpty()const;
	bool enqueue(const T& item);
	bool dequeue();
	T peekFront()const;
};

#endif
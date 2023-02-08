//22.12
#ifndef _LINKED_LIST
#define _LINKED_LIST

#include "ListInterface.h"
#include "Node.cpp"
#include "PrecondViolatedExcep.h"
#include <cassert>

template <class T>
class LinkedList:public ListInterface<T>{

private:
	Node<T>* headPtr;//pointer to first node in chain
	int itemCount;
	//Locates a specified node in a linked list.
	//@pre position is the number of the desired node;
	//		position  >= 1 and position <= itemCount.
	//@post The node is found and apointer to it is returned.
	//@parama position The number of the node to locate.
	//@return A pointer to the node at the given position.
	Node<T>* getNodeAt(int position) const;

public:

	LinkedList();
	//LinkedList(const LinkedList<T>& alist);
	virtual~LinkedList();

	bool isEmpty()const;
	int getLenght()const;
	bool insert(int position, const T& item);
	bool remove(int position);
	void clear();
	

	T getEntry(int position)const throw (PrecondViolatedExcep);
	void setEntry(int position, const T& item) throw (PrecondViolatedExcep);


};
#endif
//22.12
#include "LinkedList.h"


template <class T>
LinkedList<T>::LinkedList(){
	headPtr = nullptr;
	itemCount = 0;
}
/*template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& alist){

}*/
template<class T>
LinkedList<T>::~LinkedList(){
	clear();
}
template <class T>
bool LinkedList<T>::isEmpty()const {
	
	if (itemCount == 0)
	return true;
	else
	return false;
}
template <class T>
int LinkedList<T> ::getLenght() const {
	return itemCount;
}
template<class T>
Node<T>* LinkedList<T>::getNodeAt(int position)const{
	
	assert((position >= 1) && (position <= itemCount));
		Node<T>*curPtr = headPtr;
	for (int i = 1; i < position; i++){
		curPtr=curPtr->getnext();///////////
	}
	return curPtr;

}
template <class T>
bool LinkedList<T> ::insert(int position, const T& item){
	bool ableToInsert(position >= 1 && position <= itemCount + 1);
		if (ableToInsert)
		{
			Node<T>* newNodePtr = new Node<T>(item);

			if (position == 1){
				newNodePtr->setnext(headPtr);
				headPtr = newNodePtr;
			}
			else{
				Node<T>* prevPtr = getNodeAt(position - 1);

				newNodePtr->setnext(prevPtr->getnext());
					prevPtr->setnext(newNodePtr);
			}
			itemCount++;
		}
		return ableToInsert;
}
template<class T>
bool LinkedList<T>::remove(int position){
	bool ableToremove = (position >= 1 && position <= itemCount);
	if (ableToremove){
		Node<T>*currPtr = nullptr;
		if (position == 1){
			currPtr = headPtr;
			headPtr = headPtr->getnext();
		}
		else{
			Node<T>* prevPtr = getNodeAt(position - 1);
			currPtr = prevPtr->getnext();
			prevPtr->setnext(currPtr->getnext());
		}
		currPtr->setnext(nullptr);
		delete currPtr;
		currPtr = nullptr;///////

		itemCount--;
	}
	return ableToremove;
}
template <class T>
void LinkedList<T>::clear(){
	while (!isEmpty())
		remove(1);
}
template <class T>
T LinkedList<T>::getEntry(int position)const throw (PrecondViolatedExcep){
	bool ableToget = (position >= 1 && position <= itemCount);
	if (ableToget)
	{
		Node<T>* nodePtr = getNodeAt(position);
		return nodePtr->getItem();
	}
	else
	{
		string message = "getEntry() called with an empty list or invalid position.";
		throw(PrecondViolatedExcep(message));
	}
}
template<class T>
void LinkedList<T>::setEntry(int position, const T& item) throw (PrecondViolatedExcep){
	bool ableToset = (position >= 1 && position <= itemCount);
	if (ableToset){
		Node<T>* nodePtr = getNodeAt(position);
		nodePtr->setItem(item);
	}
	else{
		string message = "setEntry() called with an empty list or invalid position.";
		throw(PrecondViolatedExcep(message));
	}
}


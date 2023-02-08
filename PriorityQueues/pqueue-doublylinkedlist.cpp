#include "pqueue-doublylinkedlist.h"


int DoublyLinkedListPriorityQueue::compareStrings(string one, string two){
	return  one.compare(two);
}
void DoublyLinkedListPriorityQueue::Deallocate(Entry * &list){
	while (!isEmpty()) dequeueMin();
}
DoublyLinkedListPriorityQueue::DoublyLinkedListPriorityQueue(){
	list = new Entry();
	list->next = nullptr;
	list->previous = nullptr;
	number = 0;
}
DoublyLinkedListPriorityQueue::~DoublyLinkedListPriorityQueue(){
	Deallocate(list);
}
int DoublyLinkedListPriorityQueue::size(){
	return number;
}
bool DoublyLinkedListPriorityQueue::isEmpty(){
	if (number==0)	return 1;
	else return 0;
}
void DoublyLinkedListPriorityQueue::enqueue(string value){
	newOne = new Entry();
	newOne->name = value;
	newOne->previous = nullptr;
	newOne->next = nullptr;
	
	if (isEmpty()){
		list = newOne;
	}
	else{
		newOne->next = list;
		list->previous = newOne;
		list = newOne;
	}
	
	number++;
}
string DoublyLinkedListPriorityQueue::peek(){//search for the min
	if (isEmpty())exit(0);
	Entry *min = new Entry();
	Entry *curr = new Entry();
	curr = list;
	min = curr;
	while (curr != nullptr){
		if (compareStrings(min->name, curr->name)!=-1){
			min = curr;
		}
		curr = curr->next;
	}
	return min->name;
}
string DoublyLinkedListPriorityQueue::dequeueMin(){
	string min = peek();
	Entry *curr = new Entry();
	curr = list;
	while (compareStrings(min, curr->name) != 0)
		curr = curr->next;
	
	Entry *temp = new Entry();
	temp = curr;
	if (curr == list){
		if (curr->next!=nullptr)
		curr->next->previous = nullptr;
		list = curr->next;
	}

	if (curr->previous!=nullptr)
	curr->previous->next = curr->next;
	if (curr->next!=nullptr)
	curr->next->previous = curr->previous;

	temp->next = nullptr;
	delete temp;
	temp = nullptr;

	number--;

	return min;
}

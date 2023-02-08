#include "pqueue-linkedlist.h"


int LinkedListPriorityQueue::compareStrings(string one, string two){
	return one.compare(two);
}
void LinkedListPriorityQueue::InsertSorted(Entry * & list, Entry *newOne){
	if (isEmpty() || compareStrings(list->name, newOne->name) != -1){
		newOne->next = list;
		list = newOne;
		
	}
	else{
		Entry *prev = new Entry(), *curr = new Entry();
		
		curr->next = list;
		while (curr != nullptr&&compareStrings(curr->name, newOne->name) == -1){//searching for its place
			prev = curr;
			curr = curr->next;
}
		newOne->next = curr;
		prev->next = newOne;
		
	}
	number++;
}
void LinkedListPriorityQueue::Deallocate(Entry * &list){
	while (!isEmpty()) dequeueMin();
}
LinkedListPriorityQueue::LinkedListPriorityQueue(){
	list = new Entry();
	list->next=nullptr;
	number = 0;
}
LinkedListPriorityQueue::~LinkedListPriorityQueue(){
	Deallocate(list);
}
int LinkedListPriorityQueue::size(){
	return number;
}
bool LinkedListPriorityQueue::isEmpty(){
	if (number == 0)
		return 1;
	else return 0;
	
}
void  LinkedListPriorityQueue::enqueue(string value){
	newOne = new Entry();
	newOne->name = value;
	InsertSorted(list, newOne);
	
}
string LinkedListPriorityQueue::peek(){
	if (isEmpty()){ exit(0); }
	return list->name;
}
string LinkedListPriorityQueue::dequeueMin(){
	if (isEmpty()){ exit(0); }
	string b = peek();
	Entry *curr = new Entry(); 
	curr = list;
	list = list->next;

	curr->next = nullptr;
	delete curr;
	curr = nullptr;

	number--;

	return b;
}

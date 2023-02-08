

#include "pqueue-vector.h"


void VectorPriorityQueue:: doubleCapacity(){
	
		numAllocated *= 2;
		string *newarr=new string[numAllocated];
		for (int i = 0; i < numUsed; i++){
			newarr[i] = arr[i];
		}
		for (int i = 0; i < numUsed; i++){
			arr[i].clear();
		}
		delete[]arr;
		arr = newarr;
	
}
int VectorPriorityQueue::compareStrings(string one, string two){
	return one.compare(two);
}
void VectorPriorityQueue::removeAt(int number){
	for (int i = number; i < numUsed-1; i++){
		arr[i] = arr[i + 1];
	}
		arr[--numUsed].clear();
}
VectorPriorityQueue::VectorPriorityQueue(){
	arr = new string[10];
	numAllocated = 10;
	numUsed = 0;
}
VectorPriorityQueue::~VectorPriorityQueue(){
	delete [] arr;
}
int  VectorPriorityQueue::size(){
	return numUsed;
}
bool VectorPriorityQueue::isEmpty(){
	if (numUsed == 0){
		return 1;
	}
	else return 0;
}
void VectorPriorityQueue::enqueue(string value){
	if (numUsed == numAllocated)
	doubleCapacity();
	arr[numUsed] = value;
	numUsed++;
}
string VectorPriorityQueue:: peek(){
	if(isEmpty()) exit(0);
	else {
		string temp;
		int index = 0;
		for (int i = 1; i < numUsed; i++){
			if (compareStrings(arr[index], arr[i]) == 1)
				index = i;
		}
		return arr[index];
	}
}
string VectorPriorityQueue:: dequeueMin(){
	if (isEmpty()){ exit(0); }
	string temp;
	int index=0;
	for (int i = 1; i < numUsed; i++){
		if (compareStrings(arr[index], arr[i]) == 1)
			index = i;
	}
	string v = arr[index];
	removeAt(index);
	return v;
}

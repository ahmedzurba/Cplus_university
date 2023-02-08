#include "pqueue-heap.h"



int HeapPriorityQueue::compareStrings(string  one, string two){
	return one.compare(two);
}
void HeapPriorityQueue::Swap(int one, int two){
	string  temp = arr[one];
	arr[one] = arr[two];
	arr[two] = temp;
}
void HeapPriorityQueue::doubleCapacity(){
	numAllocated *= 2;
	string *newarr = new string[numAllocated];
	for (int i = 0; i < numUsed; i++){
		newarr[i] = arr[i];
	}
	for (int i = 0; i < numUsed; i++){
		arr[i].clear();
	}
	delete[]arr;
	arr = newarr;
}
void HeapPriorityQueue::FindMin(int numUsed){

}
void HeapPriorityQueue::Readjust(int number){

}
HeapPriorityQueue::HeapPriorityQueue(){
	arr = new string[10];
	numAllocated = 10;
	numUsed = 0;
}
HeapPriorityQueue::~HeapPriorityQueue(){
	delete [] arr;
}
int HeapPriorityQueue::size(){
	return numUsed;
}
bool HeapPriorityQueue::isEmpty(){
	if (numUsed == 0){
		return 1;
	}
	else return 0;
}
void HeapPriorityQueue::enqueue(string value){
	if (numUsed == numAllocated){
		doubleCapacity();
	}
	if (isEmpty()){
		arr[0] = value;
	}
	else{
		bool inPlace = false;
		arr[numUsed] = value;
		int currindex = numUsed;
		while (currindex >= 0 && !inPlace){
			if (compareStrings(arr[(currindex - 1) / 2], arr[currindex])==1){
				Swap((currindex - 1) / 2, currindex);
				currindex = (currindex - 1) / 2;
			}
			else inPlace = true;
		}
	}
	numUsed++;
}
string HeapPriorityQueue::peek(){
	if (isEmpty()) exit(0);

	return arr[0];
}
string HeapPriorityQueue::dequeueMin(){
	if (isEmpty()) exit(0);
	string min = arr[0];
	arr[0] = arr[numUsed - 1];
	arr[numUsed - 1].clear();
	numUsed--;
	int curr = 0;
	bool inPlace = false;
	while (!inPlace){
		int minm = curr * 2 + 1;
		if (minm < numUsed){//if there left child
			if (minm + 1 < numUsed)//if there right child
				if (compareStrings(arr[minm], arr[minm + 1]) == 1)//compare left and right and return minm
					minm++;
			if (compareStrings(arr[curr], arr[minm]) == 1){//compare the curr with the minm
				swap(arr[curr], arr[minm]);
				curr = minm;
			}
			else inPlace = true;
		}
		
		else inPlace = true;//if leaf it is in place
		
	}

	return min;
}
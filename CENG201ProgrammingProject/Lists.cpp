//24.12
#include "Lists.h"

template<class T>
Stack<T>::Stack(){

}
template<class T>
Stack<T>::Stack(const Stack& astack){
	
}
template<class T>
Stack<T>::~Stack(){
	a.clear();
}
template<class T>
bool Stack<T>::isEmpty()const{
	return a.isEmpty();
}
template<class T>
bool Stack<T>::push(const T& item){
	return a.insert(1, item);
}
template<class T>
bool Stack<T>::pop(){
	return a.remove(1);
}
template<class T>
T Stack<T>::peek()const{
	return a.getEntry(1);
}

template<class T>
Queue<T>::Queue(){
	listPtr = new LinkedList < T > ;
}
template<class T>
Queue<T>::Queue(const Queue<T>& aqueue){

}
template<class T>
Queue<T>::~Queue(){
}
template<class T>
bool Queue<T>::isEmpty()const{
	return listPtr->isEmpty();
}
template<class T>
bool Queue<T>::enqueue(const T& item){
	return listPtr->insert(listPtr->getLenght()+1, item);
}
template<class T>
bool Queue<T>::dequeue(){
	return listPtr->remove(1);
}
template<class T>
T Queue<T>::peekFront()const{
	return listPtr->getEntry(1);
}
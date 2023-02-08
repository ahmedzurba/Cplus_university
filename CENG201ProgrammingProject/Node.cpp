#include "Node.h"
#include<cstddef>

template<class Itemtype>
Node<Itemtype>::Node(){
	next = nullptr;
}
template<class Itemtype>
Node<Itemtype>::Node(const Itemtype &anitem){
	item = anitem;
	next = nullptr;
}
template<class Itemtype>
Node<Itemtype>::Node(const Itemtype &anitem, Node<Itemtype>* nextnode){
	item = anitem;
	next = nextnode;
}
template<class Itemtype>
void Node<Itemtype>::setItem(const Itemtype &newitem){
	item = newitem;
}
template<class Itemtype>
void Node<Itemtype>::setnext(Node<Itemtype>*nextitem){
	next = nextitem;
}
template<class Itemtype>
Itemtype Node<Itemtype>::getItem()const{
	return item;
}
template<class Itemtype>
Node<Itemtype>* Node<Itemtype>::getnext()const{
	return next;
}


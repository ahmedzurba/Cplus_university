//21.12
#ifndef _NODE
#define _NODE
template <class Itemtype>
class Node
{
private:
	Itemtype item;
	Node<Itemtype> *next;
public:
	Node();
	Node(const Itemtype &anitem);
	Node(const Itemtype &anitem, Node<Itemtype>* nextnode);
	void setItem(const Itemtype &newitem);
	void setnext(Node<Itemtype>*nextitem);
	Itemtype getItem()const;
	Node<Itemtype>* getnext()const;
};

#endif
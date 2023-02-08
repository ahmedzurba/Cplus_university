//22.12
#ifndef _LIST_INTERFACE
#define _LIST_INTERFACE

template<class T>
class ListInterface{

public:

	virtual bool isEmpty()const = 0;

	virtual int getLenght() const = 0;

	virtual bool insert(int position, const T& item) = 0;

	virtual bool remove(int position) = 0;

	virtual void clear() = 0;

	virtual T getEntry(int position) const = 0;

	virtual void setEntry(int position, const T & item) = 0;

};
#endif


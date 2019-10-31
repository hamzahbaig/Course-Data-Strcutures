#ifndef __STACK_CPP
#define __STACK_CPP
#include "stack.h"

template <class T>
Stack<T>::Stack()
{

}
    
template <class T>
Stack<T>::Stack(const Stack<T>& otherStack)
{
	LinkedList<T> temp0 = otherStack.list;
	ListItem<T> *temp = temp0.getTail();
	while(temp!=NULL)
	{
		push(temp->value);
		temp=temp->prev;
	}
}

template <class T>
Stack<T>::~Stack()
{
	while (isEmpty()!=1)
	{
		pop();
	}
}

template <class T>
void Stack<T>::push(T item)
{
	list.insertAtHead(item);
}

template <class T>
T Stack<T>::top()
{
	T data;
	data = list.getHead()->value;
	return data;
}

template <class T>
T Stack<T>::pop()
{
	T data;
	data = list.getHead()->value;
	list.deleteHead();
	return data;
}

template <class T>
int Stack<T>::length()
{
	return list.length();
}

template <class T>
bool Stack<T>::isEmpty()
{
	if (length()==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

#endif

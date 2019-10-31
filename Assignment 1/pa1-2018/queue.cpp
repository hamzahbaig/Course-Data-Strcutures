#ifndef __QUEUE_CPP
#define __QUEUE_CPP
#include "queue.h"

template <class T>
Queue<T>::Queue()
{

}
    
template <class T>
Queue<T>::Queue(const Queue<T>& otherQueue)
{
	LinkedList<T> temp0= otherQueue.list;
	ListItem<T> *temp = temp0.getTail();
	while (temp!=NULL)
	{
		enqueue(temp->value);
		temp=temp->prev;
	}

}

template <class T>
Queue<T>::~Queue()
{
	while (isEmpty()!=1)
	{
		dequeue();
	}

}

template <class T>
void Queue<T>::enqueue(T item)
{
	list.insertAtHead(item);
}

template <class T>
T Queue<T>::front()
{
	T data;
	data = list.getTail()->value;
	return data;
}

template <class T>
T Queue<T>::dequeue()
{
	T data;
	data = list.getTail()->value;
	list.deleteTail();
	return data;
}

template <class T>
int Queue<T>::length()
{
	return list.length();
}

template <class T>
bool Queue<T>::isEmpty()
{
	 if (length() == 0)
	 {
	 	return 1;
	 }
	 else
	 {
	 	return 0;
	 }
}


#endif

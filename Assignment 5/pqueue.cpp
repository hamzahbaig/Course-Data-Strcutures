#ifndef PQUEUE__CPP
#define PQUEUE__CPP
#include "pqueue.h"

template<class T>
pqueue<T>::pqueue(int heapSize)
{
 size = heapSize;	
 heap = new T (size);
}

template<class T>
T pqueue<T>::ExtractMin()
{
  return heap->extractMin();
}


#endif

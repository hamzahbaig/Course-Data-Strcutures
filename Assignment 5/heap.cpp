#ifndef __HEAP_CPP
#define __HEAP_CPP
#include "heap.h"

template <class T> 
MinHeap<T>::MinHeap(int cap)
{
  harr =  new T [cap];
  heap_size = 0;
}

// ((left(i) >= harr[i]) && (right(i) >= harr[i]))
template <class T> 
void MinHeap<T>::MinHeapify(int i)
{
 bool noRight = ((2*i) +2) > heap_size;	
 bool noLeft = 	((2*i) +1) > heap_size;	
 bool breakCnd =  noLeft || noRight  || ((harr[i] < left(i)) && (harr[i] < right(i)));
 if(!breakCnd){
   T leftChild  =  left(i);
   T rightChild = right(i);
   if(leftChild < harr[i] && rightChild < harr[i]){
   	if(leftChild<rightChild){
     swap(harr[(2*i)+1],harr[i]);
     MinHeapify((2*i)+1);
   	}else{
     swap(harr[(2*i)+2],harr[i]);
     MinHeapify((2*i)+2);
   	}
   }
   else if(leftChild < harr[i]){
     swap(harr[(2*i)+1],harr[i]);
     MinHeapify((2*i)+1);
   }
   else if(rightChild < harr[i]){
     swap(harr[(2*i)+2],harr[i]);
     MinHeapify((2*i)+2);
   }
 }
 return;
}

template <class T>  
T MinHeap<T>::parent(int i) 
{ 
  return harr[(i-1)/2];
}

template <class T>  
T MinHeap<T>::left(int i)
{
  return harr[(2*i)+1];
}

template <class T>  
T MinHeap<T>::right(int i)
{
  return harr[(2*i)+2];
}

template <class T>  
T MinHeap<T>::extractMin()
{
 T toReturn = harr[0];	
 harr[0] = harr[heap_size-1];
 heap_size--;
 MinHeapify(0);
 return toReturn;
}

template <class T>  
void MinHeap<T>::decreaseKey(int i, T new_val)
{
	harr[i] = new_val;
	int index = i; 
	while(1)
	{
	if(index == 0 || parent(index) < harr[index] || parent(index) == harr[index] ){
		break;
	 }
		else if(parent(index) > harr[index]){
		swap(harr[index],harr[(index-1)/2]);
		index = (index-1)/2;
	}
	}
}
template <class T>  
T MinHeap<T>::getMin()
{
   return harr[0];
}

/*template <class T>  
void MinHeap<T>::deleteKey(int i)
{ 
if(i< heap_size)
{
  decreaseKey(i,INT_MIN);
  extractMin();
}  
}*/
 
template <class T>  
void MinHeap<T>::insertKey(T k)
{	
  harr[heap_size] = k;
  int index = heap_size; 
  while(1)
  {
   if(index == 0 || parent(index) < harr[index] || parent(index) == harr[index] ){
     break;
  	}
   else if(parent(index) > harr[index]){
   	swap(harr[index],harr[(index-1)/2]);
   	index = (index-1)/2;
   }
  }
  heap_size++; 
}

template <class T> 
T* MinHeap<T>::getHeap()
{
	return harr;
}

/*void MinHeap::display_heap() {
	cout << "Heap: ";
	int k = 0;
	for(int i=0;i< heap_size;i++){
		cout << harr[i] << " ";
		k++; 
	}
	cout <<"elements= " << k <<  endl;
	cout <<"heap_size= " <<heap_size << endl;
}*/
#endif
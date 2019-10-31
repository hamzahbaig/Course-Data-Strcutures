#ifndef __HEAP_CPP
#define __HEAP_CPP
#include "heap.h"
#include "list.h"
#include<iostream>
#include<climits>


MinHeap::MinHeap(int cap)
{
	heap_size = 0;
	capacity = cap;
	harr = new int[cap];
}

void MinHeap::MinHeapify(int i)
{
	int breakingCondtion = i;
	int left1 = left(i);
    int right1 = right(i);
    if (left1 < heap_size && harr[left1] < harr[i])
    {
        breakingCondtion = left1;
    }
    if (right1 < heap_size && harr[right1] < harr[breakingCondtion])
    {
        breakingCondtion = right1;
    }
    if (breakingCondtion != i)
    {
        swap(&harr[breakingCondtion],&harr[i]);
        MinHeapify(breakingCondtion);
    }
}
 
int MinHeap::parent(int i)
{
	return (i-1)/2;
}
 
int MinHeap::left(int i)
{
	return (2*i + 1);
}
 
int MinHeap::right(int i)
{
	return (2*i + 2);
}
 
int MinHeap::extractMin()
{
	if(heap_size <= 0)
	{
		return 0;
	}
	else if (heap_size == 1)
	{
		heap_size--;
		return harr[0];
	}
	else
	{
		int temp = harr[0];
		harr[0] = harr[heap_size-1];
		heap_size--;
		MinHeapify(0);

		return temp;
	}
}
 
void MinHeap::decreaseKey(int i, int new_val)
{
	harr[i] = new_val;
	while (i != 0 && harr[parent(i)] > harr[i])
	{
		swap(&harr[parent(i)],&harr[i]);
		i =parent(i); 
	}
}
 
int MinHeap::getMin()
{
	return harr[0];
}
 
void MinHeap::deleteKey(int i)
{
	if(i >=heap_size)
	{
		// cout << "NOT POSSIBLE" << endl;
		return;
	}
	else
	{
		decreaseKey(i,INT_MIN);
		extractMin();
	}
}
 
void MinHeap::insertKey(int k)
{
	if (heap_size == capacity)
	{
		cout << "SIZE IS FULL";
		return;
	}

	heap_size++;
	int index = heap_size - 1;
	harr[index] = k;
	while (index != 0 && harr[parent(index)] > harr[index])
	{
		swap(&harr[parent(index)],&harr[index]);
		index =parent(index); 
	}
}

int* MinHeap::getHeap()
{
	return harr;
}

void MinHeap::swap(int *first, int *second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}

#endif
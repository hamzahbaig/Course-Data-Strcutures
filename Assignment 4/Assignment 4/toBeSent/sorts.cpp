#ifndef __SORTS_CPP
#define __SORTS_CPP
#include "sorts.h"
#include "heap.cpp"


//=====================================================================================
vector<long> InsertionSort(vector<long> nums)
{	
	int key;
	int j;
	int lenOfVect = nums.size();
	int *sortedArray = new int[lenOfVect];
	for(int i =0 ; i< lenOfVect; i++)
	{
		sortedArray[i] = nums[i];
	}
	for (int i =0; i < lenOfVect; i++)
	{
		key = sortedArray[i];
		j = i-1;
		while(j >=0 && sortedArray[j] > key )
		{
			sortedArray[j+1] = sortedArray[j];
			j = j - 1;
		}
		sortedArray[j+1] = key;
	}
	nums.clear();
	for (int i =0 ;i < lenOfVect ; i++)
	{
		nums.push_back(sortedArray[i]);
	}
	return nums;
}

//=====================================================================================
List<long>* merge(List<long> *leftList, List<long>*rightList)
{
	
	ListItem<long> *tempL = leftList->getHead();
	ListItem<long> *tempR = rightList->getHead();
	List<long>* sortedList =  new List<long>();
	while(1)
	{
		if(tempL == NULL)
		{
			while(tempR !=NULL)
			{
				sortedList->insertAtHead(tempR->value);
				tempR = tempR->next;
			}
			break;
		}
		else if(tempR == NULL)
		{
			while(tempL !=NULL)
			{
				sortedList->insertAtHead(tempL->value);
				tempL = tempL->next;
			}
			break;
		}
		else if(tempL->value <= tempR->value)
		{
        sortedList->insertAtHead(tempL->value);
        tempL = tempL-> next;
		}
		else if (tempR->value < tempL->value) 
		{
		sortedList->insertAtHead(tempR->value);
        tempR = tempR-> next;
		}
	}
	sortedList->reverse();
	return sortedList; 
}

List<long>* mergeSort1(List<long>* list1, int lenOfVect)
{
	if (lenOfVect > 1)
	{
		int mid = lenOfVect/2;
		List<long>* leftList   =  new List<long>();
		List<long>* rightList  =  new List<long>();
		ListItem<long> *temp = list1->getHead();
		for(int i=0;i<mid;i++)
		{
		 	leftList->insertAtHead(temp->value);	
		 	temp = temp->next;
		}
		for(int i=mid; i <lenOfVect; i++)
		{
			rightList->insertAtHead(temp->value);
			temp= temp->next;
		}
		leftList  = mergeSort1(leftList,mid);
		rightList = mergeSort1(rightList,lenOfVect-mid);
		List<long>* sortedList = merge(leftList,rightList);
		return sortedList;
	}
	return list1;	
}

vector<long> MergeSort(vector<long> nums)
{
	List<long>* list1 =  new List<long>();
	int lenOfVect = nums.size();
	for(int i=0;i<lenOfVect;i++)
	{
		list1->insertAtHead(nums[i]);
	}
	List<long>* sortedList = mergeSort1(list1,lenOfVect);
	ListItem<long> *temp = sortedList->getHead();
	nums.clear();
    for(int i=0;i<lenOfVect;i++)
	{
		nums.push_back(temp->value);
		temp = temp -> next;
	}
	return nums;
}


//=====================================================================================
vector<long> QuickSortArray(vector<long> nums)
{
	int lenOfVect = nums.size();
	long *sortedArray = new long[lenOfVect];
	for(int i =0 ; i< lenOfVect; i++)
	{
		sortedArray[i] = nums[i];
	}

	quickSort(sortedArray,0,lenOfVect-1);
	nums.clear();
	for (int i =0 ;i < lenOfVect ; i++)
	{
		nums.push_back(sortedArray[i]);
	}
	return nums;
}

int seperation(long sortedArray[], int low, int high)
{
	int pivot = sortedArray[high] ;//last element as pivot
	int i = (low-1);

	for(int j = low; j <=high-1; j++)
	{
		if (sortedArray[j] <= pivot)
		{
			i++;
			swap(&sortedArray[i],&sortedArray[j]);
		}
	}
	swap(&sortedArray[i+1],&sortedArray[high]);
	return(i+1);
}

void quickSort(long sortedArray[], int low, int high)
{
	if (low < high)
	{
		int partition = seperation(sortedArray,low,high);
		quickSort(sortedArray,low,partition-1);
		quickSort(sortedArray,partition+1,high);
	}
}

void swap(long *first, long *second)
{
	long temp = *first;
	*first = *second;
	*second = temp;
}
//=====================================================================================
vector<long> QuickSortList(vector<long> nums)
{
	List<long>* sortedList =  new List<long>();
	int lenOfVect = nums.size();
	for(int i=0;i<lenOfVect;i++)
	{
		sortedList->insertAtHead(nums[i]);
	}
	// List<long>* sortedList = 
	quickSort1(sortedList->getHead(),sortedList->getTail());
	ListItem<long> *temp= sortedList->getHead();
	nums.clear();
    for(int i=0;i<lenOfVect;i++)
	{
		nums.push_back(temp->value);
		temp = temp -> next;
	}
	return nums;
}

void quickSort1(ListItem<long> *low, ListItem<long>* high)
{
	if(high!=NULL && low != high && low != high->next)
	{
		ListItem<long>* partition = seperation1(low,high);
		quickSort1(low,partition->prev);
		quickSort1(partition->next,high);
	}
}

ListItem<long>* seperation1(ListItem<long> *low, ListItem<long>* high)
{
	long pivot = high->value;

	ListItem<long>* i= low->prev;

	for (ListItem<long>* j = low ; j != high; j=j->next)
	{
		if(j->value <= pivot)
		{
			if(i==NULL)
			{
				i= low;
			}
			else
			{
				i=i->next;
			}
			swap(&(i->value),&(j->value));
		}
	}
	if(i==NULL)
			{
				i= low;
			}
			else
			{
				i=i->next;
			}
	swap(&(i->value),&(high->value));
	return i;

}

//=====================================================================================
vector<long> HeapSort(vector<long> nums)
{
	int lenOfVect = nums.size();
	int *sortedArray = new int[lenOfVect];
	for(int i =0 ; i< lenOfVect; i++)
	{
		sortedArray[i] = nums[i];
	}
	MinHeap* heap = new MinHeap(lenOfVect);
	for(int i =0 ;i <lenOfVect;i++)
	{
		heap->insertKey(sortedArray[i]);
	}
	for (int i=0 ;i < lenOfVect; i++)
	{
		sortedArray[i]= heap->extractMin();
	}
	nums.clear();
	for (int i =0 ;i < lenOfVect ; i++)
	{
		nums.push_back(sortedArray[i]);
	}
	return nums;



}


#endif
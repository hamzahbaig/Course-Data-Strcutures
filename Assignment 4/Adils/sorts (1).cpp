#ifndef __SORTS_CPP
#define __SORTS_CPP
#include "sorts.h"
#include "heap.cpp"

//=====================================================================================
vector<long> InsertionSort(vector<long> myVector)
{

	const int len = myVector.size();
	long nums[len];
	for(int i=0;i<len;i++){
		nums[i] = myVector[i];
	}

	int value,i,j;
	for(i=0;i<len;i++) {
		value = nums[i];
		j=i-1;
		while(j>=0 && nums[j] > value){
				nums[j+1] =nums[j];
				j--;
			} 
        nums[j+1]=value;
		}

	for(int i=0;i<len;i++){
		myVector[i] = nums[i];
	}

  return myVector;
}

//=====================================================================================

List<long>* Merge(List<long>* left,List<long>* right)
{
	int sizeLeft = left->length();
	int sizeRight = right->length();
	ListItem<long> *tempL = left->getHead();
	ListItem<long> *tempR = right->getHead();
	List<long>* final =  new List<long>();
	while(1)
	{
		if(tempL == NULL)
		{
			while(tempR !=NULL)
			{
				final->insertAtHead(tempR->value);
				tempR = tempR->next;
			}
			break;
		}
		else if(tempR == NULL)
		{
			while(tempL !=NULL)
			{
				final->insertAtHead(tempL->value);
				tempL = tempL->next;
			}
			break;
		}
		else if(tempL->value <= tempR->value)
		{
        final->insertAtHead(tempL->value);
        tempL = tempL-> next;
		}
		else if (tempR->value < tempL->value) 
		{
		final->insertAtHead(tempR->value);
        tempR = tempR-> next;
		}
	}
	final->reverse();
	return final; 
}

List<long>* MergeSortLL(List<long>* nums, int len)
{
	if (len > 1)
	{
		int mid = len/2;
		List<long>* left   =  new List<long>();
		List<long>* right  =  new List<long>();
		ListItem<long> *temp = nums->getHead();
		for(int i=0;i<len;i++)
		{
		 if(i<mid)	left->insertAtHead(temp->value);	
		 else if (i >= mid) right->insertAtHead(temp->value);
		 temp = temp->next;
		}
		left  = MergeSortLL(left,mid);
		right = MergeSortLL(right,len-mid);
		List<long>* final = Merge(left,right);
		return final;
	}
	return nums;	
}

vector<long> MergeSort(vector<long> nums)
{
	List<long>* myList =  new List<long>();
	int len = nums.size();
	for(int i=0;i<len;i++)
	{
		myList->insertAtHead(nums[i]);
	}
	List<long>* final = MergeSortLL(myList,len);
	ListItem<long> *temp = final->getHead();
    for(int i=0;i<len;i++)
	{
		nums[i] = temp->value;
		temp = temp -> next;
	}
	return nums;
}



//=====================================================================================
int parting()

void QuickRecursive(long* nums, int start,int end)
{
	if(len > 1){
	long pivot = nums[len-1];
	long* start= &nums[0];
	long* end = &nums[len-2];
	int lcount = 0;
	while (1) {
		if(start == end) break;
        else if(*start > pivot)
        {
        	while(1) {	
              if(*end < pivot){
              	swap(*start,*end);
              	break;
              }
              else{
              	end--;
              } 
              if(start == end) break; 
        	}
        }
        else{
        lcount++;
        start++;
        }
        if(start == end) break;
	}
	swap(*start,nums[len-1]);
	QuickRecursive(nums,start,index-1);
	QuickRecursive(nums,index+1,end);
}
return;
}

vector<long> QuickSortArray(vector<long> myVector)
{
	const int len = myVector.size();
	long *nums =  new long [len];
	for(int i=0;i<len;i++){
		nums[i] = myVector[i];
	}

	QuickRecursive(nums,0,len-1);

		for(int i=0;i<len;i++) {
		myVector[i] = nums[i];
	}

  return myVector;

}

//=====================================================================================
List<long>* MergeQuick(List<long>* left,List<long>* right)
{
	ListItem<long> *tempL = left->getHead();
	ListItem<long> *tempR = right->getHead();
	List<long>* final =  new List<long>();
	while(1)
	{
		while(tempL != NULL){
			final ->insertAtTail(tempL->value);
			tempL = tempL->next;
		}
		while(tempR != NULL){
			final ->insertAtTail(tempR->value);
			tempR = tempR->next;
		}
	}
	return final; 
}

List<long>* QuickSortLL(List<long>* nums, int len)
{
	if (len > 1)
	{
		int mid = len/2;
		List<long>* left   =  new List<long>();
		List<long>* right  =  new List<long>();
		long pivot = (nums->getHead())->value;
		int llen = 0;
		int rlen = 0;
		ListItem<long> *temp = nums->getHead();
		for(int i=0;i<len;i++)
		{
		 if(temp->value < pivot){
		 	left->insertAtHead(temp->value);
		 	llen++;	
		 }	
		 else if (temp->value >= pivot){
		 	right->insertAtHead(temp->value);
		 	rlen++;
		 }
		 temp = temp->next;
		}
		left  = QuickSortLL(left,llen);
		right = QuickSortLL(right,rlen);
		List<long>* final = MergeQuick(left,right);
		return final;
	}
	return nums;	
}

vector<long> QuickSortList(vector<long> nums)
{
   List<long>* myList =  new List<long>();
	int len = nums.size();
	for(int i=0;i<len;i++)
	{
		myList->insertAtHead(nums[i]);
	}
	List<long>* final = MergeSortLL(myList,len);
	ListItem<long> *temp = final->getHead();
    for(int i=0;i<len;i++)
	{
		nums[i] = temp->value;
		temp = temp -> next;
	}
	return nums;
}

//=====================================================================================
vector<long> HeapSort(vector<long> nums)
{

}

#endif



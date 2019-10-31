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
vector<long> MergeSort(vector<long> nums)
{
	List<long>*list1 = new List<long>();
	int lenOfVect = nums.size();
	for(int i =0 ; i <lenOfVect; i++)
	{
		cout << "HELLO";
		list1->insertAtHead(nums[i]);
	}
	List<long> *sortedList = MergeSortLL(list1,lenOfVect);
}

// List<long>* mergeSort1(List<long>* list1, int lenOfVect)
// {
// 	if(lenOfVect >1)
// 	{
// 		int middle = lenOfVect/2;
// 		List<long> *leftList = new List<long>();
// 		List<long> *rightList = new List<long>();
// 		ListItem<long> *temp = list1->getHead();
// 		for (int i =0; i < middle ; i++)
// 		{
// 			leftList->insertAtHead(temp->value);
// 			temp = temp->next;
// 		}
// 		for (int i= middle; i < lenOfVect ;i++)
// 		{
// 			rightList->insertAtHead(temp->value);
// 			temp=temp->next;
// 		}
// 		leftList = mergeSort1(leftList,middle);
// 		rightList = mergeSort1(rightList,lenOfVect-middle);
// 		List<long> *sortedList = new List<long>();
// 		// merge(leftList,rightList);
// 		return sortedList;
// 	}
// 	return list1;
// }

List<long>* MergeSortLL(List<long>* nums, int len)
{
	if (len > 1)
	{
		cout << "HEELLO";
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
		// List<long>* final = new List<long>();
		// return final;
	}
	return nums;	
}
List<long>* merge(List<long> *leftList, List<long>*rightList)
{
	// ListItem<long> *temp = leftList->getHead();
	// while(temp!=NULL)
	// {
	// 	cout << temp->value << " " ;
	// 	temp=temp->next;
	// }	
	// temp = leftList->getHead();
	// while(temp!=NULL)
	// {
	// 	cout << temp->next << " ";
	// 	temp=temp->next;
	// }
}



//=====================================================================================
vector<long> QuickSortArray(vector<long> nums)
{
	int lenOfVect = nums.size();
	int *sortedArray = new int[lenOfVect];
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

int seperation(int sortedArray[], int low, int high)
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

void quickSort(int sortedArray[], int low, int high)
{
	if (low < high)
	{
		int partition = seperation(sortedArray,low,high);
		quickSort(sortedArray,low,partition-1);
		quickSort(sortedArray,partition+1,high);
	}
}

void swap(int *first, int *second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}
//=====================================================================================
vector<long> QuickSortList(vector<long> nums)
{

}

//=====================================================================================
vector<long> HeapSort(vector<long> nums)
{

}

int main()
{
	vector<long> A;
	
	A.push_back(10);
	A.push_back(2);
	A.push_back(4);
	A.push_back(5);
	A.push_back(8);
	A.push_back(6);
	A.push_back(7);
	A.push_back(20);
	A.push_back(25);
	A.push_back(3);
	A.push_back(9);

	 MergeSort(A);
	//  cout << endl;
	// for (int i =0 ; i < B.size(); i++)
	// {
	// 	cout << B[i] << " ";
	// }
}
#endif
#ifndef __SORTS_H
#define __SORTS_H

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "list.cpp" // Your Own Implementation


using namespace std;

vector<long> InsertionSort(vector<long> nums);
vector<long> MergeSort(vector<long> nums);
List<long>* mergeSort1(List<long>* list1, int lenOfVect);
List<long>* merge(List<long> *leftList, List<long>*rightList);
vector<long> QuickSortArray(vector<long> nums);
vector<long> QuickSortList(vector<long> nums);
List<long> *mergeQuick(List<long>* leftList, List<long>* rightList);
void quickSort1(ListItem<long> *low, ListItem<long>* high);
ListItem<long>* seperation1(ListItem<long> *low, ListItem<long>* high);
vector<long> HeapSort(vector<long> nums);
void swap(long *first, long *second);
void quickSort(long sortedArray[], int low, int high);
int seperation(long sortedArray[], int low, int high);


#endif
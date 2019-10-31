#include <iostream>
#include "bst.h"
#include <vector>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <string>


using namespace std;

template <class T>
void rightrecursive(BST<T>* mergedTree,vector<myPair<T> >& mergetree_data,int start, int end)
{
	if (start > end)
	{
		return ;
	}

	int mid = (start+end)/2;
	mergedTree->insert1(mergetree_data[mid].value,mergetree_data[mid].key);
	rightrecursive(mergedTree,mergetree_data,start,mid-1);
	rightrecursive(mergedTree,mergetree_data,mid+1,end);

	return ;
}

template <class T>
void fillingVect(node<T>* p, vector<myPair<T> > &tree_data)
{
	
	if(p==NULL)
	{
		return;
	}

	fillingVect(p->left,tree_data);
	tree_data.push_back({p->key,p->value});
	fillingVect(p->right,tree_data);

}
template <class T>
vector<myPair<T> > merge(vector<myPair<T> > &tree1_data, vector<myPair<T> > &tree2_data)
{
	vector<myPair<T> > mergetree_data=tree1_data;
	for(int i =0 ; i<tree2_data.size() ; i++)
	{
		int counter=0;
		int flag=0;
		for (int j=0 ; j < mergetree_data.size() ; j++)
		{
			if(tree2_data[i].key == mergetree_data[j].key)
			{
				flag=1;
				break;
			}
		}
		if(flag == 0)
		{
			mergetree_data.push_back({tree2_data[i].key,tree2_data[i].value});
		}
	}
	return mergetree_data;
}

template<class T>
void bubbleSort(vector<myPair<T> >& mergetree_data)
{
  for (int i=0; i <mergetree_data.size(); i++)
  {
  	for (int j=0 ; j <mergetree_data.size()-1 ; j++)
  	{
  		if(mergetree_data[j].key > mergetree_data[j+1].key)
  		{
  			myPair<T> temp = mergetree_data[j];
  			mergetree_data[j]=mergetree_data[j+1];
  			mergetree_data[j+1]=temp;
  		}
  	}
  }
}


template <class T>
BST<T>* bst_Union(BST<T>* tree1,BST<T>* tree2){
	vector<myPair<T> > tree1_data;
	vector<myPair<T> > tree2_data;
	vector<myPair<T> > mergetree_data;
	vector<myPair<T> > rightPart;
	vector<myPair<T> > leftPart;
	BST<T>* mergedTree = new BST<T>();
	// BST<int>* tree2=new BST<int>();


	fillingVect(tree1->getRoot(),tree1_data);
	fillingVect(tree2->getRoot(),tree2_data);
	// PRINTING..
	// for (int i=0; i< tree1_data.size();i++)
	// {
	// 	cout << "KEY: " <<  tree1_data[i].key << " VALUE: " << tree1_data[i].value << endl;
	// }
	// cout << "---------------------" << endl;
	// for (int i=0; i< tree2_data.size();i++)
	// {
	// 	cout << "KEY: " <<  tree2_data[i].key << " VALUE: " << tree2_data[i].value << endl;
	// }
	mergetree_data = merge(tree1_data,tree2_data);
	bubbleSort(mergetree_data);
	// cout << "-----MERGED TREE------"  << endl;
	// for (int i=0; i< mergetree_data.size();i++)
	// {
	// 	cout << "KEY: " <<  mergetree_data[i].key << " VALUE: " << mergetree_data[i].value << endl;
	// }
	//MERGING RIGHT PART..
	rightrecursive(mergedTree,mergetree_data,0,mergetree_data.size()-1);

	return mergedTree;

}

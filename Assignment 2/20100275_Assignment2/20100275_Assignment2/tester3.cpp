#include <iostream>
#include "bst.cpp"
#include "union.cpp"
// #include "union1.cpp"
#include <set>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <vector>


using namespace std;

int main()
{
	BST<int>* tree1=new BST<int>();
	BST<int>* tree2=new BST<int>();
	// TREE 1 insertion
	tree1->insert("a",1);
	tree1->insert("b",10);
	tree1->insert("c",1);
	tree1->insert("d",10);
	tree1->insert("k",12);
	// tree1->print(tree1->getRoot());
	// TREE 2 insertion
	tree2->insert("d",0);
	tree2->insert("d",11);
	tree2->insert("e",2);
	tree2->insert("f",3);
	BST<int>* mergedTree = bst_Union(tree1,tree2);
	cout << "-------FINAL PUTPUT------ "<< endl;
	mergedTree->print(mergedTree->getRoot());
	// // cout << mergedTree->getRoot()->left->left->key << endl;
}
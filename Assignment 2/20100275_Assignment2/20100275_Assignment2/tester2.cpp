#include <cstdlib>
#include <vector>
#include <iostream>
#include <cstring>
#include <sstream>
#include "bst.h"
#include "bst.cpp"
#include <fstream> 
using namespace std;




int main()
{
	//insertion....,.....
	node<int>* A;
	BST<int>* tree=new BST<int>();
//------------------------
	tree->insert("a",3);
	tree->insert("b",1);
	tree->insert("c",11);
	tree->insert("d",10);
	tree->insert("e",2);
	tree->insert("f",0);
	tree->insert("g",12);
	// tree->insert("h",71);
	// tree->insert("i",13);
	// tree->insert("j",3);
	// tree->insert("k",1);
	// tree->insert("l",61);
	// tree->insert("m",18);
	// tree->insert("n",30);
	// tree->insert("o",50);
	// tree->insert("p",4);
	// tree->insert("q",11);
	// tree->insert("r",52);
	// tree->insert("r",54);
	// tree->insert("r",56);
	// tree->insert("r",55);
	// tree->insert("r",80);
	// A=tree->rotateleft(tree->getRoot());
	// cout << endl << "Height: " << tree->height(tree->getRoot()) << endl; ;
	// cout << endl << "Max Height " << tree->MaxHeigth(tree->getRoot()) << endl ;
	// gets root
	A=tree->getRoot();
	//print 
	cout << "ORIGINAL     ";
	tree->print(A);
	// tree->print(tree->findparent(A->key));
	cout << endl << "Height: " << tree->height(A) << endl; ;
	// cout << endl << "Balancing Factor: " << tree->balanceFactor(A->right) ;
	cout << endl;
//------------------------------------
	//Search
	// cout << endl << endl << "Search Result: VALUE-> " << tree->search(13)->value;
	// cout << "DELETEION    ";
	// tree->delete_node(90);
	// tree->delete_node(18);
	// tree->delete_node(50);
	// tree->delete_node(24);
	// tree->delete_node(68);
	// tree->delete_node(54);
	// tree->print(tree->getRoot());
	// cout << endl << "Height: " << tree->height(tree->getRoot()) << endl; ;
	// find min is working
	// cout << endl;
	// cout << "FIND MIN     ";
	// cout << tree->findmin(A)->value
	// cout << "REMOVING MIN ";
	// tree->removemin(tree->getRoot());
	// tree->removemin(tree->getRoot());
	// tree->removemin(tree->getRoot());
	// tree->removemin(tree->getRoot());
	// tree->removemin(tree->getRoot());
	// tree->removemin(tree->getRoot());
	// tree->removemin(tree->getRoot());
	// tree->removemin(tree->getRoot());
	// tree->removemin(tree->getRoot());
	// tree->removemin(tree->getRoot());
	// tree->removemin(tree->getRoot());








	// cout << tree->findmin(tree->getRoot())->value << endl;
	// cout << tree->findparent(tree->getRoot()->key)->value << endl;

	// A=tree->getRoot();


	// tree->print(A);
	// cout << endl;
	// // cout << "Parent: " << tree->findparent(A->left->right->key)->value;
	// // // cout << endl << "AGAIN: ";
	// // tree->removemin(A);
	// // tree->print(A);



}
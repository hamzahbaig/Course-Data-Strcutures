#ifndef __BST_CPP
#define __BST_CPP
#include "bst.h"
#include <iostream>
#include <queue>
// HELPER FUNCTIONS HERE...
template <class T>
BST<T>::BST(){
	root = NULL;
}

template <class T>
BST<T>:: ~BST(){

    // your destructor code goes here
}

template <class T>
int BST<T> :: height (node<T>* p){

	if(p==NULL)
	{
		return 0;
	}
	else
	{
		return p->height;
	}
}

template <class T>
int BST<T> :: balanceFactor(node<T>* p){

	if (p==NULL)
	{
		return 0;
	}
	else
	{
		return (height(p->left) - height(p->right));
	}
}

template <class T>
int BST<T>::MaxHeigth(node<T>* p)
{
	 if (p==NULL)
	 {
	 	return 0;
	 }

    return max(height(p->left), height(p->right))+1;

}

template <class T>
void BST<T> :: fixHeight(node<T>* p){
    // use this function to fix height of a node after insertion or deletion.
	p->height=MaxHeigth(p);
}

// ROTATING HELPERS 
template <class T>
node<T>* BST<T> :: rotateleft(node<T>* p)
{

	node<T>* temp ;
	temp= p->right;
	p->right = temp->left;
	temp->left=p;
	fixHeight(p);
	fixHeight(temp);
    return temp;
}

template <class T>
node<T>* BST<T> :: rotateright(node<T>* p)
{
	node<T> *temp;
    temp = p->left;
    p->left = temp->right;
    temp->right = p;
    fixHeight(p);
    fixHeight(temp);
    return temp;
}

template <class T>
node<T>* BST<T> :: balance(node<T>* p)
{   

    int balance = balanceFactor(p);

    // Left-Right Case
    
    if(balance > 1)
    {
    	if (p->left->right != NULL)
    	{
    		if(p->left->right->key > p->left->key)	
    		{
    			p->left = rotateleft(p->left);
    			return rotateright(p);
    		}
    	}
    }
    // Right-Left Case
    
   if(balance < -1 )
    {
		if(p->right->left != NULL)
		{
			if(p->right->left->key < p->right->key)
			{
    			p->right=rotateright(p->right);
    			return rotateleft(p);
    		}
    	}

    }
    // Right-Right case
   if(balance < -1 && p->right->right->key > p->right->key)
    {
    	return rotateleft(p);
    }
    // Left Left Case
   if(balance > 1 && p->left->left->key < p->left->key)
    {
    	return rotateright(p);
    }
    
   		fixHeight(p);
    	return p;
    
    // fixHeight(p);
    // 	return p;
}
// CLASS FUNCTIONS HERE
template <class T>
void BST<T> :: insert(string value,T k){
    root = insertHelper(value,k,root);
}
// insertion helpe  r
template <class T>
node<T>* BST<T> :: insertHelper(string value,T k, node<T> *p)
{ 
	node<T>* insert; 
	if(p == NULL)
	{
		insert = new node<T>(k,value);
		return balance(insert);
	}
	if(k <= p->key)
	{
		p->left = insertHelper(value,k,p->left);
	}
	else
	{
		p->right=insertHelper(value,k,p->right);
	}
    return balance(p);
}




template<class T>
node<T>* BST<T> :: search(T key)
{	
	if(root==NULL)
	{
		return NULL;
	}

	node<T>* current = root;

	while(current!=NULL)
	{
		if(current->key==key)
		{
			return current;
		}
		else if(key <= current->key)
		{
			current=current->left;
		}
		else
		{
			current=current->right;
		}
	}

    return NULL;
    // Search code goes here.
}
// DELETE HELPER FUNCTIONS
template<class T>
node<T>* BST<T> :: findmin(node<T> *p){

	if (p==NULL)
	{
		return NULL;
	}
	while (p->left!= NULL)
	{
		p=p->left;
	}
    return p;
}

template<class T>
node<T>* BST<T>::removemin(node<T>* p)
{

	node<T>*tobeDeleted = findmin(p);
	node<T>*tobeDeletedParent = findparent(tobeDeleted->key); 
	if(tobeDeleted==tobeDeletedParent)
	{
		p=p->right;
		delete(tobeDeleted);
		root=p;

	}
	else if(tobeDeleted->right != NULL)
	{
		if(tobeDeleted->key > tobeDeletedParent->key)
		{
			tobeDeletedParent->right=tobeDeleted->right;
			delete(tobeDeleted);
		}
		else
		{
			tobeDeletedParent->left=tobeDeleted->right;
			delete(tobeDeleted);
		}
	}
	else
	{
		tobeDeletedParent->left=tobeDeleted->left;
		delete(tobeDeleted);
	}

    return balance(p);
}

template<class T>
node<T>* BST<T>::findparent(T k)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(root->key==k)
	{
		return root;
	}
	node<T>* current = root;

	while(current != NULL)
	{
		if(k < current->key)
		{
			if(current->left->key==k)
			{
				return current;
			}
			else
			{
				current=current->left;
			}
		}
		else
		{
			if(current->right->key == k)
			{
				return current;
			}
			else
			{
				current=current->right;
			}
		}
	}
}


template<class T>
void BST<T>::delete_node(T k){
    root = remove(root, k);
}

template<class T>
node<T>*  BST<T>::remove(node<T>* p, T k) // k key deletion from p tree
{
	if(p==NULL)
	{
		return p;
	}
	if(k < p->key)
	{
		p->left=remove(p->left,k);
	}
	else if (k > p->key)
	{
		p->right=remove(p->right,k);
	}

	else
	{
		if(p->left ==NULL && p->right == NULL)
		{
			delete(p);
			return NULL;
		}
		else if(p->left == NULL)
		{
			node<T>* temp= p->right;
			delete(p);
			return temp;
		}
		else if(p->right==NULL)
		{
			node<T>* temp=p->left;
			delete(p);
			return temp;
		}

		node<T>*temp = findmin(p->right);
		p->key=temp->key;
		p->value=temp->value;
		p->right=remove(p->right,temp->key);
	}
    return balance(p);
    // This function uses findmin and deletemin to delete arbitrary node in the tree.
}
template<class T>
node<T>* BST<T>::getRoot(){
    return root;
}

template<class T>
void BST<T>::print(node<T>* p)
{
	if(p==NULL) return;

	cout << p->value << " " ;
	print(p->left);
	print(p->right);


}
#endif

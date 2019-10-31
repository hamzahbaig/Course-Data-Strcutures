#include "bst.cpp"
#ifndef __BST_H
#define __BST_H
#include <vector>
#include <string>
using namespace std;

template <class T>
struct myPair{
    T key;
    string value;
    myPair(T key,string value)
    {
        this->key = key;
        this->value= value;
    }
};

template <class T>
class node{
    public:
    
    string value; 
    T key;
    node *left;
    node *right;
    int height;
    
    node (T key, string value){
        this->key = key;
        this->value = value;
        left = NULL;
        right = NULL;
        height = 1;
    }

};


template <class T>
class BST {
    private:
    node<T> *root;

    
    // HELPER FUNCTIONS
    void fixHeight(node<T>* p);
    node<T>* rotateleft(node<T>* p);
    node<T>* rotateright(node<T>* p);
    int balanceFactor(node<T>* p);
    node<T>* balance(node<T>* p);
    node<T>* insertHelper(string value,T k, node<T> *p);
    node<T>* mergeintoright(string value,T k, node<T> *p,string flag);
    node<T>* mergeintoleft(string value,T k, node<T> *p,string flag);
    node<T>* findmin(node<T> *p);
    node<T>* removemin(node<T> *p);
    node<T>* remove(node<T> *p,T k);
    node<T>* findparent(T k);

   public:
    BST(); // CONSTRUCTOR 
    ~BST(); // DESTRUCTOR
    void insert(string val, T k); // inserts the given key value pair into the tree
    void delete_node(T k);    
    node<T>* search(T k); // takes key as an input and returns the node pointer if key exists and NULL pointer if key does not exists 
    node<T>* getRoot();
    int height (node<T>* p);
    void print(node<T>* p);
    int MaxHeigth(node<T>* p);
    void insert1(string val, T k,string flag); // inserts the given key value pair into the tree






    




};


#endif
#ifndef CHAINING_CPP
#define CHAINING_CPP
#include <string>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <string>
#include <math.h>
#include "Chaining.h"
#include "hashfunctions.cpp"

HashC::HashC(int size){

	tableSize = size;
	hashTable = new LinkedList<string>[size];
    
}
HashC::~HashC(){

}

unsigned long HashC :: hash(string input){
	unsigned long hash;
	hash = divCompression(bitHash(input),tableSize);
	return hash;
}

void HashC::insert(string word){
	// unsigned long key;
	// key = hash(word);
	hashTable[hash(word)].insertAtHead(word);
  return;
}

ListItem<string>* HashC :: lookup(string word){
	unsigned long key;
	key = hash(word);
	ListItem<string>* temp ;
	temp = hashTable[key].searchFor(word);
	if (temp != NULL)
	{
		return temp;
	}
	else
	{
		return NULL;
	}

}

void HashC :: deleteWord(string word){
	unsigned long key;
	key = hash(word);
	ListItem<string>* temp = hashTable[key].getHead();
	while(temp!=NULL)
	{
		if(temp->value == word)
		{
			hashTable[key].deleteElement(word);
		}
		temp = temp->next;
	}
  return;
}

// int main()
// {
// 	HashC A(5);
// 	cout << A.hash("ABC") << endl;
// 	A.insert("ABC") ;
// 	cout << "VALUE: " << A.hashTable[2].getHead()->value << endl;
// 	// A.deleteWord("ABC");
// 	// cout << "VALUE: " << A.hashTable[2].getHead()->value;
// 	cout << "RESULT: " <<  A.lookup("ABC")->value << endl;


// }
#endif
#ifndef DOUBLEHASH_CPP
#define DOUBLEHASH_CPP
#include "doubleHash.h"
#include "hashfunctions.cpp"
HashD::HashD(){
    tableSize = 10000; // you cant change this
    hashTable =  new block*[tableSize];
    for (int i=0; i<tableSize; i++)
    {
        hashTable[i] = NULL;
    }
}

HashD::~HashD(){
	for (int i=0; i<tableSize; i++)
    {
        delete (hashTable[i]);
    }   

}

unsigned long HashD :: hash1(string value){
    int Hash= divCompression(bitHash(value),tableSize);   
    return Hash; 
}

unsigned long HashD :: hash2(string value){
	int M = tableSize -3;
	return (M - ((hash1(value)) % M));
}

void HashD::resizeTable(){
	int tempTableSize = tableSize;
    tableSize = 2* tableSize;
    block** temp = new block*[tableSize];
    for(int i=0;i<tableSize;i++)
    {
        temp[i] = NULL;
    }
    count = 0;
    int j;
    for(int i =0 ;i < tempTableSize ;i++)
    {
      if(hashTable[i]!=NULL)
      {
        if(hashTable[i]->value != "MyMarker")
        {
            int hash_1 = hash1(hashTable[i]->value);
			int index = hash_1;
			int hash_2 = hash2(hashTable[i]->value);
			j=0;
            while(1)
            {   
              if(temp[index] == NULL)
             {
                temp[index] = new block(index,hashTable[i]->value);
                count++;
                break;
             }
		     j++;
		     index = hash_1 + (j*hash_2);
		     index = index % tableSize;
            }
        }
      }
    }
    hashTable = temp;
    return;
}

void HashD::insert(string value){
	int hash_1 = hash1(value);
	int index = hash_1;
	int i=0;
	int hash_2 = hash2(value);
    while(1)
    {
      if(hashTable[index] == NULL || hashTable[index]->value == "MyMarker" )
     {
        hashTable[index] = new block(index,value);
        count++;
        if((double) count/tableSize >= 0.25)
        {
            this->resizeTable();
        }
        break;
     }
     
     i++;
     index = hash_1 + (i*hash_2);
     index = index % tableSize;
    }
  return;
}

void HashD::deleteWord(string value){
	int hash_1 = hash1(value);
	int index = hash_1;
	int hash_2 = hash2(value);
	int i=0;
	while(1)
    {
        if(hashTable[index] == NULL)
        {
            break;
        }
        else if(hashTable[index]->value == value && hashTable[index]->key == index)
        {
            hashTable[index]->value = "MyMarker";
            hashTable[index]->key = -1;
            count--;
        }
     i++;
     index = hash_1 + (i*hash_2);
     index = index % tableSize;
    }
    return;
}

block* HashD::lookup(string value){
	int hash_1 = hash1(value);
	int hash_2 = hash2(value);
	int index = hash_1;
	int i=0;    
	while(1)
    {
        if (hashTable[index] == NULL)
        {
          break; 
        }
        else if(hashTable[index]->value == value && hashTable[index]->key == index)
        {
          return hashTable[index];
        }
	i++;
    index = hash_1 + (i*hash_2);
    index = index % tableSize;   
    }
    return NULL;
   }


#endif
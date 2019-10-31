#ifndef LINEARPROBING_CPP
#define LINEARPROBING_CPP

#include "linearProbing.h"
#include "hashfunctions.cpp"


HashL::HashL(){ 
    tableSize = 1000; // you cant change this
    hashTable =  new block*[tableSize];
    for (int i=0; i<tableSize; i++)
    {
        hashTable[i] = NULL;
    }
}

HashL::~HashL(){
    for (int i=0; i<tableSize; i++)
    {
        delete (hashTable[i]);
    }   
}

unsigned long HashL :: hash(string value){
    int Hash= divCompression(bitHash(value),tableSize);   
    return Hash; 
}

void HashL::resizeTable(){
    int tempTableSize = tableSize;
    tableSize = 2* tableSize;
    block** temp = new block*[tableSize];
    for(int i=0;i<tableSize;i++)
    {
        temp[i] = NULL;
    }
    count = 0;
    int index;
    for(int i =0 ;i < tempTableSize ;i++)
    {
      if(hashTable[i]!=NULL)
      {
        if(hashTable[i]->value != "MyMarker")
        {
            index = hash(hashTable[i]->value);
            while(1)
            {   
              if(temp[index] == NULL)
             {
                temp[index] = new block(index,hashTable[i]->value);
                count++;
                break;
             }
             if(index==tableSize-1)
             {
                index=0;
             }
             else
             {
                index++;
             }
            }
        }
      }
    }
    hashTable = temp;
    return;
}
    


void HashL::insert(string value){
    int index = hash(value);
    while(1)
    {
      if(hashTable[index] == NULL || hashTable[index]->value == "MyMarker" )
     {
        hashTable[index] = new block(index,value);
        count++;
        if((double) count/tableSize >= 0.25)
        {
            resizeTable();
        }
        break;
     }
     if(index==tableSize-1)
     {
        index=0;  
     }
     else
     {
        index++;
     }
    }
  return;
}

void HashL::deleteWord(string value){
 int index = hash(value);
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
    index++; 
    }
    return;
}


block* HashL::lookup(string value){
    int index = hash(value);
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
    index ++;  
    }
    return NULL;
   
}
void HashL::print()
{
    for(int i=0;i<tableSize;i++)
    {
        if(hashTable[i] != NULL)
            cout << i << "- Value->" <<hashTable[i]->value << " Key->" << hashTable[i]->key << endl;

    }
}
// int main()
// {
//         HashL* map = new HashL();
//         for(int i=0;i<2000;i++)
//         {
//             map->insert("ADIL");
//         }
//         map->print();
//         cout << "TABLESIZE: " << map->tableSize << endl;
//         cout << "ENTRIES FILLED: " << map->count;

// }
#endif

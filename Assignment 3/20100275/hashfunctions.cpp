#ifndef HASHFUNCTIONS_CPP
#define HASHFUNCTIONS_CPP
#include <string>
#include <cmath>
#include <iostream>


// this takes in a string and returns a 64bit hash.
unsigned long polyHash(std::string value,int a = 5){
	unsigned long hash;
	if (value == "")
	{
		return 0;
	}
	else
	{
		hash = value[0]*pow(a,value.length()-1) + polyHash(value.erase(0,1));
	}
	return hash;
	
}
//does some bitwise operation and generates a 64bit hash.
unsigned long bitHash(std::string value){
	unsigned long bitwise_hash = 0;
	int len = value.length();
	for (int i =0 ; i < len ; i++)
	{
		bitwise_hash ^= (bitwise_hash << 20) | (bitwise_hash >> 10) + int(value[i]);
	}
	return bitwise_hash;
}
// Size is the size of array maintained by the hashtable.
unsigned long divCompression(unsigned long hash,long size){
    return (hash % size);
}
// multiplication addition and division compression. 
unsigned long madCompression(unsigned long hash,long size,int m = 1993,int a = 1637){
	
    return (((hash*m)+a) % size);
}
// 'm' and 'a' can take any value
// int main()
// {
// 	cout << "PLOYHASH: " << (polyHash("ABC")) << endl;
// 	cout << "BITWISE_HASH: " << (bitHash("ABC")) << endl;
// }
#endif
// you may write your own program to test these functions.
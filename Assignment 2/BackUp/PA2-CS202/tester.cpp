#include <cstdlib>
#include <vector>
#include <iostream>
#include <cstring>
#include <sstream>
#include "tree.h"
#include "tree.cpp"
#include <fstream> 
using namespace std;


int main()
{
	string lca;
	vector<string> v;
	Tree A("input_test.txt");
	TreeItem* C;
	C= A.getHead();
	// cout << C->FChild->FChild->NextS->value ;
	v= A.Locate("CS 578");
	for (int i=0 ; i < v.size(); i ++)
	{
		cout << v[i] << "    " ;
	}
	cout << v.size() << endl << endl;
	v= A.Locate("summary-1.docx");
	for (int i=0 ; i < v.size(); i ++)
	{
		cout << v[i] << "    " ;
	}
	cout << v.size() << endl << endl;

	lca = A.LComAc("s04e01.avi","summary-1.docx");
	cout << lca << endl;
	cout << endl ;
	vector<string> result;
	cout<<endl;
	cout << A.countFiles();
	
}
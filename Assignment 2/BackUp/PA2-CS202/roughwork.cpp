#include <cstdlib>
#include <vector>
#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream> 
using namespace std;

void remove_slash(string path)
{
	cout << path << endl << endl;
	int i =0;
	while(path[0] != '0')
		{
			if (path.at(i) == '\\')
			{
				// remove_slash(path.substr(i+1,path.length()));
				cout  << path.substr(0,i) << endl;
				// cout << path.substr(i+1,path.length()-i);
				path=path.substr(i+1,path.length());
				i=0;
			}
				i++;

		}
}

void remove_Start(vector<string> &directory)
{
	string temp = "\\0";
	for (int i =0 ; i < directory.size() ; i++)
	{
		// directory[i]=directory[i].substr(3,directory[i].length()-2);
		directory[i].append(temp);
	}
	
}

int main()
{
	vector <string> directory;
	string a;
	string target;
	ifstream fout;
	fout.open("input.txt");
	while(getline(fout,a))
	{
		directory.push_back(a);
	}

	for (int i=0; i < directory.size(); i++)
	{
		cout << directory[i] << endl ;
	}
	cout << endl;
	remove_Start(directory);
	// cout << directory[0] << endl << directory[1];
	remove_slash(directory[0]);
	remove_slash(directory[13]);
}
#ifndef __TREE_CPP
#define __LIST_CPP
#include "tree.h"
#include <fstream>

Tree::Tree()
{
	head=NULL;
}

void Tree::remove_Start(vector<string> &directory)
{
	string temp = "\\0";
	for (int i =0 ; i < directory.size() ; i++)
	{
		directory[i].append(temp);
	}
}

Tree::Tree(string file)
{
	head=NULL;
	string a;
	ifstream fout;
	fout.open(file);
	while(getline(fout,a))
	{
		directory.push_back(a);
	}
	remove_Start(directory);

	for (int i=0; i < directory.size(); i++)
	{
		insert(directory[i]);
		cout << endl << endl;
	}
}

Tree::~Tree()
{
}

void Tree::insertAsChild(TreeItem* Current, TreeItem* temp)
{
	cout << temp->value << " -> " << "DoneCHILD" << endl;
	Current->FChild=temp;
	temp->Parent = Current;
}
void Tree::insertAsSibling(TreeItem* Current, TreeItem* temp)
{
	cout << temp->value << " -> " <<  "DoneSibling" << endl;
	Current->NextS=temp;
	temp->Parent=Current->Parent;

}
void Tree::insert(string item)
{
	TreeItem* Current= head;
	TreeItem* Previous;
	string toBeInsert;
	string previousString;
	int i =0;
	while(item[0] != '0')
		{
			int flag = 0;
			if (item.at(i) == '\\' || item.at(i) == '/')
			{
				toBeInsert=item.substr(0,i);
				TreeItem* temp= new TreeItem(toBeInsert);
				if (Current == NULL)
				{
					head=temp;
					Current=head;
					item=item.substr(i+1,item.length());
					i=0;
					cout << Current->value << " -> " <<  "Heading ->";
				}
				else
				{
					if (Current->value == toBeInsert)
					{
						item=item.substr(i+1,item.length());
						i=0;
						cout << Current->value << " -> ";
					}
					else
					{	
						
						while(Current->FChild !=NULL)
						{
							Current=Current->FChild;
							cout << Current->value << " -> ";
							abc:
							if(Current->value != toBeInsert)
							{
								if(Current->NextS !=NULL)
								{
									Current=Current->NextS;
									cout << Current->value << " -> " ;
									goto abc;
								}
								insertAsSibling(Current,temp);
								return;
							}
							else
							{
								item=item.substr(i+1,item.length());
								i=0;
								flag=1;
								break;
							}
						}
						if (flag==0)
						{
							insertAsChild(Current,temp);
							cout << Current->value << " -> ";
							Current=Current->FChild;
							cout << Current->value << " -> ";
							item=item.substr(i+1,item.length());
							i=0;
							flag=1;
						}
					}
				}
			}
			i++;
		}	
}


vector<string> Tree::Locate(string qry)
{	
	int flag=0;
	vector<string> result_directory;
	TreeItem* Result;
	TreeItem* TraverseVar = head;
	if (TraverseVar->value==qry)
	{
		result_directory.push_back(TraverseVar->value);
		return result_directory;

	}
	else
	{
		positive:
		if(TraverseVar->value==qry)
			{
				Result=TraverseVar;
				flag=1;
			}
		while(TraverseVar->FChild!=NULL && flag!=1)
		{
			TraverseVar=TraverseVar->FChild;
			if(TraverseVar->value==qry)
			{
				Result=TraverseVar;
				flag=1;
				break;
			}
		}
		while (TraverseVar->NextS!=NULL && flag!=1)
		{
			TraverseVar=TraverseVar->NextS;
			if(TraverseVar->value==qry)
			{
				Result=TraverseVar;
				flag=1;
				break;
			}
		}
		if(flag!=1)
		{
			TraverseVar=TraverseVar->Parent;
		}	
		if(TraverseVar->NextS!=NULL && flag!=1)
		{
			TraverseVar=TraverseVar->NextS;
			goto positive;
		}
		else if (flag!=1)
		{
			Result=NULL;
			return result_directory;
		}
	}

	// ENTERING VALUES IN VECTOR
	while(Result!=NULL)
	{
		result_directory.push_back(Result->value);
		Result=Result->Parent;
	}
	return result_directory;
}

string Tree::LComAc(string a, string b)
{
	vector<string> first;
	vector<string> second;
	first=Locate(a);
	second=Locate(b);
	for (int i =0 ; i < first.size();i++)
	{
		for(int j=0; j< second.size(); j++)
		{
			if(first[i]==second[j])
			{
				return first[i];
			}
		}
	}
}

TreeItem* Tree::getHead()
{
	return head;
}

int Tree::countFiles()
{
}

void Tree::moveFolder(string fromFolder,string toFolder)
{
}
#endif


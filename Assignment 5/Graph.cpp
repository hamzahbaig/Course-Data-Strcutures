#ifndef GRAPH__CPP
#define GRAPH__CPP
#include "Graph.h"
#include "heap.cpp"

bool operator == (edge a, edge b)
{
	if((a.weight == b.weight)){
		return true;
	} else {
		return false;
	}
}

bool operator < (edge a, edge b)
{
	if(a.weight < b.weight){
		return true;
	} else{
		return false;
	}
}

bool operator > (edge a, edge b)
{
	if(a.weight > b.weight){
		return true;
	} else{
		return false;
	}
}

bool operator < (node a, node b)
{
}

bool operator > (node a, node b)
{
}




Graph::Graph(char* file)
{
	ifstream fin;
	int condition = 0 ;
	string city1, city2;
	float x,y,weight;
	fin.open(file);
	fin >> city1;
	while(!fin.eof())
	{
		if (city1 == "NODES")
		{
			condition = 1 ;
		}
		else if (city1 == "ARCS")
		{
			condition = 2;
		}
		else if (condition == 1)
		{
			fin >> x; fin >> y;
			node* temp_city = new node();
			temp_city->name = city1;
			temp_city->x = x ;
			temp_city->y = y ;
			cities.push_back(temp_city);
		}
		else if (condition == 2)
		{
			fin >> city2 ; fin >> weight;
			edge temp_edge;
			temp_edge.Origin = getCity(city1);
			temp_edge.Dest = getCity(city2);
			temp_edge.weight = weight;
			arcs.push_back(temp_edge);
		}
		fin >> city1;
	}

	int len_cities = cities.size();
	int len_arcs = arcs.size();
	for (int i =0 ; i < len_cities; i++)
	{
		for (int j= 0 ; j <len_arcs ; j++)
		{
			if(cities[i]->name == arcs[j].Origin->name || cities[i]->name == arcs[j].Dest->name)
			{
				cities[i]->edges.push_back(arcs[j]);
			}
		}
	}
}
node* Graph::getCity(string s)
{
	int len = cities.size();
	for (int i =0 ; i < len ; i++)
	{
		if (cities[i]->name == s)
		{
			return cities[i];
		}
	}
	return NULL;
}
void Graph::display(node* temp)
{
	if(temp->visit)
		return;
	
	cout << "AT: " << temp->name;
	temp->visit = 1;
	for(int i=0; i< temp->edges.size(); i++)
	{
		if(!temp->edges[i].Origin->visit || !temp->edges[i].Dest->visit)
		cout << "->" << temp->edges[i].weight << endl;
		display(temp->edges[i].Origin);
		display(temp->edges[i].Dest);
	}
}
vector<node*> Graph::Prims()
{
}
vector<node*> Graph::Kruskal()
{
	vector<edge> arcsofMST;
	vector<vector<node*>> outerSet;
	int len_cities = cities.size();
	for(int i=0; i < len_cities; i++)
	{
		vector <node* > temp;
		temp.push_back(cities[i]);
		outerSet.push_back(temp);
	}
	cout << "LOADING MININMUM SPANNING TREE.." << endl ;
	int heapSize = arcs.size();
	MinHeap<edge> *heap = new MinHeap<edge> (heapSize);

	for (int i=0; i < heapSize; i++)
	{
		heap->insertKey(arcs[i]);
	}
	float totalWeight = 0;

	for(int i =0 ; i <heapSize ; i++)
	{
		edge extracted = heap->extractMin();
		node* extractOrigin = extracted.Origin;
		node* extractDest = extracted.Dest;
		float extractWeight = extracted.weight;
		bool discard = false ;
		bool originPres = false;
		bool destPres = false;
		int outerLen = outerSet.size();
		vector<node* > originVector;
		vector <node* > destVector ;

		for (int i =0 ; i < outerLen ; i++)
		{
			vector<node*> innerSet = outerSet[i];
			int innerLength = innerSet.size();
			originPres = false;
			destPres = false;
			for(int j = 0 ; j <innerLength ; j++)
			{
				if (innerSet[j]->name == extractOrigin->name)
				{
					originPres = true;
				}
				if (innerSet[j]->name == extractDest->name)
				{
					destPres = true;
				}
			}
			if (originPres && !destPres)
			{
				originVector = innerSet;
			}
			if(!originPres && destPres)
			{
				destVector = innerSet;
			}
			if (originPres && destPres)
			{
				discard = true;
				break;
			}
		}

		if (!discard)
		{
			arcsofMST.push_back(extracted);
			cout << "Edge added in MST with Origin " << extractOrigin->name << 
	    	" and Destination " <<extractDest->name << " and weight " << extractWeight << endl; 
			
			vector<node *> mergeVect;
			int originLen = originVector.size();
			int destLen = destVector.size();
			for (int i = 0 ; i < originLen; i++)
			{
				mergeVect.push_back(originVector[i]);
			}
			for (int i=0 ; i < destLen; i++)
			{
				mergeVect.push_back(destVector[i]);
			}
			vector<vector<node*>> tempOuterSet;
			for (int i=0 ; i< outerLen; i++)
			{
				if(outerSet[i] != originVector && outerSet[i] != destVector)
				{
					tempOuterSet.push_back(outerSet[i]);
				}
			}
			tempOuterSet.push_back(mergeVect);
			outerSet = tempOuterSet;
			totalWeight = totalWeight + extractWeight;
		}
	}

	cout << "TOTAL WEIGHT : " << totalWeight << endl;
	vector <node*> final;
	for (int i =0 ; i < len_cities; i++)
	{
		node* temp = new node();
		temp->name = cities[i]->name;
		final.push_back(temp);
	}

	int len_arcs = arcsofMST.size();
	for (int i=0;i < len_cities; i++)
	{
		for(int j=0; j<len_arcs; j++)
		{
			if (final[i]->name == arcsofMST[j].Origin->name || final[i]->name == arcsofMST[j].Dest->name)
			{
				final[i]->edges.push_back(arcsofMST[j]);
			}
		}
	}

	return final;

}
vector<string> Graph::Dijkstra(string city, string destination, float &d)
{
}
#endif

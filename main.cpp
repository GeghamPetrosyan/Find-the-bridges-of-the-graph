#include<iostream> 
#include <list> 
#include <string>
#include<fstream>
#include <sstream>
#include"Graph.h"
using namespace std;

// Driver program to test above function 
int main()
{
    // Create graphs given in above diagrams 
    cout << "G_1 graph bridges are  \n";
    Graph G_1(5);
    G_1.AddEdge(1, 0);
    G_1.AddEdge(0, 2);
    G_1.AddEdge(2, 1);
    G_1.AddEdge(0, 3);
    G_1.AddEdge(3, 4);
    G_1.FindeBridge();

 

	/**************************************************/
	int i;
	cout << "In file's first line write vertex count " << '\n';
	cout << "Started with second line write adjecency list representation of the graph" << '\n';
	cout << "If your file is ready,please press 1 and then enter- ";
	cin >> i;
	if (i == 1)
	{
		/********************************************/
		int V = 0;
		list<int>* adj;
		fstream ob;
		//ob.open("Name.txt", ios::out);
		//ob.close();
		string S, T;
		ob.open("Name.txt", ios::in);
		streampos begin, end;
		begin = ob.tellg();
		ob.seekg(0, ios::end);
		end = ob.tellg();
		int sizee = end - begin;
		ob.close();
		//streampos size=ob.tellg();
		//cout << "sizee =" << sizee << endl;
		int size = sizee;
		//cout << "size =" << size << endl;
		//cout << "size is: " << () << " bytes.\n";
		char* SS = new char[size];
		ob.open("Name.txt", ios::in);
		ob.read(SS, size);
		int k = 0;
		while (SS[k] != '\n')
		{
			//cout << SS[k] << " ";
			T.push_back(SS[k]);
			k++;
		}
		//cout << "T=" << T << endl;
		istringstream(T) >> V;
		//	cout << "V=" << V << endl;
		adj = new list<int>[V];
		while (SS[k] != '\0' && k < size)
		{
			string index;
			int first;
			//	cout << "k=" << k << endl;
			while (SS[k] != '-' && SS[k] != '\0' && k < size)
			{
				index.push_back(SS[k]);
				k++;
				istringstream(index) >> first;
				/**/
			}
			//cout << "first=" << first << endl;
			//cout << "k=" << k << endl;
			if (SS[k] != '\n' && SS[k] != '\0')
				k++;
			while (SS[k] != '\n' && SS[k] != '\0' && SS[k] != '-' && k < size)
			{
				string s;
				while (SS[k] != ' ' && SS[k] != '\0' && SS[k] != '\n' && SS[k] != '-' && k < size)
				{
					s.push_back(SS[k]);
					k++;
					//cout << "s=" << s << endl;
				}
				if (SS[k] != '\n' && SS[k] != '\0' && k < size)
					k++;
				int p;
				istringstream(s) >> p;
				adj[first].push_back(p);
			}
		}
		/*
		for (int l = 0; l < V; ++l)
			{
				cout << l << "-";
				for (list<int>::iterator o = adj[l].begin(); o != adj[l].end(); ++o)
					cout << *o << " ";
				cout << endl;
			}
			ob.close();
		*/
		Graph G(V, adj);
		cout << "G  graph bridges are  " << endl;
		G.FindeBridge();
	}
    return 0;
}

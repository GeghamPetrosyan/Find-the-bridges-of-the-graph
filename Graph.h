#pragma once
using namespace std;
int min(int a, int b)
{
     return (a<b)? a:b;  
}
class Graph
{
    int V;    //Vertices 
    list<int>* adj;    // A dynamic array of adjacency lists 
    void bridgeUtil(int v, bool visited[], int disc[], int low[],
        int parent[]);
public:
    Graph(int V);   // Constructor 
    Graph(int , list<int>*);// Constructor
    void AddEdge(int v, int w);   // to add an edge to graph 
    void FindeBridge();    // prints all bridges 
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

Graph::Graph(int v, list<int>* adj)// Constructor
{
    this->V = v;
    this->adj = new list<int>[V];
    for (int l = 0; l < V; ++l)
    {
        for (list<int>::iterator o = adj[l].begin(); o != adj[l].end(); ++o)
            // this->adj[l].push_back(*o
            ddEdge(l, *o);
    }
}
void Graph::AddEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);  // Note: the graph is undirected 
}
void Graph::bridgeUtil(int u, bool visited[], int disc[],
    int low[], int parent[])
{
    // A static variable is used for simplicity, we can  
    static int time = 0;
    // Mark the current node as visited 
    visited[u] = true;
    // Initialize discovery time and low value 
    disc[u] = low[u] = time++;

    // Go through all vertices aadjacent to this 
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;  // v is current adjacent of u 
        // If v is not visited yet, then recur for it 
        if (!visited[v])
        {
            parent[v] = u;
            bridgeUtil(v, visited, disc, low, parent);
            // Check if the subtree rooted with v has a  
            // connection to one of the ancestors of u 
            low[u] = min(low[u], low[v]);

            // If the lowest vertex reachable from subtree  
            // under v is  below u in DFS tree, then u-v  
            // is a bridge 
            if (low[v] > disc[u])
                cout << u << " " << v << endl;
        }

        // Update low value of u for parent function calls. 
        else if (v != parent[u])
            low[u] = min(low[u], disc[v]);
    }
}

// DFS based function to find all bridges. It uses recursive  
// function bridgeUtil() 
void Graph::FindeBridge()
{
    // Mark all the vertices as not visited 
    bool* visited = new bool[V];
    int* disc = new int[V];
    int* low = new int[V];
    int* parent = new int[V];

    // Initialize parent and visited arrays 
    for (int i = 0; i < V; i++)
    {
        parent[i] = -1;
        visited[i] = false;
    }

    // Call the recursive helper function to find Bridges 
    // in DFS tree rooted with vertex 'i' 
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            bridgeUtil(i, visited, disc, low, parent);
}

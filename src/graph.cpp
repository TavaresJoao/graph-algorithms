#include "graph.h"

Graph::Graph(int v)
{
  this->V = v;
  adj = new list<int>[V];
}

void Graph::addEdge(int v1, int v2)
{
  // add v2 to v1's list
  adj[v1].push_back(v2);
}

void Graph::DFS_Util(int v, bool visited[])
{
  // mark the current node as visited and print it
  visited[v] = true;

  cout << v << '\t';

  // recur for all the vertices adjacent to this vertex
  list<int>::iterator i;
  for(i = adj[v].begin(); i != adj[v].end(); ++i)
    if(!visited[*i])
      DFS_Util(*i, visited);
}

// DFS traversal of the vertices  reacheable  from v.
// it uses recursive DFS_Util()
void Graph::DFS(int v)
{
  // mark all vertices as not visited
  bool *visited = new bool[V];
  for(int i = 0; i < V; i++)
    visited[i] = false;

  // call the recursive helper function to print DFS traversal
  DFS_Util(v, visited);
}

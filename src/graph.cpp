#include "graph.h"

Graph::Graph(int v)
{
  this->V = v;

  adj = new list<int>[V];
  vertices = new vector<vertex>[V];

  adj_matrix = new vector<vector<int>>(V, vector<int>(V, 0));
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

int Graph::get_V()
{
  return this->V;
}

void Graph::displayVertices()
{
  for(int i = 0; i < V; i++)
    cout << i << ":\t" << (*vertices).at(i) << endl;
}

void Graph::displayGraph()
{
  for (int i = 0; i < V; i++)
  {
    cout << i << " -->";

    list<int>::iterator j;
    for(j = adj[i].begin(); j != adj[i].end(); ++j)
      cout << '\t' << *j;
    cout << endl;
  }
}

void Graph::displayGraph_matrix()
{
  int i, j;
  for(i = 0; i < V; i++)
  {
    for(j = 0; j < V; j++)
      cout << (*adj_matrix).at(i).at(j) << ' ';
    cout << endl;
  }
}

void Graph::assign_vertices(vector<vertex> ass_vec)
{
  vertices->assign(ass_vec.begin(), ass_vec.end());
}

void Graph::assign_matrix(vector<vector<edge>> ass_mat)
{
  for(int i = 0; i < V; i++)
    (*adj_matrix)[i].assign(ass_mat[i].begin(), ass_mat[i].end());
}

void Graph::matrix2list()
{
  
}

#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <iostream>
#include <list>
#include <vector>

using namespace std;

typedef string vertex;

/*  Graph class  represents a directed graph
*   using adjacency list representation and
*   adjacency matrix
*/
class Graph
{
  // number of vetex
  int V;

  // vertices
  vector<vertex> *vertices;

  // adjacency list
  list<int> *adj;

public:
  // constructor
  Graph(int v);

  //
  int get_V();

  // function to add an edge to graph
  void addEdge(int v1, int v2);

  // depth first search (DFS) tree of vertices reacheable from v
  void DFS(int v);

  // function to display adjacency list of the graph
  void displayGraph();

  // function to assign vertices
  void assign_vertices(vector<vertex> ass_vec);

private:
  void DFS_Util(int v, bool visited[]);
};


#endif //GRAPH_H_INCLUDED

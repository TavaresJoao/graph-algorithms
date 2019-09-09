#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <iostream>
#include <list>

using namespace std;

/*  Graph class  represents a directed graph
*   using adjacency list representation and
*   adjacency matrix
*/
class Graph
{
  // number of vetex
  int V;

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

private:
  void DFS_Util(int v, bool visited[]);
};


#endif //GRAPH_H_INCLUDED

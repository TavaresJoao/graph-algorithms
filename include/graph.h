#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <iostream>
#include <list>

using namespace std;

/*  Graph class  represents a directed graph
*   using adjacency list representation
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

  // function to add an edge to graph
  void addEdge(int v1, int v2);

  // depth first search (DFS) tree of vertices reacheable from v
  void DFS(int v);

private:
  void DFS_Util(int v, bool visited[]);
};

/*
Graph::Graph(int v);
void Graph::addEdge(int v1, int v2);
void Graph::DFS_Util(int v, bool visited[]);
void Graph::DFS(int v);
*/

#endif //GRAPH_H_INCLUDED

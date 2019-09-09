#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <iostream>
#include <list>
#include <vector>

using namespace std;

typedef string vertex;
typedef int edge;

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

  // adjacency matrix
  vector<vector<edge>> *adj_matrix;

public:
  // constructor
  Graph(int v);

  //
  int get_V();

  // function to add an edge to graph
  void addEdge(int v1, int v2);

  // depth first search (DFS) tree of vertices reacheable from v
  void DFS(int v);

  //
  void displayVertices();

  // function to display adjacency list of the graph
  void displayGraph();

  //
  void displayGraph_matrix();

  // function to assign vertices
  void assign_vertices(vector<vertex> ass_vec);

  //
  void assign_matrix(vector<vector<edge>> ass_mat);

  // tranfers matrix data to adjacency list
  void matrix2list();

private:
  void DFS_Util(int v, bool visited[]);
};


#endif //GRAPH_H_INCLUDED

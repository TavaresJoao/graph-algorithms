#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

typedef string vertex;
typedef int edge;

#define WHITE_COLOR   0
#define YELLOW_COLOR  1
#define RED_COLOR     2

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

  //
  vector<int> depth(int v_orig, int v_dest);

private:
  //
  void DFS_Util(int v, bool visited[]);

  //
  void searchD(int u, int v_dest, vector<int> *color, vector<int> *path);
};


#endif //GRAPH_H_INCLUDED

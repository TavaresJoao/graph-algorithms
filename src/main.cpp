#include "headers.h"

int main(int argc, char const *argv[])
{
  /*
  if(argc!=2)
  {
    cerr << "Invalid argument number!\n";
    return 2;
  }

  ifstream input_file;
  input_file.open(argv[1]);

  if(!input_file.is_open())
  {
    cout << "Nop abriu!\n";
    return 1;
  }
  cout << "Abriu!\n";

  input_file.close();
  */
  /*
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
  g.DFS(2);
  cout << endl;
  */
  Graph grafo = import_data(argv[1]);

  grafo.displayVertices();
  grafo.displayGraph_matrix();
  grafo.displayGraph();

  cout << "Following is Depth First Traversal"
            " (starting from vertex 20 [Porecatu]) \n";
  grafo.DFS(20);

  return 0;
}

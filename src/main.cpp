#include "headers.h"

int main(int argc, char const *argv[])
{
  Graph grafo = import_data(argv[1]);

  grafo.displayVertices();
  //grafo.displayGraph_matrix();
  grafo.displayGraph();

  grafo.depth(20, 18);

  return 0;
}

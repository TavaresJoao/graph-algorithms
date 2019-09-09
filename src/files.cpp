#include "files.h"

Graph import_data(string input_src)
{
  ifstream input_file;
  input_file.open(input_src);

  if(!input_file.is_open())
  {
    Graph grafo(0);
    return grafo;
  }

  string line, buffer;

  // get N
  int N;
  getline(input_file, line);
  N = stoi(line);

  // Graph created with given N
  Graph grafo(N);

  // get vertices

  // get adjacency matrix

  return grafo;
}

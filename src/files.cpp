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
  getline(input_file, line);
  vector<string> data = split(line, ',');

  grafo.assign_vertices(data);

  // get adjacency matrix
  int i, j;
  vector<vector<int>> matrix(N, vector<int>(N));

  for(i = 0; i < N; i++)
    for(j = 0; j < N; j++)
      input_file >> matrix[i][j];
  input_file >> buffer;

  /*cout << "matrix::" << endl;
  for(i = 0; i < N; i++)
  {
    for(j = 0; j < N; j++)
      cout << matrix.at(i).at(j) << " ";
    cout << endl;
  }*/
  grafo.assign_matrix(matrix);
  grafo.matrix2list();

  // fechar o arquivo
  input_file.close();

  return grafo;
}

const vector<string> split(const string& s, const char& delimiter)
{
  string buff{""};
  vector<string> v;

  for(auto n:s)
  {
    if( n != delimiter )
      buff += n;
    else
    {
      if( buff != "" )
      {
        v.push_back(buff);
        buff="";
      }
    }
  }
  if(buff != "")
    v.push_back(buff);

  return v;
}

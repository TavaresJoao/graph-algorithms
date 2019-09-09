#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>

#include "graph.h"

using namespace std;

Graph import_data(string input_src);
const vector<string> split(const string& s, const char& delimiter);

#endif //FILES_H_INCLUDED

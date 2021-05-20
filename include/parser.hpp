#ifndef PARSER_H
#define PARSER_H

#include <fstream>
#include <string>
#include <vector>
#include "mapa.hpp"
using std::ifstream;
using std::string;
using std::vector;

vector<Vertice*> ler_arquivo(string filename);

#endif

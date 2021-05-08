#include <iostream>
#include <string>
#include "gl_wrapper.hpp"
#include "mapa.hpp"
#include "parser.hpp"
//using std::cout;
//using std::endl;
using std::string;

int main(int argc, char const *argv[]) {
  if (argc == 3 && argv[1][0] == '-' && argv[1][1] == 'f') {
    string filename = argv[2];
    vector<Vertice*> vertices = ler_arquivo(filename);
  }

  wrapper::open_window(800, 400);

  return 0;
}

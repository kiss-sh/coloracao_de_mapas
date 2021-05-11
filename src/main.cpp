#include <iostream>
#include <string>
#include "gl_wrapper.hpp"
#include "mapa.hpp"
#include "parser.hpp"
using std::cout;
using std::endl;
using std::string;

extern vector<VerticePosition*> global_var_vertices;

int main(int argc, char const *argv[]) {
  if (argc == 3 && argv[1][0] == '-' && argv[1][1] == 'f') {
    string filename = argv[2];

    cout << "lendo o arquivo ..." << endl; // log
    vector<Vertice*> vertices = ler_arquivo(filename);
    cout << "leitura finalizada" << endl; // log

    if (vertices.size() == 2) {
      VerticePosition *v1 = new VerticePosition;

      global_var_vertices.push_back(v1);
    }
  }


  return 0;
}

#include <iostream>
#include <string>
#include "gl_wrapper.hpp"
#include "mapa.hpp"
#include "parser.hpp"
using std::cout;
using std::endl;
using std::string;

extern vector<VerticePosition*> global_var_vertices;
extern vector<ArestaPosition*>  global_var_arestas;

int main(int argc, char const *argv[]) {
  if (argc == 2) {
    string filename = argv[1];

    cout << "lendo o arquivo ..." << endl; // log
    vector<Vertice*> vertices = ler_arquivo(filename);
    cout << "leitura finalizada" << endl; // log

    if (vertices.size() == 2) {
      // vertices
      VerticePosition *v1 = new VerticePosition;
      v1->x = 100;
      v1->y = 100;
      VerticePosition *v2 = new VerticePosition;
      v2->x = 200;
      v2->y = 100;

      global_var_vertices.push_back(v1);
      global_var_vertices.push_back(v2);

      // arestas
      ArestaPosition *a1 = new ArestaPosition;
      a1->x_begin = v1->x;
      a1->y_begin = v1->y;
      a1->x_end = v2->x;
      a1->y_end = v2->y;

      global_var_arestas.push_back(a1);
    }
  }

  open_window(800, 400);

  return 0;
}

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

    bool breaked = false;
    int x_axis = 100;
    int y_axis = 100;
    int index = 0;

    while (true) {
      for (int x=0; x < 3; x++) {
        if (index < vertices.size()) {
          VerticePosition *v = new VerticePosition;
          v->x = x_axis;
          v->y = y_axis;
          v->nome = vertices[index]->nome;
          global_var_vertices.push_back(v);

          x_axis += 50;
          index++;

        } else {
          breaked = true;
          break;
        }
      }

      if (breaked) {
        break;
      } else {
        x_axis = 100;
        y_axis += 50;
      }
    }
  }

  open_window(800, 400);

  return 0;
}

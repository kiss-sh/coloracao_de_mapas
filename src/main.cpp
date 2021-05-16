#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "gl_wrapper.hpp"
#include "mapa.hpp"
#include "parser.hpp"
using std::cout;
using std::endl;
using std::map;
using std::string;

extern vector<VerticePosition*> global_var_vertices;
extern vector<ArestaPosition*>  global_var_arestas;

VerticePosition *obterPointer(string nome) {
  for (int it = 0; it < global_var_vertices.size(); it++) {
    if(global_var_vertices[it]->nome == nome) {
      return global_var_vertices[it];
    }
  }
}

void montarArestas(vector<Vertice*> vertices) {
  for (int x = 0; x != vertices.size(); x++) {
    VerticePosition *v = obterPointer(vertices[x]->nome);

    map<string, Vertice*>::iterator it;
    for (it = vertices[x]->adjacentes.begin(); it != vertices[x]->adjacentes.end(); it++) {
      VerticePosition *v_adjacente = obterPointer(it->first);
      ArestaPosition *aresta = new ArestaPosition;
      aresta->x_begin = v->x;
      aresta->y_begin = v->y;
      aresta->x_end = v_adjacente->x;
      aresta->y_end = v_adjacente->y;
      global_var_arestas.push_back(aresta);
    }
  }
}

int main(int argc, char const *argv[]) {
  if (argc == 2) {
    string filename = argv[1];

    cout << "lendo o arquivo ..." << endl; // log
    vector<Vertice*> vertices = ler_arquivo(filename);
    cout << "leitura finalizada" << endl; // log

    vector<int> cores;
    colorir_mapa(*vertices[0], cores);

    bool breaked = false;
    int x_axis = 100;
    int y_axis = 100;
    int index = 0;

    while (true) {
      for (int x=0; x < 3; x++) {
        if (index < vertices.size()) {
          VerticePosition *v = new VerticePosition;
          v->x = x_axis;
          if (x == 1) {
            // deslocar a segunda coluna
            v->y = y_axis-30;
          } else {
            v->y = y_axis;
          }
          v->nome = vertices[index]->nome;
          v->cor = vertices[index]->cor;
          global_var_vertices.push_back(v);

          x_axis += 80;
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
        y_axis += 80;
      }
    }

    montarArestas(vertices);
  }

  open_window(800, 400);

  return 0;
}

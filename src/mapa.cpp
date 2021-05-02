#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

class Vertice {
  public:
    map<string, Vertice> adjacentes;
    string nome;
    int cor = 0; // 0 significa nenhuma cor definida ou simplesmente cor branca

    Vertice(string n) {
      nome = n;
    }

    void add_vertice(Vertice other_vertice) {
      adjacentes.emplace(other_vertice.nome, other_vertice);
    }

    void mostrar_adjacentes() {
      map<string, Vertice>::iterator x;
      for (x = adjacentes.begin(); x != adjacentes.end(); x++) {
        cout << nome << "->" << x->first << endl;
      }
    }
};

class Grafo {

  public:
    vector<Vertice> vertices;
    void add(string v1, string v2) {
      bool break_called = false;

      vector<Vertice>::iterator x;
      for (x = vertices.begin(); x != vertices.end(); x++) {
        if (x->nome == v1) {
          x->add_vertice(v2);
          break_called = true;
          break;
        }
      }

      if (!break_called) {
        Vertice novo_vertice(v1);
        novo_vertice.add_vertice(v2);
        vertices.push_back(novo_vertice);
      }
    }
};

void colorir_mapa(Vertice &v, vector<int> cores = {}) {
  if (v.cor == 0) {
    if (cores.size() > 0) {
      /* implementacao incompleta
      vector<int> cores_adj = cores;

      map<string, Vertice>::iterator x;
      for (x = v.adjacentes.begin(); x != v.adjacentes.end(); x++) {
        index = cores
      }
      */

    } else {
      v.cor = 1;
      cores.push_back(1);
    }

    map<string, Vertice>::iterator x;
    for (x = v.adjacentes.begin(); x != v.adjacentes.end(); x++) {
      colorir_mapa(x->second, cores);
    }
  }
}

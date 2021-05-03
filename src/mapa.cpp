#include <iostream>
#include <map>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

class Vertice {
  public:
    map<string, Vertice*> adjacentes;
    string nome;
    int cor = 0; // 0 significa nenhuma cor definida ou simplesmente cor branca

    Vertice(string n) {
      nome = n;
    }

    void add_vertice(Vertice *other_vertice) {
      adjacentes.emplace(other_vertice->nome, other_vertice);
    }

    void mostrar_adjacentes() {
      map<string, Vertice*>::iterator x;
      for (x = adjacentes.begin(); x != adjacentes.end(); x++) {
        cout << nome << "->" << x->first << endl;
      }
    }
};

class Grafo {

  int find_vertice(string v) {
    int index = 0;
    while (index < vertices.size()) {
      if (vertices[index]->nome == v) {
        return index;
      } else {
        index++;
      }
    }

    return -1;
  }

  public:
    vector<Vertice*> vertices;
    void add(string v1, string v2) {
      int search_v1 = find_vertice(v1);
      int search_v2 = find_vertice(v2);

      if (search_v1 >= 0) {
        if (search_v2 >= 0) {
          // quando tanto v1 quanto v2 já estão dentro do vector
          vertices[search_v1]->add_vertice(vertices[search_v2]);

        } else {
          // quando apenas v1 está dentro do vector
          Vertice* new_v2 = new Vertice(v2);
          vertices[search_v1]->add_vertice(new_v2);
          new_v2->add_vertice(vertices[search_v1]);
          vertices.push_back(new_v2);
        }
      } else {
        // quando v1 e v2 não estão dentro do vector
        Vertice *new_v1 = new Vertice(v1), *new_v2 = new Vertice(v2);
        new_v1->add_vertice(new_v2);
        new_v2->add_vertice(new_v1);
        vertices.push_back(new_v1);
        vertices.push_back(new_v2);
      }
    }
};

int get_index(int value, vector<int> v) {
  for (int x = 0; x < v.size(); x++) {
    if (v[x] == value) {
      return  x;
    }
  }
  return -1;
}

void colorir_mapa(Vertice &v, vector<int> &cores) {
  if (v.cor == 0) {
    if (cores.size() > 0) {
      vector<int> cores_adj = cores;

      map<string, Vertice*>::iterator x;
      for (x = v.adjacentes.begin(); x != v.adjacentes.end(); x++) {
        int search_index = get_index(x->second->cor, cores_adj);
        if (search_index >= 0) {
          cores_adj.erase(cores_adj.begin() +search_index);
        }
      }

      if (cores_adj.size() > 0) {
        v.cor = cores_adj[0];
      } else {
        int new_cor = cores[cores.size() -1] +1;
        cores.push_back(new_cor);
        v.cor = new_cor;
      }

    } else {
      v.cor = 1;
      cores.push_back(1);
    }

    map<string, Vertice*>::iterator x;
    for (x = v.adjacentes.begin(); x != v.adjacentes.end(); x++) {
      colorir_mapa(*(x->second), cores);
    }
  }
}

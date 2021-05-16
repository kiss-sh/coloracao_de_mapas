#include <fstream>
#include <string>
#include <vector>
#include "mapa.hpp"
#include "parser.hpp"
using std::ifstream;
using std::string;
using std::vector;

string ler_nome_vertice(ifstream &arquivo) {
  // armazena todos os caracteres em uma variavel
  // e retorna quando achar aspas duplas

  vector<char> variavel_char;
  char c;
  while (arquivo.get(c)) {
    if (c != '"') {
      variavel_char.push_back(c);
    } else {
      break;
    }
  }
  string nome_vertice(variavel_char.begin(), variavel_char.end());
  return nome_vertice;
}

vector<Vertice*> ler_arquivo(string filename) {
  // lê um arquivo de texto estruturado e retorna um vetor de ponteiros

  Grafo grafo;
  string nome_vertice, nome_adjacente;
  bool in_braket = false;

  char c;
  ifstream arquivo(filename);
  while (arquivo.get(c)) {
    if (c == '"' && in_braket == false) {
      nome_vertice = ler_nome_vertice(arquivo);

    } else if (c == '"' && in_braket == true) {
      nome_adjacente = ler_nome_vertice(arquivo);
      grafo.add(nome_vertice, nome_adjacente);

    } else if (c == '[' || c == ']') {
      in_braket = !in_braket;
    }
  }
  return grafo.vertices;
}

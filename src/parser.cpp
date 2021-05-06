#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::ifstream;
using std::string;
using std::vector;
using std::cout;
using std::endl;

string ler_nome_vertice(ifstream &arquivo) {
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
  cout << "teste: " << nome_vertice << endl;
  return nome_vertice;
}

void ler_arquivo(string filename) {
  string nome_v1;
  char c;
  ifstream arquivo(filename);
  while (arquivo.get(c)) {
    if (c == '"') {
      nome_v1 = ler_nome_vertice(arquivo);
    }
  }
}

// teste
int main(int argc, char const *argv[]) {
  ler_arquivo(argv[1]);
}

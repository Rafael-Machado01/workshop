#include <iostream>
#include <string>
using namespace std;

#define T 2

// Structs

struct Cidade {
  int id;
  string nome, uf;
};

struct Servico {
  int id;
  string descricao;
  float valorMaoDeObra;
};

struct Peca {
  int id, qtdeEstoque, minEstoque, maxEstoque;
  string descricao;
  float preco;
};

// Structs

// Protótipos
void readCidade(Cidade c[]);
void readServicos(Servico s[]);
void readPeca(Peca p[]);
// Protótipos

int main() {
  // Structs

  Cidade c[T];
  Servico s[T];
  Peca p[T];

  // Structs
  readCidade(c);
  readServicos(s);
  readPeca(p);
}

void readCidade(Cidade c[]) {
  for (int i = 0; i < T; i++) {
    cout << "ID: " << c[i].id << endl;
    cout << "Nome: " << c[i].nome << endl;
    cout << "UF: " << c[i].uf << endl;
  }
}

void readServicos(Servico s[]) {
  for (int i = 0; i < T; i++) {
    cout << "ID: " << s[i].id << endl;
    cout << "Descrição: " << s[i].descricao << endl;
    cout << "Valor de Mão de Obra: " << s[i].valorMaoDeObra << endl;
  }
}

void readPeca(Peca p[]) {
  for (int i = 0; i < T; i++) {
    cout << "ID:" << p[i].id << endl;
    cout << "Descrição: " << p[i].descricao << endl;
    cout << "Quantidade em Estoque: " << p[i].qtdeEstoque << endl;
    cout << "Quantidade Mínima: " << p[i].minEstoque << endl;
    cout << "Quantidade Maxíma: " << p[i].maxEstoque << endl;
    cout << "Preço Unitário: " << p[i].preco << endl;
  }
}

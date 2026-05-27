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
    cout << "Digite o ID da Cidade: " << endl;
    cin >> c[i].id;
    cout << "Digite o Nome da Cidade: " << endl;
    cin.ignore();
    getline(cin, c[i].nome);
    cout << "Digite a UF do Estado da Cidade: " << endl;
    cin >> c[i].uf;
  }
}

void readServicos(Servico s[]) {
  for (int i = 0; i < T; i++) {
    cout << "Digite o ID do Servico: " << endl;
    cin >> s[i].id;
    cout << "Digite a Descrição do Serviço: " << endl;
    cin.ignore();
    getline(cin, s[i].descricao);
    cout << "Digite o Valor de Mão de Obra do Serviço:" << endl;
    cin >> s[i].valorMaoDeObra;
  }
}

void readPeca(Peca p[]) {
  for (int i = 0; i < T; i++) {
    cout << "Digite o ID da Peça: " << endl;
    cin >> p[i].id;
    cout << "Digite a Descrição da Peça: " << endl;
    cin.ignore();
    getline(cin, p[i].descricao);
    cout << "Digite a Quantidade em Estoque da Peça: " << endl;
    cin >> p[i].qtdeEstoque;
    cout << "Digite a Quantidade de Estoque Mínima da Peça: " << endl;
    cin >> p[i].minEstoque;
    cout << "Digite a Quantidade de Estoque Máxima da Peça: " << endl;
    cin >> p[i].maxEstoque;
    cout << "Digite o Preço da Peça: " << endl;
    cin >> p[i].preco;
  }
}

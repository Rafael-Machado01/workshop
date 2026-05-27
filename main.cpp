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

struct Cliente {
  int id, idCidade;
  string nome, telefone, endereco;
};

// Structs

// Protótipos
void readCidade(Cidade c[]);
void readServicos(Servico s[]);
void readPeca(Peca p[]);
void setCliente(Cliente cl[], Cidade c[], int &cont);
void searchCidade(Cidade c[], int id);
void searchCliente(Cliente cl[], int exist, int id);

// Protótipos

int main() {
  // Structs

  Cidade c[T];
  Servico s[T];
  Peca p[T];
  Cliente cl[T];

  // Structs

  // Variables
  int contClienteS = 0, contClienteT = 0, contClienteA = 0;
  // Variables
  setCliente(cl, c, contClienteS);
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

void setCliente(Cliente cl[], Cidade c[], int &cont) {
  cont = 0;

  while (cont < T) {
    cout << "Digite o ID do Cliente (0 para sair): " << endl;
    cin >> cl[cont].id;
    int exist = 0;
    searchCliente(cl, exist, cl[cont].id);
    if (exist == 1) {
      cout << "ID Já Existente na tabela!" << endl;
      break;
    }
    if (cl[cont].id == 0) {
      break;
    } else {
      cout << "Digite o Nome do Cliente: " << endl;
      cin.ignore();
      getline(cin, cl[cont].nome);
      cout << "Digite o Endereço do Cliente: " << endl;
      getline(cin, cl[cont].endereco);
      cout << "Digite o Telefone do Cliente:" << endl;
      cin >> cl[cont].telefone;
      cout << "Digite o ID da Cidade:" << endl;
      cin >> cl[cont].idCidade;
      searchCidade(c, cl[cont].idCidade);
      cont++;
    }
  }
}

void searchCidade(Cidade c[], int id) {
  int init = 0, end = T - 1, middle = 0;
  while (init <= end) {
    middle = (init + end) / 2;
    if (c[middle].id > id) {
      end = middle - 1;
    } else if (c[middle].id < id) {
      init = middle + 1;
    } else {
      cout << "Nome: " << c[middle].nome << " UF: " << c[middle].uf << endl;
      break;
    }
  }
}

void searchCliente(Cliente cl[], int &exist, int id) {
  int init = 0, end = T - 1, middle = 0;
  while (init <= end) {
    middle = (init + end) / 2;
    if (cl[middle].id > id) {
      end = middle - 1;
    } else if (cl[middle].id < id) {
      init = middle + 1;
    } else {
      exist = 1;
    }
  }
}

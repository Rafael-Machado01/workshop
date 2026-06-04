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

struct Veiculo {
  int ano, idCliente;
  string placa, modelo, marca;
};

struct Mecanico {
  int id, telefone;
  string nome, especialidade;
};

// Structs

// Protótipos
void readCidade(Cidade c[]);
void readServicos(Servico s[]);
void readPeca(Peca p[]);
void setCliente(Cliente cl[], Cidade c[], int &cont);
void searchCidade(Cidade c[], int id);
void searchCliente(Cliente cl[], int &exist, int id);
void includeCliente(Cliente cl[], Cliente clT[], Cliente clA[], int contCliente,
                    int contClienteT, int contClienteA);
void searchVeiculo(Veiculo v[], int &exist, string id);
void searchMecanico(Mecanico m[], int &exist, int id)

    // Protótipos

    int main() {
  // Structs

  Cidade c[T];
  Servico s[T];
  Peca p[T];
  Cliente cl[T], clT[T], clA[T];
  Mecanico m[T], mT[T], mA[T];

  // Structs

  // Variables
  int contCliente = 0, contClienteT = 0, contClienteA = 0;
  int contMec = 0, contMecT = 0, contMecA = 0;
  // Variables
  setCliente(cl, c, contCliente);
  includeCliente(cl, clT, clA, contCliente, contClienteT, contClienteA);
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
      cout << "Cliente encontrado!" << endl;
      cout << "Nome: " << cl[middle].nome << endl;
    }
  }
}

void includeCliente(Cliente cl[], Cliente clT[], Cliente clA[], int contCliente,
                    int contClienteT, int &contClienteA) {
  int i = 0, j = 0, k = 0;

  while (i < contCliente and j < contClienteT) {
    if (cl[i].id < clT[i].id) {
      clA[k] = cl[i];
      i++;
    } else {
      clA[k] = clT[j];
      j++;
    }
    k++;
  }
  while (i < contCliente) {
    clA[k] = cl[i];
    i++;
    k++;
  }

  while (j < contClienteT) {
    clA[k] = clT[j];
    j++;
    k++;
  }
  contClienteA = k;
}

void setVeiculo(Veiculo v[], Cliente cl[], int &cont) {
  cont = 1;
  while (cont < T or cont == 0) {
    cout << "Digite a Placa do Veículo: (0 para sair): " << endl;
    cin >> v[cont].placa;
    int exist = 0;
    searchVeiculo(v, exist, v[cont].placa);
    if (exist == 1) {
      cout << "ID Já Existente na tabela!" << endl;
      break;
    }
    if (v[cont].placa == "") {
      break;
    } else {
      cout << "Digite o Modelo do Veículo: " << endl;
      getline(cin, v[cont].modelo);
      cout << "Digite a Marca do Veículo: " << endl;
      getline(cin, v[cont].marca);
      cout << "Digite o Ano do Veículo: " << endl;
      cin >> v[cont].ano;
      cout << "Digite o ID do Cliente: " << endl;
      cin >> v[cont].idCliente;
      searchCliente(cl, exist, v[cont].idCliente);
    }
  }
}

void searchVeiculo(Veiculo v[], int &exist, string id) {
  int init = 0, end = T - 1, middle = 0;
  while (init <= end) {
    middle = (init + end) / 2;
    if (v[middle].placa > id) {
      end = middle - 1;
    } else if (v[middle].placa < id) {
      init = middle + 1;
    } else {
      exist = 1;
      cout << "Placa já cadastrada!" << endl;
      cout << "Modelo: " << v[middle].modelo << endl;
    }
  }
}

void setMecanico(Mecanico m[]) {
  int cont = 1;
  while (cont < T or cont == 0) {
    cout << "Digite o ID do Mecanico (0 para sair):" << endl;
    cin >> m[cont].id;
    int exist = 0;
    searchMecanico(m, exist, m[cont].id);
    if (exist !=) {
      cout << "ID Já Existente!" << endl;
    } else {
      cout << "Digite o Nome do Mecanico:" << endl;
      cin.ignore();
      getline(cin, m[cont].nome);
      cout << "Digete a Especialidade do Mecanico:" << endl;
      getline(cin, m[cont].especialidade);
      cout << "Digite o Telefone do Mecanico:" << endl;
      cin >> m[cont].telefone;
    }
  }
}

void searchMecanico(Mecanico m[], int exist, int id) {
  int init = 0, end = T - 1, middle = 0;
  while (init <= end) {
    middle = (init + end) / 2;
    if (m[middle].id > id) {
      end = middle - 1;
    } else if (m[middle].id < id) {
      init = middle + 1;
    } else {
      exist = 1;
      break;
    }
  }

  void includeMecanico(Mecanico m[], int contS, Mecanico mT[], int contT,
                       Mecanico mA[], int &contA) {

    int i = 0;
    int j = 0;
    int k = 0;

    // enquanto existir elementos nos dois vetores
    while (i < contS && j < contT) {

      // pega o menor codigo
      if (S[i].codigo < T[j].codigo) {
        A[k] = S[i];
        i++;
      } else {
        A[k] = T[j];
        j++;
      }

      k++;
    }

    // copia resto de S
    while (i < contS) {
      A[k] = S[i];
      i++;
      k++;
    }

    // copia resto de T
    while (j < contT) {
      A[k] = T[j];
      j++;
      k++;
    }

    contA = k;
  }

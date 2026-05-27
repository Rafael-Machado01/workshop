#include <iostream>
#include <string>

using namespace std;

struct Cliente {
  int codigo;
  string nome;
  string endereco;
  string cidade;
  string uf;
};

// leitura dos clientes
void leitura(Cliente cli[], int &cont) {

  cont = 0;

  while (cont < 20) {

    cout << "\nCodigo do cliente (0 para sair): ";
    cin >> cli[cont].codigo;

    // encerra leitura
    if (cli[cont].codigo == 0) {
      break;
    }

    cin.ignore();

    cout << "Nome: ";
    getline(cin, cli[cont].nome);

    cout << "Endereco: ";
    getline(cin, cli[cont].endereco);

    cout << "Cidade: ";
    getline(cin, cli[cont].cidade);

    cout << "UF: ";
    getline(cin, cli[cont].uf);

    cont++;
  }
}

// junta os dois vetores em ordem
void inclusao(Cliente S[], int contS, Cliente T[], int contT, Cliente A[],
              int &contA) {

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

// mostra vetor final
void mostrar(Cliente A[], int contA) {

  cout << "\n\n=== CLIENTES ===\n";

  for (int i = 0; i < contA; i++) {

    cout << "\nCodigo: " << A[i].codigo << endl;
    cout << "Nome: " << A[i].nome << endl;
    cout << "Endereco: " << A[i].endereco << endl;
    cout << "Cidade: " << A[i].cidade << endl;
    cout << "UF: " << A[i].uf << endl;
  }
}

int main() {

  Cliente arqS[20];
  Cliente arqT[20];
  Cliente arqA[40];

  int contS, contT, contA;

  cout << "\n=== LEITURA DO ARQUIVO S ===\n";
  leitura(arqS, contS);

  cout << "\n=== LEITURA DO ARQUIVO T ===\n";
  leitura(arqT, contT);

  inclusao(arqS, contS, arqT, contT, arqA, contA);

  mostrar(arqA, contA);

  return 0;
}

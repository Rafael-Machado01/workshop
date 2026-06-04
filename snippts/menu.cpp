
char menu() {
  system("clear"); // Limpe a Tela
  cout << "\t\t Escola Ernani Rodrigues";
  cout << "\n\n\t\t Opções ";
  cout << "\n\n\t\t 1 - Cadastrar Dados.";
  cout << "\n\n\t\t 2 - Exibir Dados.";
  cout << "\n\n\t\t S - Sair";
  cout << "\n\n\t\t Escolha:";
  char op;            // Variável para armazenar a escolha.
  cin >> op;          // Para digitar.
  return toupper(op); // Sempre irá retornar um caractere maiusculo.
}

int main() {
  int sair = 0;
  while (sair == 0) {
    char op = menu();
    switch (op) {
    case '1': {
      read();
      break;
    }; // Chama a função read quando o um for digitado
    case '2': {
      view();
      break;
    } // Chama função view quando o dois for digitado
    case 'S': {
      sair = 1;
      system("clear");
      break;
    }
    default: {
      // Para opções invalidas
      cout << "\n\n\t\t Opção Invalida.";
      system("pause");
      break;
    }
    }
  }
}
// Opções principais:
// Registrar
// Imprimir
// Incluir
// Quests
#include <iostream>
using namespace std;

int main() {
  int opcaoPrincipal;
  int opcaoSubmenu;

  do {
    cout << "\n===== MENU PRINCIPAL =====\n";
    cout << "1 - Cadastro\n";
    cout << "2 - Relatorios\n";
    cout << "0 - Sair\n";
    cout << "Escolha uma opcao: ";
    cin >> opcaoPrincipal;

    switch (opcaoPrincipal) {
    case 1:
      do {
        cout << "\n--- SUBMENU CADASTRO ---\n";
        cout << "1 - Cadastrar Cliente\n";
        cout << "2 - Cadastrar Produto\n";
        cout << "0 - Voltar\n";
        cout << "Escolha uma opcao: ";
        cin >> opcaoSubmenu;

        switch (opcaoSubmenu) {
        case 1:
          cout << "Cliente cadastrado!\n";
          break;
        case 2:
          cout << "Produto cadastrado!\n";
          break;
        case 0:
          cout << "Voltando ao menu principal...\n";
          break;
        default:
          cout << "Opcao invalida!\n";
        }
      } while (opcaoSubmenu != 0);
      break;

    case 2:
      do {
        cout << "\n--- SUBMENU RELATORIOS ---\n";
        cout << "1 - Relatorio de Clientes\n";
        cout << "2 - Relatorio de Produtos\n";
        cout << "0 - Voltar\n";
        cout << "Escolha uma opcao: ";
        cin >> opcaoSubmenu;

        switch (opcaoSubmenu) {
        case 1:
          cout << "Exibindo relatorio de clientes...\n";
          break;
        case 2:
          cout << "Exibindo relatorio de produtos...\n";
          break;
        case 0:
          cout << "Voltando ao menu principal...\n";
          break;
        default:
          cout << "Opcao invalida!\n";
        }
      } while (opcaoSubmenu != 0);
      break;

    case 0:
      cout << "Encerrando programa...\n";
      break;

    default:
      cout << "Opcao invalida!\n";
    }

  } while (opcaoPrincipal != 0);

  return 0;
}

#include <iostream>
using namespace std;

#define T 5

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


void readCidade(Cidade c[]);
void readServico(Servico s[]);
void readPeca(Peca p[]);
void menu(Cidade c[],Servico s[],Peca p[]);

int main() {
    Cidade c[T] = {
        {1, "Assis", "SP"},
        {2, "Marilia", "SP"},
        {3, "Londrina", "PR"},
        {4, "Presidente Prudente", "SP"},
        {5, "Bauru", "SP"}
    };
    Servico s[T] = {
        {1, "Troca de Oleo", 80.00},
        {2, "Alinhamento", 120.00},
        {3, "Balanceamento", 90.00},
        {4, "Revisao Completa", 350.00},
        {5, "Troca de Pastilhas de Freio", 150.00}
    };
    Peca p[T] = {
        {1, 20, 5, 50, "Filtro de Oleo", 35.90},
        {2, 15, 3, 30, "Pastilha de Freio", 89.90},
        {3, 10, 2, 20, "Bateria 60Ah", 420.00},
        {4, 25, 5, 40, "Vela de Ignicao", 18.50},
        {5, 8, 2, 15, "Correia Dentada", 150.00}
    };
    Cliente cl[T] = {
        {1, 1, "Joao Silva", "18998112233", "Rua das Flores, 120"},
        {2, 2, "Maria Souza", "14999774455", "Av. Brasil, 450"},
        {3, 3, "Carlos Lima", "43988776655", "Rua Parana, 88"},
        {4, 4, "Ana Oliveira", "18999443322", "Rua Central, 210"},
        {5, 5, "Pedro Santos", "14998552211", "Av. Paulista, 75"}
    };
    menu(c,s,p);
}

void menu(Cidade c[],Servico s[], Peca p[]) {
    int opMain = -1;

    while (opMain != 0) {
        cout << "\n\n\t\tMenu Principal - Racing Fema" << endl;
        cout << "\n1 - Imprimir";
        cout << "\n2 - Incluir";
        cout << "\n3 - Funcoes";
        cout << "\n0 - Sair";
        cout << "\n\nEscolha uma opcao: ";
        cin >> opMain;

        switch (opMain) {
            case 1: {
                int opSecond = -1;

                while (opSecond != 0) {
                    cout << "\n\n\t\tMenu Imprimir - Racing Fema" << endl;
                    cout << "\n1 - Cidades";
                    cout << "\n2 - Servicos";
                    cout << "\n3 - Pecas";
                    cout << "\n0 - Voltar";
                    cout << "\n\nEscolha uma opcao: ";
                    cin >> opSecond;

                    switch (opSecond) {
                        case 1:
                            readCidade(c);
                            break;
                        case 2:
                            readServico(s);
                            break;
                        case 3:
                            readPeca(p);
                            break;
                        case 0:
                            cout << "\nVoltando..." << endl;
                            break;
                        default:
                            cout << "\nOpcao invalida!" << endl;
                    }
                }
                break;
            }

            case 2: {
                int opSecond = -1;

                while (opSecond != 0) {
                    cout << "\n\n\t\tMenu Incluir - Racing Fema" << endl;
                    cout << "\n1 - Cliente";
                    cout << "\n2 - Veiculo";
                    cout << "\n3 - Mecanico";
                    cout << "\n0 - Voltar";
                    cout << "\n\nEscolha uma opcao: ";
                    cin >> opSecond;

                    switch (opSecond) {
                        case 1:
                            cout << "Incluir Cliente\n";
                            break;
                        case 2:
                            cout << "Incluir Veiculo\n";
                            break;
                        case 3:
                            cout << "Incluir Mecanico\n";
                            break;
                        case 0:
                            cout << "Voltando...\n";
                            break;
                        default:
                            cout << "Opcao invalida!\n";
                    }
                }
                break;
            }

            case 3:
                cout << "\nMenu de funcoes\n";
                break;

            case 0:
                cout << "\nFechando programa...\n";
                break;

            default:
                cout << "\nOpcao invalida!\n";
        }
    }
}

void readCidade(Cidade c[]) {
    for (int i = 0; i < T; i++) {
        cout << "ID: " << c[i].id << endl;
        cout << "Nome: " << c[i].nome << endl;
        cout << "UF: " << c[i].uf << endl;
    }
}

void readServico(Servico s[]) {
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

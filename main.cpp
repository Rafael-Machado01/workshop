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


void readCidade(Cidade c[],int &sizeCliente);
void readServico(Servico s[]);
void readPeca(Peca p[]);
void readCliente(Cliente cl[], int &sizeCliente);
void searchCliente(Cliente cl[],int sizeCliente,bool &exist,int x);
void searchCidade(Cidade c[],int idCidade);
void mergeCliente(Cliente cl[],int &sizeCliente, Cliente clT[],int &cont,Cliente clA[]);
void newCliente(Cliente cl[],Cliente clT[], Cliente clA[],int &sizeCliente,Cidade c[]);
void menu(Cidade c[],Servico s[],Peca p[],Cliente cl[],int &sizeCliente,Cliente clT[],Cliente clA[]);

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
    Cliente cl[T*2] = {
        {1, 1, "Joao Silva", "18998112233", "Rua das Flores, 120"},
        {2, 2, "Maria Souza", "14999774455", "Av. Brasil, 450"},
        {3, 3, "Carlos Lima", "43988776655", "Rua Parana, 88"},
        {4, 4, "Ana Oliveira", "18999443322", "Rua Central, 210"},
        {5, 5, "Pedro Santos", "14998552211", "Av. Paulista, 75"}
    };
    Cliente clT[T*2],clA[T*2];
    int sizeCliente=T;
    menu(c,s,p,cl,sizeCliente,clT,clA);
}

void menu(Cidade c[],Servico s[],Peca p[],Cliente cl[],int &sizeCliente,Cliente clT[],Cliente clA[]) {
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
                    cout << "\n4 - Clientes";
                    cout << "\n0 - Voltar";
                    cout << "\n\nEscolha uma opcao: ";
                    cin >> opSecond;

                    switch (opSecond) {
                        case 1:
                            readCidade(c,sizeCliente);
                            break;
                        case 2:
                            readServico(s);
                            break;
                        case 3:
                            readPeca(p);
                            break;
                        case 4:
                            readCliente(cl,sizeCliente);
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
                            newCliente(cl, clT,  clA, sizeCliente, c);
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

void readCidade(Cidade c[],int &sizeCliente) {
    for (int i = 0; i < sizeCliente; i++) {
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

void readCliente(Cliente cl[], int &sizeCliente) {
    for (int i = 0; i < sizeCliente; i++) {
        cout << "ID: " << cl[i].id << endl;
        cout << "Nome: " << cl[i].nome << endl;
        cout << "Endereço: " << cl[i].endereco << endl;
        cout << "Telefone: " << cl[i].telefone << endl;
        cout << "ID Cidade: " << cl[i].idCidade<< endl;
    }
}

void newCliente(Cliente cl[],Cliente clT[], Cliente clA[],int &sizeCliente,Cidade c[]) {
    int x=-1,cont=0;
    while (sizeCliente < T*2) {
        bool exist=false;
        cout << "Digite o ID do Cliente: - Digite 0 para sair. " << endl;
        cin >> x;
        if (x == 0 ) {
            break;
        }
        searchCliente(cl,sizeCliente,exist,x);
        if (exist == true) {
            break;
        }
            clT[cont].id = x;
            cout << "Digite o Nome do Cliente: " << endl;
            cin.ignore();
            getline(cin, clT[cont].nome);
            cout << "Digite o Endereço do Cliente: " << endl;
            getline(cin,clT[cont].endereco);
            cout << "Digite o Telefone do Cliente: "<<endl;
            getline(cin,clT[cont].telefone);
            cout << "Digite o ID da Cidade: " << endl;
            cin >> clT[cont].idCidade;
            searchCidade(c,clT[cont].idCidade);
        cont++;
    }
    for (int i=0; i < cont; i++) {
        for (int j=i+1; j < cont; j++) {
            if (clT[i].id > clT[j].id) {
                Cliente aux[1];
                aux[0] = clT[i];
                clT[i] = clT[j];
                clT[j] = aux[0];
            }
        }
    }
    mergeCliente(cl,sizeCliente,clT,cont, clA);
}

void searchCliente(Cliente cl[],int sizeCliente,bool &exist, int x) {
    int init=0,end = sizeCliente,middle=0;
    while (init <= end) {
        middle = (init + end) / 2;
        if (cl[middle].id > x) {
            end = middle - 1;
        }else if (cl[middle].id < x) {
            init = middle + 1;
        }if (cl[middle].id == x) {
            cout << "Cliente já existente!" << endl;
            cout << "ID: " << cl[middle].id << " Nome: " << cl[middle].nome << endl;
            exist = true;
            break;
        }
    }
}

void searchCidade(Cidade c[],int idCidade) {
    int init=0,end = T,middle = 0;
    while (init <= end) {
        middle = (init + end) / 2;
        if (c[middle].id > idCidade) {
            end = middle - 1;
        }else if (c[middle].id < idCidade) {
            init = middle + 1;
        }if (c[middle].id == idCidade) {
            cout << "ID: " << c[middle].id << " Nome: " << c[middle].nome << " UF: " << c[middle].uf << endl;
            break;
        }

    }
}

void mergeCliente(Cliente cl[],int &sizeCliente, Cliente clT[],int &cont,Cliente clA[]) {
    int i=0,j=0,a=0;

    while (i < sizeCliente and j < cont) {
        if (cl[i].id < clT[j].id) {
            clA[a] = cl[i];
            i++;
        }else {
            clA[a] = clT[j];
            j++;
        }
        a++;
    }
    while (i < sizeCliente ) {
        clA[a] = cl[i];
        i++;
        a++;
    }
    while (j < cont) {
        clA[a] = clT[j];
        j++;
        a++;
    }
    sizeCliente = a;
    for (int i=0; i < sizeCliente; i++) {
        cl[i] = clA[i];
    }
}

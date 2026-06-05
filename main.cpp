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
struct Veiculo {
    int ano, idCliente;
    string placa, modelo, marca;
};
struct Mecanico {
    int id;
    string telefone, nome, especialidade;
};



void readCidade(Cidade c[]);
void readServico(Servico s[]);
void readPeca(Peca p[]);
void readCliente(Cliente cl[], int &sizeCliente);
void readVeiculo(Veiculo v[],int &sizeVeiculo);
void readMecanico(Mecanico m[],int &sizeMecanico);
void searchCliente(Cliente cl[],int sizeCliente,bool &exist,int x);
void searchCidade(Cidade c[],int idCidade);
void searchVeiculo(Veiculo v[], int &sizeVeiculo, string x,bool &exist);
void searchMecanico(Mecanico m[],int &sizeMecanico,bool &exist, int x);
void mergeCliente(Cliente cl[],int &sizeCliente, Cliente clT[],int &cont,Cliente clA[]);
void newCliente(Cliente cl[],Cliente clT[], Cliente clA[],int &sizeCliente,Cidade c[]);
void newVeiculo(Veiculo v[], int &sizeVeiculo,Cliente cl[], int &sizeCliente,Veiculo vT[],Veiculo vA[]);
void mergeVeiculo(Veiculo v[],int &sizeVeiculo, Veiculo vT[],int &cont,Veiculo vA[]);
void newMecanico(Mecanico m[],int &sizeMecanico,Mecanico mT[],Mecanico mA[]);
void mergeMecanico(Mecanico m[],int &sizeMecanico,Mecanico mT[],int &cont,Mecanico mA[]);

void menu(Cidade c[],Servico s[],Peca p[],Cliente cl[],int &sizeCliente,Cliente clT[],Cliente clA[],Veiculo v[],int &sizeVeiculo,Veiculo vT[],Veiculo vA[],Mecanico m[],int &sizeMecanico,Mecanico mT[],Mecanico mA[]);

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
    Veiculo v[T*2] = {
        {2018, 1, "ABC1D23", "Onix", "Chevrolet"},
        {2020, 2, "DEF4G56", "HB20", "Hyundai"},
        {2017, 3, "HIJ7K89", "Corolla", "Toyota"},
        {2022, 4, "LMN1O23", "T-Cross", "Volkswagen"},
        {2019, 5, "PQR4S56", "Ka", "Ford"}
    };
    Veiculo vT[T*2],vA[T*2];
    int sizeVeiculo=T;
    Mecanico m[T*2] = {
        {1, "18998123456", "Carlos Mendes", "Motor"},
        {2, "14999765432", "Fernanda Rocha", "Suspensao"},
        {3, "43998887766", "Juliano Martins", "Freios"},
        {4, "18999445566", "Patricia Lima", "Eletrica Automotiva"},
        {5, "14998553322", "Ricardo Nogueira", "Injecao Eletronica"}
    };
    Mecanico mT[T*2],mA[T*2];
    int sizeMecanico = T;
    menu(c,s,p,cl,sizeCliente,clT,clA,v,sizeVeiculo,vT,vA,m,sizeMecanico,mT,mA);
}

void menu(Cidade c[],Servico s[],Peca p[],Cliente cl[],int &sizeCliente,Cliente clT[],Cliente clA[],Veiculo v[],int &sizeVeiculo,Veiculo vT[],Veiculo vA[],Mecanico m[],int &sizeMecanico,Mecanico mT[],Mecanico mA[]) {
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
                    cout << "\n5 - Veiculos";
                    cout << "\n6 - Mecanicos";
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
                        case 4:
                            readCliente(cl,sizeCliente);
                            break;
                        case 5:
                            readVeiculo(v,sizeVeiculo);
                            break;
                        case 6:
                            readMecanico(m,sizeMecanico);
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
                            newVeiculo(v,sizeVeiculo,cl,sizeCliente,vT,vA);
                            break;
                        case 3:
                            newMecanico(m,sizeMecanico,mT,mA);
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

void readCliente(Cliente cl[], int &sizeCliente) {
    for (int i = 0; i < sizeCliente; i++) {
        cout << "ID: " << cl[i].id << endl;
        cout << "Nome: " << cl[i].nome << endl;
        cout << "Endereço: " << cl[i].endereco << endl;
        cout << "Telefone: " << cl[i].telefone << endl;
        cout << "ID Cidade: " << cl[i].idCidade<< endl;
    }
}

void readVeiculo(Veiculo v[],int &sizeVeiculo) {
    for (int i=0; i < sizeVeiculo; i++) {
        cout << "Placa: " << v[i].placa << endl;
        cout << "Modelo: " << v[i].modelo << endl;
        cout << "Marca: " << v[i].marca << endl;
        cout << "Ano: " << v[i].ano << endl;
        cout << "Cliente: " << v[i].idCliente << endl;
    }
}

void readMecanico(Mecanico m[], int &sizeVeiculo) {
    for (int i=0; i < sizeVeiculo; i++) {
        cout << "ID: " << m[i].id << endl;
        cout << "Nome: " << m[i].nome << endl;
        cout << "Telefone: " << m[i].telefone << endl;
        cout << "Especialidade: " << m[i].especialidade << endl;
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

void newVeiculo(Veiculo v[], int &sizeVeiculo,Cliente cl[], int &sizeCliente,Veiculo vT[],Veiculo vA[]) {
    string x="";
    int cont=0;
    while (cont < T*2) {
        bool exist=false;
        cout << "Digite a Placa do Veiculo: - 0 para sair " << endl;
        cin >> x;
        for (int i = 0; i < x.size(); i++) {
            x[i] = toupper(x[i]);
        }
        if (x == "") {
            cout << "Placa Inválida" << endl;
            break;
        }
        if (x == "0") {
            break;
        }
        searchVeiculo(v,sizeVeiculo, x,exist);
        if (exist == false) {
            vT[cont].placa = x;
            cout << "Digite o Modelo: " << endl;
            cin.ignore();
            getline(cin,vT[cont].modelo);
            cout << "Digite a Marca: " << endl;
            getline(cin,vT[cont].marca);
            cout << "Digite o Ano: " << endl;
            cin >> vT[cont].ano;
            cout << "Digite o ID do Cliente: " << endl;
            cin >> vT[cont].idCliente;
            searchCliente(cl,sizeCliente,exist,vT[cont].idCliente);
        }
        cont++;
    }
    for (int i=0; i < cont; i++) {
        for (int j=i+1; j < cont; j++) {
            if (vT[i].placa > vT[j].placa) {
                Veiculo aux[1];
                aux[0] = vT[i];
                vT[i] =  vT[j];
                vT[j] = aux[0];
            }
        }
    }
    mergeVeiculo(v,sizeVeiculo,vT,cont,vA);
}

void newMecanico(Mecanico m[],int &sizeMecanico,Mecanico mT[],Mecanico mA[]) {
    int x=0,cont=0;
    while (cont < sizeMecanico) {
        bool exist = false;
        cout << "Digite o ID do Mecanico: - 0 para sair." << endl;
        cin >> x;
        if (x == 0) {
            break;
        }
        searchMecanico(m,sizeMecanico,exist,x);
        if (exist == false) {
            mT[cont].id = x;
            cout << "Digite o Nome do Mecanico: " << endl;
            cin.ignore();
            getline(cin,mT[cont].nome);
            cout << "Digite o Telefone do Mecanico: " << endl;
            getline(cin, mT[cont].telefone);
            cout << "Digite a Especialidade do Mecanico: " << endl;
            getline(cin, mT[cont].especialidade);
        }
        cont++;
    }
    for (int i=0; i < cont; i++) {
        for (int j=i+1; j < cont; j++) {
            if (mT[i].id > mT[j].id) {
                Mecanico aux[1];
                aux[0] = mT[i];
                mT[i] =  mT[j];
                mT[j] = aux[0];
            }
        }
    }
    mergeMecanico(m,sizeMecanico,mT,cont,mA);
}


void searchCliente(Cliente cl[],int sizeCliente,bool &exist, int x) {
    int init=0,end = sizeCliente-1,middle=0;
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
    int init=0,end = T-1,middle = 0;
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

void searchVeiculo(Veiculo v[], int &sizeVeiculo, string x,bool &exist) {
    int init=0,end = sizeVeiculo-1,middle = 0;
    while (init <= end) {
        middle = (init + end) / 2;
        if (v[middle].placa > x) {
            end = middle - 1;
        }else if (v[middle].placa < x) {
            init = middle + 1;
        }if (v[middle].placa == x) {
            cout << "Placa já Cadrastrada" << endl;
            exist = true;
            break;

        }
    }
}

void searchMecanico(Mecanico m[],int &sizeMecanico,bool &exist, int x) {
    int init=0,end = sizeMecanico-1,middle = 0;
    while (init <= end) {
        middle = (init + end) / 2;
        if (m[middle].id > x) {
            end = middle - 1;
        }
        else if (m[middle].id < x) {
            init = middle + 1;
        }
        if (m[middle].id == x) {
            cout << "Mecanico encontrado!" << endl;
            cout << "ID: " << m[middle].id << " Nome: " << m[middle].nome << endl;
            exist = true;
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

void mergeVeiculo(Veiculo v[],int &sizeVeiculo, Veiculo vT[],int &cont,Veiculo vA[]) {
    int i=0,j=0,a=0;

    while (i < sizeVeiculo and j < cont) {
        if (v[i].placa < vT[j].placa) {
            vA[a] = v[i];
            i++;
        }else {
            vA[a] = vT[j];
            j++;
        }
        a++;
    }
    while (i < sizeVeiculo ) {
        vA[a] = v[i];
        i++;
        a++;
    }
    while (j < cont) {
        vA[a] = vT[j];
        j++;
        a++;
    }
    sizeVeiculo = a;
    for (int i=0; i < sizeVeiculo; i++) {
        v[i] = vA[i];
    }
}

void mergeMecanico(Mecanico v[],int &sizeMecanico, Mecanico mT[],int &cont,Mecanico mA[]) {
    int i=0,j=0,a=0;

    while (i < sizeMecanico and j < cont) {
        if (v[i].id < mT[j].id) {
            mA[a] = v[i];
            i++;
        }else {
            mA[a] = mT[j];
            j++;
        }
        a++;
    }
    while (i < sizeMecanico ) {
        mA[a] = v[i];
        i++;
        a++;
    }
    while (j < cont) {
        mA[a] = mT[j];
        j++;
        a++;
    }
    sizeMecanico = a;
    for (int i=0; i < sizeMecanico; i++) {
        v[i] = mA[i];
    }
}


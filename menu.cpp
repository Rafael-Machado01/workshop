void menu() {
    int opMain,opSecond;
    do {
        cout << "\n\n\t\t Menu Principal - Racing Fema" << endl;
        cout << "\n\n 1 - Imprimir " << endl;
        cout << "\n\n 2 - Incluir" << endl;
        cout << "\n\n 3 - Funções " << endl;
        cout << "\n\n 0 - Sair" << endl;
        cout << "\n\n Escolha uma opção:";
        cin << opMain;
        switch(opMain) {
            case 1: {
                cout << "\n\n\t\t Menu Imprimir - Racing Fema" << endl;
                cout << "\n\n 1 - Cidades" << endl;
                cout << "\n\n 2 - Serviços" << endl;
                cout << "\n\n 3 - Peça" << endl;
                cout << "\n\n 0 - Voltar " << endl;
                cout << "Escolha uma opção: ";
                cin >> opSecond;

                switch(opSecond) {
                    case 1:
                        readCidade();
                        break;
                    case 2:
                        readServico();
                        break;
                    case 3:
                        readPeca();
                        break;
                    case 0:
                        cout << "Voltando ao Menu Principal" << endl;
                    default:
                        cout << "Opção Inválida!" << endl;
                }
            }
                while(opSecond != 0);
                break;

            case 2:
                do {
                    cout << "\n\n\t\t Menu Incluir - Racing Fema" << endl;
                    cout << "1 - Incluir Clientes" << endl;
                    cout << "2 - Incluir Veiculos" << endl;
                    cout << "3 - Incluir Mecanicos" << endl;
                    cout << "0  - Voltar" << endl;
                    cout << "Escolha uma opção : ";
                    cin >> opSecond;

                    switch (opSecond) {
                        case 1:
                            cout << "include";
                        case 0:
                            cout << "Voltando ao Menu Principal" << endl;
                        default:
                            cout << "Opção Inválida!" << endl;
                    }
                }
        }while (opSecond != 0);
        break;
        case 0:
            cout << "Fechando programa.."<< endl;
        default:
            cout << "Opção Inválida!" << endl;
    } while (opMain != 0);
    break;
}
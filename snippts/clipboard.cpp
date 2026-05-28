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

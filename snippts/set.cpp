
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

// Inclusão de novos clientes na tabela
void setCliente(Cliente cl[], Cidade c[], int &cont) {
  cont = 0;

  while (cont < T) {
    cout << "Digite o ID do Cliente (0 para sair): " << endl;
    cin >> cl[cont].id;
    int exist = 0;
    searchCliente(cl, exist, cl[cont].id);
    if (exist == 1) {
      break;
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
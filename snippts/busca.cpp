void search(Cliente v[], int x) {
  int inicio = 0, fim = T - 1, meio = 0;
  for (int i = 0; i < T; i++) {
    meio = (inicio + fim) / 2;
    if (v[meio].id > x) {
      fim = meio - 1;
    } else if (v[meio].id < x) {
      inicio = meio + 1;
    }
    if (v[meio].id == x) {
      cout << "Encontrado!" << endl;
      cout << "ID:" << v[meio].id << " Nome: " << v[meio].nome
           << " Endereço: " << v[meio].endereco << " Cidade: " << v[meio].cidade
           << " UF: " << v[meio].uf << endl;
      break;
    }
  }
}

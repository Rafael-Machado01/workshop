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

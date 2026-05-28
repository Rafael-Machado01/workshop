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
    }
  }
}

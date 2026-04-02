void selection_sort(int vetor[], int n) {
  for(int i = 0; i < n - 1; i++) {
    int posicao = i;

    for(int j = i + 1; j < n; j++) {
      if(vetor[posicao] > vetor[j]) {
        posicao = j;
      }
    }

    int aux = vetor[i];
    vetor[i] = vetor[posicao];
    vetor[posicao] = aux;
  }
}
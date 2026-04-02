void insertion_sort(int vetor[], int n) {
  for(int i = 1; i < n; i++) {
    for(int k = i - 1; k >= 0 && vetor[k] > vetor[k+1]; k--) {
      int aux = vetor[k];
      vetor[k] = vetor[k+1];
      vetor[k+1] = aux;
    }
  }
}
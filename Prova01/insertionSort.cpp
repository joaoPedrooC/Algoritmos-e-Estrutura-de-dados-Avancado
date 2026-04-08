void insertion_sort(int vetor[], int n, void (*imprime_lista_fn)(int*, int), bool allowPrints) {
  for(int i = 1; i < n; i++) {
    for(int k = i - 1; k >= 0 && vetor[k] > vetor[k+1]; k--) {
      int aux = vetor[k];
      vetor[k] = vetor[k+1];
      vetor[k+1] = aux;

      if(allowPrints) {
        cout << "\nInteracao [" << i << "] | Passo [" << k << "].\nImprimindo vetor:" << endl;
        imprime_lista_fn(vetor, n);
      }
    }
  }
}
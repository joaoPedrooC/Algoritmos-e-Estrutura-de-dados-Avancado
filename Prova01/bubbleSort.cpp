#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int vetor[], int n, void (*imprime_lista_fn)(int*, int), bool allowPrints) {
  int aux;

  for(int i = 0; i < n; i++) {
  bool ordenado = true;
  
    for(int j = 0; j < n - 1; j++) {

      if(vetor[j] > vetor[j + 1]) {
        aux = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = aux;

        ordenado = false;
      }

      if(allowPrints) {
        cout << "Iteracao [" << i + 1 << "] | passo [" << j + 1 << "]: acompanhamento da ordenacao do vetor." << endl;
        imprime_lista_fn(vetor, n);
      }
    }

    if(ordenado) break;
  }
}
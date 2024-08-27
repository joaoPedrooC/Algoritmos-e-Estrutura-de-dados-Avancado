#include <bits/stdc++.h>
using namespace std;

#define TAMANHO 1000

void bubble_sort(int vetor[], int n) {
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

    }

    if(ordenado) break;
  }
}

void imprime_vetor(int vetor[], int n) {
  for(int i = 0; i < n; i++) {
    cout << vetor[i] << " -> ";
  }

  cout << endl;
}

int main() {
  int vetor[TAMANHO];

  for(int i = 0; i < TAMANHO; i++) {
    vetor[i] = rand();
  }

  cout << "Vetor antes da ordenacaoo ->" << endl;
  imprime_vetor(vetor, TAMANHO);

  // Início da contagem de clocks ->
  clock_t inicio = clock();

  bubble_sort(vetor, TAMANHO);

  // Fim da contagem de clocks ->
  clock_t fim = clock();

  float tempoGasto = (double)( fim - inicio ) / CLOCKS_PER_SEC;

  cout << "\n\n\n\nVetor apos ordenacao -> " << endl;
  imprime_vetor(vetor, TAMANHO);
  
  cout << "Tempo gasto -> " << tempoGasto << " segundos." << endl;
}
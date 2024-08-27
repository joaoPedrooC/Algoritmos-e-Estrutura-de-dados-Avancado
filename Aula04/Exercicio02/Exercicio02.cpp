#include <bits/stdc++.h>
using namespace std;

#define TAMANHO 1000

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

void imprime_lista(int vetor[], int n) {
  for(int i = 0; i < n; i++) {
    cout << vetor[i] << " ";
  }

  cout << endl << endl;
}

int main() {
  int vetor[TAMANHO];

  for(int i = 0; i < TAMANHO; i++) {
    vetor[i] = rand();
  }

  cout << "Antes da ordenacao:\n";
  imprime_lista(vetor, TAMANHO);

  clock_t inicio = clock();

  selection_sort(vetor, TAMANHO);

  clock_t fim = clock();

  cout << "Apos ordenacao:\n";
  imprime_lista(vetor, TAMANHO);

  float tempoGasto = (double)( fim - inicio ) / CLOCKS_PER_SEC;
  cout << setprecision(5) << fixed;
  cout << "\nTempo gasto: " << tempoGasto << " segundos." << endl;

  return 0;
}
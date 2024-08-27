#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int vetor[], int n) {
  for(int i = 1; i < n; i++) {
    for(int k = i - 1; k >= 0 && vetor[k] > vetor[k+1]; k--) {

      int aux = vetor[k];
      vetor[k] = vetor[k+1];
      vetor[k+1] = aux;

    }
  }
}

void imprime_lista(int vetor[], int n) {
  for(int i = 0; i < n; i++) {
    cout << vetor[i] << " ";
  }

  cout << endl << endl;
}

int main() {
  int tamanho;

  cout << "Informe a quantidade de elementos a serem inseridos: ";
  cin >> tamanho;

  int vetor[tamanho];

  for(int i = 0; i < tamanho; i++) {
    int val;
    cin >> val;

    vetor[i] = val;
  }

  cout << "Antes da ordenacao:\n";
  imprime_lista(vetor, tamanho);

  clock_t inicio = clock();

  insertion_sort(vetor, tamanho);

  clock_t fim = clock();

  cout << "Apos ordenacao:\n";
  imprime_lista(vetor, tamanho);

  float tempoGasto = (double)( fim - inicio ) / CLOCKS_PER_SEC;
  cout << setprecision(5) << fixed;
  cout << "\nTempo gasto: " << tempoGasto << " segundos." << endl;

  return 0;
}
#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int vetor[], int n) { // n é o tamanho do vetor
  int aux;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n - 1; j++) {

      if(vetor[j] > vetor[j + 1]) {
        aux = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = aux;
      }

    }
  }
}

int main() {
  int num[10];

  // Inicializando os valores
  for(int i = 0; i < 10; i++) {
    num[i] = rand();
  }

  cout << "Vetor original ->" << endl;
  for(int i = 0; i < 10; i++) {
    cout << num[i] << " -> ";
  }

  // Iniciando Bubble Sort ->
  clock_t antes = clock(); // Armazena a quantidade de clocks desde que o programa foi executado até o momento

  bubble_sort(num, 10);
  
  cout << "\nVetor ordenado ->" << endl;
  for(int i = 0; i < 10; i++) {
    cout << num[i] << " -> ";
  }

  clock_t depois = clock();

  float tempoGasto = (double)( depois - antes ) / CLOCKS_PER_SEC;

  cout << "\n\nTempo gasto no bubble sort: " << tempoGasto << " segundos."; // Aprox 0.001 ~ 0.002s para o vetor com 10 números aleatórios

  return 0;
}
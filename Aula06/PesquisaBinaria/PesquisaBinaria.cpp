#include <bits/stdc++.h>
using namespace std;

// Com recursividade
// int pesquisaBinaria(int vet[], int inicio, int fim, int chave) {
//   int meio = (inicio + fim) / 2;

//   if(vet[meio] == chave) return meio;
//   else if(inicio > fim) return -1;

//   if(vet[meio] < chave) return pesquisaBinaria(vet, meio + 1, fim, chave);

//   return pesquisaBinaria(vet, inicio, meio - 1, chave);
// }

int pesquisaBinaria(int vet[], int n, int chave) {
  int inicio = 0;
  int meio;
  int fim = n - 1;

  while(inicio <= fim) {
    meio = (inicio + fim) / 2;

    if(chave < vet[meio]) fim = meio - 1;
    else if(chave > vet[meio]) inicio = meio + 1;
    else return meio;
  }

  return -1;
}

int main() {
  int vet[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  clock_t inicio = clock();

  int indice = pesquisaBinaria(vet, sizeof(vet), 25);

  clock_t fim = clock();

  float tempoGasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
  cout << "tempo: " << tempoGasto << endl;
  cout << indice << endl;
}
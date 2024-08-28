#include <bits/stdc++.h>
#include "../PesquisaBinaria/PesquisaBinaria.cpp"
#include "../PesquisaInterpolacao/PesquisaInterpolacao.cpp"
#include "../PesquisaSequencial/PesquisaSequencial.cpp"
#include "../../MetodosOrdenacao/MergeSort/MergeSort.cpp"
using namespace std;

#define TAMANHO 1000

int main() {
  int vet[TAMANHO];

  for(int i = 0; i < TAMANHO; i++) {
    vet[i] = rand();
  }

  clock_t inicio = clock();

  merge_sort(vet, TAMANHO);

  clock_t meio = clock();
  int num;
  
  cout << "Digite um numero para buscar no vetor: ";
  cin >> num;

  cout << "O tempo de execução ate agora foi: " << (float)(meio - inicio) / CLOCKS_PER_SEC << endl;

  int indiceBin = pesquisaBinaria(vet, TAMANHO, num);
  int indiceInterp = pesquisaInterpolacao(num, vet, TAMANHO);
  int indiceSequenc = pesquisaSequencial(num, vet, TAMANHO);

  clock_t fim = clock();

  cout << "Busca Binaria: " << indiceBin << "\nBusca Interp.: " << indiceInterp << "\nBusca Sequencial: " << indiceSequenc << endl;

  cout << "Tempo total de execucao: " << (float)(fim - inicio) / CLOCKS_PER_SEC << "\nNumero encontrado: " << vet[indiceBin] << endl;
  return 0;
}
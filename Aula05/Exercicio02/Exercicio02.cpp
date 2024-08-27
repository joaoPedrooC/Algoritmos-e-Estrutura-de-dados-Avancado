#include <bits/stdc++.h>
using namespace std;

#define TAMANHO 1000

void merge_vetor(int vetor[], int copia_vetor[], int posicao_inicial, int posicao_meio, int posicao_final) {
  int copia_posicaoInicial = posicao_inicial;
  int copia_posicaoMeio = posicao_meio + 1;
  int percorreVetor = posicao_inicial;

  for(percorreVetor; percorreVetor <= posicao_final; percorreVetor++) {
    copia_vetor[percorreVetor] = vetor[percorreVetor];
  }

  percorreVetor = posicao_inicial;

  while(copia_posicaoInicial <= posicao_meio && copia_posicaoMeio <= posicao_final) {
    if(copia_vetor[copia_posicaoInicial] <= vetor[copia_posicaoMeio]) {
      vetor[percorreVetor++] = copia_vetor[copia_posicaoInicial++];
    } else {
      vetor[percorreVetor++] = copia_vetor[copia_posicaoMeio++];
    }
  }

  while(copia_posicaoInicial <= posicao_meio) {
    vetor[percorreVetor++] = copia_vetor[copia_posicaoInicial++];
  }

  while(copia_posicaoMeio <= posicao_final) {
    vetor[percorreVetor++] = copia_vetor[copia_posicaoMeio++];
  }
}

void sort_vetor(int vetor[], int copia_vetor[], int posicao_inicial, int posicao_final) {
  if(posicao_inicial >= posicao_final) return;

  int posicao_meio = (posicao_inicial + posicao_final) / 2;

  sort_vetor(vetor, copia_vetor, posicao_inicial, posicao_meio);
  sort_vetor(vetor, copia_vetor, posicao_meio + 1, posicao_final);

  if(vetor[posicao_meio] <= vetor[posicao_meio + 1]) return;

  merge_vetor(vetor, copia_vetor, posicao_inicial, posicao_meio, posicao_final);
}

void merge_sort(int vetor[], int n) {
  int* copia_vetor = (int*)malloc(sizeof(int) * n);

  sort_vetor(vetor, copia_vetor, 0, n - 1);

  free(copia_vetor);
}

void imprimir_vetor(int vetor[], int tamanho) {
  for(int i = 0; i < tamanho; i++) {
    cout << vetor[i] << " ";
  }

  cout << endl << endl;
}

int main() {
  int vetor[TAMANHO];

  for(int i = 0; i < TAMANHO; i++) {
    vetor[i] = rand();
  }

  cout << "Antes da ordenacao:" << endl;
  imprimir_vetor(vetor, TAMANHO);

  // Inicio da contagem de tempo
  clock_t inicio = clock();

  merge_sort(vetor, TAMANHO);

  clock_t fim = clock();

  cout << "Apos a ordenacao:" << endl;
  imprimir_vetor(vetor, TAMANHO);

  float tempoExecucao = (float)(fim - inicio) / CLOCKS_PER_SEC;
  cout << setprecision(5) << fixed;
  cout << "Tempo de execucao: " << tempoExecucao << " segundos." << endl;

  return 0;
}
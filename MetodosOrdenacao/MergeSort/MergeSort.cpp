#include <bits/stdc++.h>
using namespace std;

void merge_array(int vetor[], int vetor_temporario[], int indice_inicial, int indice_meio, int indice_final) {
  int copia_indiceInicial = indice_inicial;
  int copia_indiceMeio = indice_meio + 1;

  int indice_percorreVetor;

  for(indice_percorreVetor = indice_inicial; indice_percorreVetor <= indice_final; indice_percorreVetor++) {
    vetor_temporario[indice_percorreVetor] = vetor[indice_percorreVetor];
  }


  indice_percorreVetor = indice_inicial;
  
  while(copia_indiceInicial <= indice_meio && copia_indiceMeio <= indice_final) {
    if(vetor_temporario[copia_indiceInicial] <= vetor[copia_indiceMeio]) {
      vetor[indice_percorreVetor++] = vetor_temporario[copia_indiceInicial++];
    } else {
      vetor[indice_percorreVetor++] = vetor_temporario[copia_indiceMeio++];
    }
  }

  while(copia_indiceInicial <= indice_meio) {
    vetor[indice_percorreVetor++] = vetor_temporario[copia_indiceInicial++];
  }

  while(copia_indiceMeio <= indice_final) {
    vetor[indice_percorreVetor++] = vetor_temporario[copia_indiceMeio++];
  }
}

void sort_array(int vetor[], int vetor_temporario[], int indice_inicial, int indice_final) {
  if(indice_inicial >= indice_final) return;

  int indice_meio = ( indice_inicial + indice_final ) / 2;

  sort_array(vetor, vetor_temporario, indice_inicial, indice_meio);
  sort_array(vetor, vetor_temporario, indice_meio + 1, indice_final);

  if(vetor[indice_meio] <= vetor[indice_meio + 1]) return;

  merge_array(vetor, vetor_temporario, indice_inicial, indice_meio, indice_final);
}

void merge_sort(int vetor[], int n) {
  int* vetor_temporario = (int*)malloc(sizeof(int) * n);

  sort_array(vetor, vetor_temporario, 0, n - 1);

  free(vetor_temporario);
}

void imprimir_vetor(int vetor[], int tamanho) {
  for(int i = 0; i < tamanho; i++) {
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

  cout << "Antes da ordenacao:" << endl;
  imprimir_vetor(vetor, tamanho);

  // Inicio da contagem de tempo
  clock_t inicio = clock();

  merge_sort(vetor, tamanho);

  clock_t fim = clock();

  cout << "Apos a ordenacao:" << endl;
  imprimir_vetor(vetor, tamanho);

  float tempoExecucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
  cout << setprecision(5) << fixed;
  cout << "Tempo de execucao: " << tempoExecucao << " segundos." << endl;
}
#include <bits/stdc++.h>
using namespace std;

void merge_vetor(int* vetor, int* copia_vetor, int posicao_inicial, int posicao_meio, int posicao_final) {
  int percorre_vetor = posicao_inicial;
  int copia_posicaoInicial = posicao_inicial;
  int copia_posicaoMeio = posicao_meio + 1;

  for(percorre_vetor; percorre_vetor <= posicao_final; percorre_vetor++) {
    copia_vetor[percorre_vetor] = vetor[percorre_vetor];
  }

  percorre_vetor = posicao_inicial;

  while((copia_posicaoInicial <= posicao_meio) && (copia_posicaoMeio <= posicao_final)) {
    if(copia_vetor[copia_posicaoInicial] <= vetor[copia_posicaoMeio]) {
      vetor[percorre_vetor++] = copia_vetor[copia_posicaoInicial++];
    } else {
      vetor[percorre_vetor++] = copia_vetor[copia_posicaoMeio++];
    }
  }

  while (copia_posicaoInicial <= posicao_meio) {
    vetor[percorre_vetor++] = copia_vetor[copia_posicaoInicial++];
  }

  while(copia_posicaoMeio <= posicao_final) {
    vetor[percorre_vetor++] = copia_vetor[copia_posicaoMeio++];
  }
}

void sort_vetor(int* vetor, int* copia_vetor, int posicao_inicial, int posicao_final) {
  if(posicao_inicial >= posicao_final) return;

  int posicao_meio = (posicao_inicial + posicao_final) / 2;

  sort_vetor(vetor, copia_vetor, posicao_inicial, posicao_meio);
  sort_vetor(vetor, copia_vetor, posicao_meio + 1, posicao_final);

  if(vetor[posicao_meio] <= vetor[posicao_meio + 1]) return;

  merge_vetor(vetor, copia_vetor, posicao_inicial, posicao_meio, posicao_final);
}

void merge_sort(int vetor[], int tamanho) {
  int* copia_vetor = (int*)malloc(sizeof(int) * tamanho);

  sort_vetor(vetor, copia_vetor, 0, tamanho - 1);

  free(copia_vetor);
}

void imprimir_vetor(int vetor[], int tamanho) {
  for(int i = 0; i < tamanho; i++) {
    cout << vetor[i] << " ";
  }

  cout << endl << endl;
}

int main() {
  int tamanho;

  cout << "Digite o tamanho do array: ";
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

  float tempoExecucao = (float)(fim - inicio) / CLOCKS_PER_SEC;
  cout << setprecision(5) << fixed;
  cout << "Tempo de execucao: " << tempoExecucao << " segundos." << endl;
}
#include <bits/stdc++.h>
using namespace std;

int TAMANHO_VETOR_MERGE = -1;

void merge_vetor(int* vetor, int* copia_vetor, int posicao_inicial, int posicao_meio, int posicao_final, void (*imprime_lista_fn)(int*, int), bool allowPrints) {
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

    if(allowPrints) {
      imprime_lista_fn(vetor, TAMANHO_VETOR_MERGE);
    }
  }

  while (copia_posicaoInicial <= posicao_meio) {
    vetor[percorre_vetor++] = copia_vetor[copia_posicaoInicial++];

    if(allowPrints) {
      imprime_lista_fn(vetor, TAMANHO_VETOR_MERGE);
    }
  }

  while(copia_posicaoMeio <= posicao_final) {
    vetor[percorre_vetor++] = copia_vetor[copia_posicaoMeio++];

    if(allowPrints) {
      imprime_lista_fn(vetor, TAMANHO_VETOR_MERGE);
    }
  }
}

void sort_vetor(int* vetor, int* copia_vetor, int posicao_inicial, int posicao_final, void (*imprime_lista_fn)(int*, int), bool allowPrints) {
  if(posicao_inicial >= posicao_final) return;
  // p_i = 0 ; p_f = 1
  int posicao_meio = (posicao_inicial + posicao_final) / 2;
  // p_m == 0 + 1 / 2 = 0.5 (int) -> 0

  sort_vetor(vetor, copia_vetor, posicao_inicial, posicao_meio, imprime_lista_fn, allowPrints); // 0, 0
  sort_vetor(vetor, copia_vetor, posicao_meio + 1, posicao_final, imprime_lista_fn, allowPrints); // 0 + 1 = 1, 1

  if(vetor[posicao_meio] <= vetor[posicao_meio + 1]) return;

  merge_vetor(vetor, copia_vetor, posicao_inicial, posicao_meio, posicao_final, imprime_lista_fn, allowPrints);
}

void merge_sort(int vetor[], int tamanho, void (*imprime_lista_fn)(int*, int), bool allowPrints) {
  int* copia_vetor = (int*)malloc(sizeof(int) * tamanho);

  TAMANHO_VETOR_MERGE = tamanho;
  sort_vetor(vetor, copia_vetor, 0, tamanho - 1, imprime_lista_fn, allowPrints);

  free(copia_vetor);
}

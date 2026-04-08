#include <bits/stdc++.h>
using namespace std;

int TAMANHO_VETOR = -1;

void quick_sort(int vetor[], int start, int end, void imprime_lista(int*, int), bool allowPrints) {
    if (start >= end) return;
    
    int start_cpy = start;
    int pivot = vetor[end - 1];

    for(int i = start; i < end - 1; i++) {
        if (vetor[i] < pivot) {
            int temp = vetor[i];
            vetor[i] = vetor[start_cpy];
            vetor[start_cpy] = temp;

            start_cpy++;
        }
    }

    vetor[end - 1] = vetor[start_cpy];
    vetor[start_cpy] = pivot;

    if (TAMANHO_VETOR == -1) TAMANHO_VETOR = end;

    if(allowPrints) {
        cout << "[+1 STEP] | PIVOT: " << pivot << " | Ordenacao vetor QUICK SORT:" << endl;
        imprime_lista(vetor, TAMANHO_VETOR);
    }

    quick_sort(vetor, start, start_cpy, imprime_lista, allowPrints);
    quick_sort(vetor, start_cpy + 1, end, imprime_lista, allowPrints);
}

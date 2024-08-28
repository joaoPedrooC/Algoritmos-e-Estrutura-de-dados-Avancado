#include <bits/stdc++.h>
using namespace std;

int pesquisaSequencial(int chave, int v[], int n) {
  for(int i = 0; i < n; i++) { // Busca índice por índice, sequencialmente
    if(v[i] == chave) return i;
  }

  return -1;
}

int main() {
  int vet[] = { 'a', 'b', 'c', 'd', 'e', 'z', 'f', 'l', 'k'};

  int indice = pesquisaSequencial('d', vet, sizeof(vet));

  cout << indice << endl;
}